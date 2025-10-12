#include"windows.cpp"
#include"colors.cpp"
#include<queue>
extern Texture2D frames[2];
extern int currentFrame;


enum Gamestate{
    MAIN_MENU,
    GAME,
    GAME_END,
    
};

Gamestate state = MAIN_MENU;


vectorGrid generateRandomPOS(){
    float rand = (float)GetRandomValue(10, 200);
    float rand2 = (float)GetRandomValue(10, 200);
    vectorGrid r;
    r.x = rand;
    r.y = rand2;
    return r;
}

monster generateNewMonster(){
    monster r;
    r.health = currentDif;
    r.position = generateRandomPOS();
    return r;
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
    updatePlayerPOS(theUser);
    drawMonsters();
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

