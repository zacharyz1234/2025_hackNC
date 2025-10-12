#include "source.cpp"
#include <iostream>
#include <algorithm>
#include <cmath>

Texture2D enemyFrames[2];
//int currentFrame = 0;
//float frameTimer = 0.0f;
const float frameSpeed = 0.2f;

void loadEnemyTextures(){
    enemyFrames[0] = LoadTexture("EnemyFrame1.png");
    enemyFrames[1] = LoadTexture("EnemyFrame2.png");
}

void unloadEnemyTextures(){
    UnloadTexture(enemyFrames[0]);
    UnloadTexture(enemyFrames[1]);
}

void setDefaults(){
    theUser.x = GetScreenWidth() / 2;
    theUser.y = GetScreenHeight()/ 2;
    
}

/*only call this for monster you are iterating through, changes X and y to move towards player
at DEFAULT MONSTERSPEED
*/
void updateMonsterPOS(monster &m) {
    Vector2 dir = { theUser.x - m.position.x, theUser.y - m.position.y };
    float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (len > 0.01f) {
        dir.x /= len;
        dir.y /= len;
        m.position.x += dir.x * DEFAULTMONSTERSPEED;
        m.position.y += dir.y * DEFAULTMONSTERSPEED;
    }
}


void updatePlayerPOS(Vector2 &theUser){
    if(IsKeyDown(KEY_A)){
        theUser.x -= DEFAULTUSERSPEEDPER;
    }
    if(IsKeyDown(KEY_D)){
        theUser.x += DEFAULTUSERSPEEDPER;
    }
    if(IsKeyDown(KEY_S)){
        theUser.y += DEFAULTUSERSPEEDPER;
    }
    if(IsKeyDown(KEY_W)){
        theUser.y -= DEFAULTUSERSPEEDPER;
    }
}

void drawMonsters() {
    static int currentFrame = 0;
    static float frameTimer = 0.0f;

    frameTimer += GetFrameTime();
    if (frameTimer >= frameSpeed) {
        frameTimer = 0.0f;
        currentFrame = (currentFrame + 1) % 2;
    }

    for (room &r : roomVec) {
        if (r.isPlayerIn) {
            for (monster &m : r.monsterNumber) {
                updateMonsterPOS(m);
                DrawTexture(enemyFrames[currentFrame],
                            m.position.x - enemyFrames[currentFrame].width / 2,
                            m.position.y - enemyFrames[currentFrame].height / 2,
                            WHITE);
            }
        }
    }
}