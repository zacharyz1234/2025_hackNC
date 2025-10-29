#include "raylib.h" 
#include "source.cpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include "cStructs.h"

#pragma once


void loadEnemyTextures(){
    enemyFrames[0] = LoadTexture("images/EnemyFrame1.png");
    enemyFrames[1] = LoadTexture("images/EnemyFrame2.png");
}

void unloadEnemyTextures(){
    UnloadTexture(enemyFrames[0]);
    UnloadTexture(enemyFrames[1]);
}

void setDefaults(){
    global_theUser.x = GetScreenWidth() / 2;
    global_theUser.y = GetScreenHeight()/ 2;
}

bool checkCollision(Vector2 a, Vector2 b, float aRadius, float bRadius) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float distance = sqrtf(dx * dx + dy * dy);
    return distance < (aRadius + bRadius);
}

void updateMonsterPOS(monster &m) {
    Vector2 dir = { global_theUser.x - m.position.x, global_theUser.y - m.position.y };
    float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (len > 0.01f) {
        dir.x /= len;
        dir.y /= len;
        m.position.x += dir.x * global_DEFAULTMONSTERSPEED;
        m.position.y += dir.y * global_DEFAULTMONSTERSPEED;
    }
}

void handlePlayerHit() {
    global_theUser.x = GetScreenWidth() / 2;
    global_theUser.y = GetScreenHeight() / 2;

    global_playerHealth = false;
    if (!global_playerHealth) {
        state = GAME_END;
    }
}

void updatePlayerPOS(Vector2 &global_theUser){
    if(IsKeyDown(KEY_A)){
        global_theUser.x -= global_DEFAULTUSERSPEEDPER;
    }
    if(IsKeyDown(KEY_D)){
        global_theUser.x += global_DEFAULTUSERSPEEDPER;
    }
    if(IsKeyDown(KEY_S)){
        global_theUser.y += global_DEFAULTUSERSPEEDPER;
    }
    if(IsKeyDown(KEY_W)){
        global_theUser.y -= global_DEFAULTUSERSPEEDPER;
    }
}

void drawMonsters(std::vector<room> &roomVec, Vector2 playerPos) {
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
                Vector2 monsterPos = { m.position.x, m.position.y };
                DrawTexture(enemyFrames[currentFrame], monsterPos.x - enemyFrames[currentFrame].width/2,
                                    monsterPos.y - enemyFrames[currentFrame].height/2, WHITE);
            }
        }
    }
}




struct PlayerStats {
    int health;
    int enemiesKilled;
    float timeAlive;
};

void DrawRetroHUD(const PlayerStats& stats, int screenWidth, int screenHeight) {
    int boxWidth = 300;
    int boxHeight = 120;
    int margin = 20;
    int boxX = (screenWidth / 2) - (boxWidth * 0.75f);
    int boxY = screenHeight - boxHeight - margin -30; 


//colors border, text backgroud
    Color bgColor = (Color){ 20, 20, 20, 220 };     
    Color borderColor = (Color){ 0, 255, 128, 255 }; 
    Color textColor = (Color){ 0, 255, 128, 255 };   

    DrawRectangle(boxX, boxY, boxWidth, boxHeight, bgColor);
    DrawRectangleLinesEx((Rectangle){(float)boxX, (float)boxY, (float)boxWidth, (float)boxHeight}, 3, borderColor);

    for (int i = 0; i < boxHeight; i += 4) {
        DrawLine(boxX, boxY + i, boxX + boxWidth, boxY + i, Fade(borderColor, 0.05f));
    }

    int fontSize = 20;
    int padding = 20;

    DrawText(TextFormat("HP: %03d", stats.health), boxX + padding, boxY + padding, fontSize, textColor);
    DrawText(TextFormat("TIME: %.1f", stats.timeAlive), boxX + padding, boxY + padding + 30, fontSize, textColor);
    DrawText(TextFormat("KILLS: %03d", stats.enemiesKilled), boxX + padding, boxY + padding + 60, fontSize, textColor);
}