#include "raylib.h" 
#include "source.cpp"
#include <iostream>
#include <algorithm>
#include <cmath>

Texture2D enemyFrames[2];
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

bool checkCollision(Vector2 a, Vector2 b, float aRadius, float bRadius) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float distance = sqrtf(dx * dx + dy * dy);
    return distance < (aRadius + bRadius);
}

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

void handlePlayerHit() {
    theUser.x = GetScreenWidth() / 2;
    theUser.y = GetScreenHeight() / 2;

    playerHealth--;
    if (playerHealth <= 0) {
        state = GAME_END;
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
    for (room &r : roomVec) {
        if (r.isPlayerIn) {
            for (monster &m : r.monsterNumber) {
                updateMonsterPOS(m);
                DrawCircle(m.position.x, m.position.y, MONSTER_RADIUS, RED);

                if (checkCollision(m.position, theUser, MONSTER_RADIUS, PLAYER_RADIUS)) {
                    TraceLog(LOG_INFO, "Player hit by monster!");
                    handlePlayerHit();
                }
            }
        }
    }
}
