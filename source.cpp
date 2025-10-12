#include<raylib.h>
#include<vector>
#include"cStructs.h"

#pragma once


//window related
int screenWidth = 960;
int screenHeight = 540;
bool fullscreen = false;


//game const
const float startUserX = 200;
const float startUserY = 200;
const float DEFAULTUSERSPEEDPER = 3.5;
const float DEFAULTMONSTERSPEED = 1.5;


//changables
int nextRoomId = 1;
int currentDif = 1;
int SpawnMonstersInRoom = 2;
int spawnTorchesInRoom = 5;



//data structures 
Vector2 theUser;

struct room{
    bool init = false;
    int roomID;
    bool isPlayerIn = false;
    bool hasPlayerVisted = false;
    std::vector<std::vector<Color>> backGroundOf;
    std::vector<monster> monsterNumber;
    int toLeft = NULL;
    int toRight = NULL;
    int toUP = NULL;
    int toDown = NULL;
};

std::vector<room> roomVec;

