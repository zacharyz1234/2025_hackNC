#include<raylib.h>
#include<vector>
#include"cStructs.h"

#pragma once

#define PLAYER_RADIUS 10.0f
#define MONSTER_RADIUS 10.0f



/*
Variables here should be marked global_ for ease of access/ prevent confusion. If editing these,
you should add it in the commit comment to help track large changes



*/


//window related
int global_screenWidth = 1920;
int global_screenHeight = 1080;
bool global_fullscreen = false;
bool global_playerHealth = true;


//game const
const float global_startUserX = 200;
const float global_startUserY = 200;
const float global_DEFAULTUSERSPEEDPER = 3.5;
const float global_DEFAULTMONSTERSPEED = 1.5;
bool global_isGameRunning = true;

//changables


int global_RoomIdCounter = 0;
int global_MaxMonsterSpawn = 1;
int global_PlayerIsInThisRoom = 0;
int global_currentDif = 3; //add more monst, might change later



//data structures 
Vector2 global_theUser;

struct room {
    bool init = false;
    int roomID;
    bool isPlayerIn = false;
    bool hasPlayerVisted = false;
    std::vector<std::vector<Color>> backGroundOf;
    std::vector<monster> monsterNumber;
    int toLeft = -1;
    int toRight = -1;
    int toUP = -1;
    int toDown = -1;
};



std::vector<room> roomVec;




//gameState
enum Gamestate{
    MAIN_MENU,
    GAME,
    GAME_END,
    
};

Gamestate state = MAIN_MENU;
