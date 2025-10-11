#include"windows.cpp"
#include"colors.cpp"


enum class Gamestate{
    MAIN_MENU,
    GAME,
    GAME_END,
    
};

Gamestate state = Gamestate::MAIN_MENU;




void HANDLESTATE(){
    if(state == Gamestate::MAIN_MENU && IsKeyPressed(KEY_ENTER)){ //in main menu

    }
    if(state == Gamestate::GAME){
        //run game
    }
    if(state == Gamestate::GAME_END){
        //end
    }
}

