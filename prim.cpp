#include "source.cpp"

void setDefaults(){
    theUser.x = GetScreenWidth() / 2;
    theUser.y = GetScreenHeight()/ 2;
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


