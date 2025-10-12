#pragma once
#include "raylib.h"

struct vectorGrid{
    float x;
    float y;
};




struct monster{
    int health = 1;
    vectorGrid position;
};