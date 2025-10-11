#include "source.c"

void setDefaults(){
    theUser.x = GetScreenWidth() / 2;
    theUser.y = GetScreenHeight()/ 2;
}

void updatePlayerPOS(Vector2 &theUser){
    if(KEY_A){
        theUser.x--;
    }
    if(KEY_D){
        theUser.x++;
    }
    if(KEY_W){
        theUser.y++;
    }
    if(KEY_D){
        theUser.y--;
    }
}


