#include<raylib.h>
#include<vector>

#pragma once

//game const
int screenWidth = 960;
int screenHeight = 540;
bool fullscreen = false;

const float startUserX = 200;
const float startUserY = 200;
int nextRoomId = 1;
float DEFAULTUSERSPEEDPER = 3.5;

Vector2 theUser;

struct monster{
    int health = 1;
    Vector2 position;
};
struct room{
    int roomID;
    bool isPlayerIn = false;
    bool hasPlayerVisted = false;
    std::vector<std::vector<Color>> backGroundOf;
    std::vector<monster> monsterNumber;
};
