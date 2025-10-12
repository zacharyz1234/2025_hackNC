#include "source.cpp"
#include <iostream>
#include <algorithm>
void setDefaults(){
    theUser.x = GetScreenWidth() / 2;
    theUser.y = GetScreenHeight()/ 2;
}
const float DEFAULTMONSTERSPEED = 1.5; // temp for now move to source later

//call on float: a < b true
bool twoIsGreater(float a, float b){

}

/*only call this for monster you are iterating through, changes X and y to move towards player
at DEFAULT MONSTERSPEED
*/
void updateMonsterPOS(Vector2 &theMonster){

    if(twoIsGreater(theUser.y, theMonster.x)){
        theMonster.x -= DEFAULTMONSTERSPEED;
    }else{
        theMonster.x += DEFAULTMONSTERSPEED;
    }
    if(twoIsGreater(theUser.y, theMonster.y)){
        theMonster.y -= DEFAULTMONSTERSPEED;
    }else{
        theMonster.y += DEFAULTMONSTERSPEED;
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


