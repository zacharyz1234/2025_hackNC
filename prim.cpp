#include "source.c"



Vector2 updatePlayerPOS(){
    Vector2 r;
    if(KEY_LEFT){
        r.x--;
    }
    if(KEY_RIGHT){
        r.x++;
    }
    if(KEY_UP){
        r.y++;
    }
    if(KEY_DOWN){
        r.y--;
    }
    return r;
}

