#include"windows.cpp"
#include"colors.cpp"
#include<queue>
#include "cStructs.h"
extern Texture2D frames[2];
extern int currentFrame;



Vector2 generateRandomPOS() {
    Vector2 r = {
        (float)GetRandomValue(10, 200),
        (float)GetRandomValue(10, 200)
    };
    return r;
}

monster generateNewMonster() {
    monster m;
    Vector2 pos = generateRandomPOS(); // returns Vector2
    m.position.x = pos.x;
    m.position.y = pos.y;
    return m;
}

void updateMonsterPOS(monster &m, Vector2 playerPos) {
    Vector2 dir = { playerPos.x - m.position.x, playerPos.y - m.position.y };
    float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (len > 0.01f) {
        dir.x /= len;
        dir.y /= len;
        m.position.x += dir.x * DEFAULTMONSTERSPEED;
        m.position.y += dir.y * DEFAULTMONSTERSPEED;
    }
}

room generateNewRoom() {
    room r;
    r.init = true;
    r.roomID = nextRoomId++;
    r.isPlayerIn = false;
    r.hasPlayerVisted = false;

    r.toLeft = -1;
    r.toRight = -1;
    r.toUP = -1;
    r.toDown = -1;


    // Generate monsters — you can scale by difficulty or room ID
    int monsterCount = GetRandomValue(0, currentDif++);
    for (int i = 0; i < monsterCount; i++) {
        r.monsterNumber.push_back(generateNewMonster());
    }

    return r;
}



void populateRoomWithMonsters(std::vector<monster> &mons, int count) {
    for (int i = 0; i < count; i++) {
        mons.push_back(generateNewMonster());
    }
}

void genFirstRoom(){
    room firstRoom = generateNewRoom();
    firstRoom.isPlayerIn = true;
    roomVec.push_back(firstRoom);
}

void gameRunning(){
     Texture2D FloorTiles = LoadTexture("floor.png");
    DrawTexture(FloorTiles, 0, 0, WHITE);
    updatePlayerPOS(theUser);
    drawMonsters(roomVec, theUser);
    DrawTexture(frames[currentFrame], theUser.x, theUser.y, WHITE);
}

void drawMenu(){
    //DrawText("Press [F] to toggle fullscreen", 40, 40, 20, RAYWHITE);
    //DrawText("Press [ESC] to quit", 70, 70, 20, RAYWHITE);
    DrawRectangle(740, 300, 430, 65, GRAY);
    DrawText("MAIN MENU", 750, 300, 70, WHITE);
    DrawText("PRESS [ENTER] TO START", 815, 380, 20, WHITE);
    DrawText("PRESS [ESC] TO QUIT", 845, 425, 20, WHITE);
}


void HANDLESTATE(){
        switch (state) {
            case MAIN_MENU:
                drawMenu();
                if(IsKeyPressed(KEY_ENTER)){
                    state = GAME;
                }
                break;

            case GAME:
                gameRunning();
                break;

            case GAME_END:
                DrawText("GAME OVER", 180, 200, 30, RED);
                break;
        }
}

