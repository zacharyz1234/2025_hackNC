
#include"prim.cpp"


#pragma once

std::vector<monster> makeNewMonstersVector(int amount){
    std::vector<monster> monsters;
    for(int i = 0; i < amount; i++){
        monster m;
        m.health = 1 + rand() % 5; // Optional: random health between 1 and 5
        m.position = { static_cast<float>(rand() % 10), static_cast<float>(rand() % 10) }; // Random positions
        monsters.push_back(m);
    }
    return monsters;
}



/*
Generates and returns a new room
*/
room generateNewRoom(){
    //when done. define what these mean.
    char floorTypes[6] = {'d', 'g', 'w', 'r', 'e', 'e'};
    char wallTypes[6] = {'d', 'g', 'w', 'r', 'e', 'e'};
    char torchColor[6] = {'d', 'g', 'w', 'r', 'e', 'e'};
    room r;
    int floor = (rand() % 6) + 1;
    int wall = (rand() % 3) + 1;
    int monsterCount = (rand() % global_MaxMonsterSpawn) + 1;
    int torch = (rand() % 5) + 1;
    r.roomID = global_RoomIdCounter;

    r.torchColor = torchColor[torch];
    r.floorType = floorTypes[floor];
    r.wallType = wallTypes[wall];
    r.monsterNumber = makeNewMonstersVector(monsterCount);
    




    printf("generateNewRoom() called \n");
    printf("ID: %d\n", global_RoomIdCounter);
    global_RoomIdCounter++; //update count as only one room is generated, and a call on this function will increment the count
    return r;
}



void checkIfRoomsAreLoadedAround(room &AroundThisRoom){
if (AroundThisRoom.toLeft == -1) {
    room newRoom = generateNewRoom();
    newRoom.toRight = AroundThisRoom.roomID; // new room knows it is to the left of current
    AroundThisRoom.toLeft = newRoom.roomID;  // current room knows about the new room on the left

    roomVec.push_back(newRoom);
    printf("checkIfRoomsAreLoadedAround(), toLeft\n");
}

if (AroundThisRoom.toRight == -1) {
    room newRoom = generateNewRoom();
    newRoom.toLeft = AroundThisRoom.roomID;
    AroundThisRoom.toRight = newRoom.roomID;
    roomVec.push_back(newRoom);
    printf("checkIfRoomsAreLoadedAround(), toRight\n");
}
if (AroundThisRoom.toUP == -1) {
    room newRoom = generateNewRoom();
    newRoom.toDown = AroundThisRoom.roomID;
    AroundThisRoom.toUP = newRoom.roomID;
    roomVec.push_back(newRoom);
    printf("checkIfRoomsAreLoadedAround(), toUP\n");
}
if (AroundThisRoom.toDown == -1) {
    room newRoom = generateNewRoom();
    newRoom.toUP = AroundThisRoom.roomID;
    AroundThisRoom.toDown = newRoom.roomID;
    roomVec.push_back(newRoom);
    printf("checkIfRoomsAreLoadedAround(), toDown\n");
}

    }
