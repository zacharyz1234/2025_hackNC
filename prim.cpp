#include "source.cpp"

void setDefaults(){
    theUser.x = GetScreenWidth() / 2;
    theUser.y = GetScreenHeight()/ 2;
}

void updatePlayerPOS(Vector2 &theUser){
    if(IsKeyDown(KEY_A)){
        theUser.x--;
    }
    if(IsKeyDown(KEY_D)){
        theUser.x++;
    }
    if(IsKeyDown(KEY_S)){
        theUser.y++;
    }
    if(IsKeyDown(KEY_W)){
        theUser.y--;
    }
}


