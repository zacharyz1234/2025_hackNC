#include "source.cpp"
#include <iostream>
#include <algorithm>
#include <cmath>
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
    for (room &r : roomVec) {
        if (r.isPlayerIn) {
            for (monster &m : r.monsterNumber) {
                updateMonsterPOS(m);
                DrawCircle(m.position.x, m.position.y, 10, RED);
            }
        }
    }
}


