/*
This file feeds together lower level functions from prim, windows, and roomGen to 
prepare to lead them into main().


*/
#include"windows.cpp"
#include<queue>
#include"cStructs.h"
#include<cstdlib> 
#include<ctime> 
#include"roomGen.cpp"



Vector2 generateRandomPOS(int screenWidth, int screenHeight) {
    Vector2 r = { 0 };
    int side = GetRandomValue(0, 3); // 0=top, 1=bottom, 2=left, 3=right

    switch (side) {
        case 0: // top
            r.x = (float)GetRandomValue(0, screenWidth);
            r.y = -50.0f; // just above the screen
            break;
        case 1: // bottom
            r.x = (float)GetRandomValue(0, screenWidth);
            r.y = (float)screenHeight + 50.0f; // just below
            break;
        case 2: // left
            r.x = -50.0f;
            r.y = (float)GetRandomValue(0, screenHeight);
            break;
        case 3: // right
            r.x = (float)screenWidth + 50.0f;
            r.y = (float)GetRandomValue(0, screenHeight);
            break;
    }

    return r;
}


/*
updates monsters location based on player. Should be fixed soon to guide to middle of player sprite, 
not top left edge.

*/
void updateMonsterPOS(monster &m, Vector2 playerPos) {
    Vector2 dir = { playerPos.x - m.position.x, playerPos.y - m.position.y };
    float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (len > 0.01f) {
        dir.x /= len;
        dir.y /= len;
        m.position.x += dir.x * global_DEFAULTMONSTERSPEED;
        m.position.y += dir.y * global_DEFAULTMONSTERSPEED;
    }
}

/*
Calls function when game runs. Should always show generating all directions directly after this call

*/
void genFirstRoom(){
    RoomGenerator generator;
    room startRoom = generator.generateNewRoom();
    roomVec.push_back(startRoom);
    generator.checkIfRoomsAreLoadedAround(startRoom);

}

void gameRunning(PlayerStats player){
    Texture2D WallTiles = LoadTexture("images/DungeonWall.png");
    Texture2D FloorTiles = LoadTexture("images/floor.png");
    DrawTexture(FloorTiles, 0, 0, WHITE);
    
    //DrawRoom(((GetScreenWidth()/2) - 20), ((GetScreenHeight()/2)+20));
    updatePlayerPOS(global_theUser);
    drawMonsters(roomVec, global_theUser);
    
    DrawTexture(frames[currentFrame], global_theUser.x, global_theUser.y, WHITE);
    DrawTexture(WallTiles, 0, 0, WHITE);
    DrawRetroHUD(player, 560, GetScreenHeight());

}

void drawMenu(){
    //DrawText("Press [F] to toggle fullscreen", 40, 40, 20, RAYWHITE);
    //DrawText("Press [ESC] to quit", 70, 70, 20, RAYWHITE);
    DrawRectangle(740, 300, 430, 65, GRAY);
    DrawText("MAIN MENU", 750, 300, 70, WHITE);
    DrawText("PRESS [ENTER] TO START", 815, 380, 20, WHITE);
    DrawText("PRESS [ESC] TO QUIT", 845, 425, 20, WHITE);
}


void HANDLESTATE(PlayerStats player){
        switch (state) {
            case MAIN_MENU:
                drawMenu();
                if(IsKeyPressed(KEY_ENTER)){
                    state = GAME;
                }
                break;

            case GAME:
                gameRunning(player);
                break;

            case GAME_END:
                DrawText("GAME OVER", 180, 200, 30, RED);
                break;
        }
}

