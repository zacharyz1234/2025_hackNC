#include "source.cpp"
#include <iostream>
#include <algorithm>
void setDefaults(){
    theUser.x = GetScreenWidth() / 2;
    theUser.y = GetScreenHeight()/ 2;
}

//call on float: a < b true
bool twoIsGreater(float a, float b){

if(a < b){
    return true;
}

return false;
}

/*only call this for monster you are iterating through, changes X and y to move towards player
at DEFAULT MONSTERSPEED
*/
void updateMonsterPOS(monster &theMonster){

    if(twoIsGreater(theUser.y, theMonster.position.y)){
        theMonster.position.x -= DEFAULTMONSTERSPEED;
    }else{
        theMonster.position.x += DEFAULTMONSTERSPEED;
    }
    if(twoIsGreater(theUser.y, theMonster.position.y)){
        theMonster.position.y -= DEFAULTMONSTERSPEED;
    }else{
        theMonster.position.y += DEFAULTMONSTERSPEED;
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


