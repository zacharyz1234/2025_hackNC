
#include<prim.cpp>

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
    std::string floorTypes[6] = {"dirt", "gravel", "glass", "sand", "etc", "etc"};
    std::string wallTypes[3] = {"wall1", "wall2", "wall3"}; 
    std::string torchColor[5] = {"blue", "green", "purple", "red", "none"};
    room r;
    int floor = (rand() % 6) + 1;
    int wall = (rand() % 3) + 1;
    int monsterCount = (rand() % globalMaxMonsterSpawn) + 1;
    int torch = (rand() % 5) + 1;
    r.roomID = globalRoomIdCounter;

    r.torchColor = torchColor[torch];
    r.floorType = floorTypes[floor];
    r.wallType = wallTypes[wall];
    r.monsterNumber = makeNewMonstersVector(monsterCount);
    




    printf("generateNewRoom() called \n");
    printf("ID: %d\n", globalRoomIdCounter);
    globalRoomIdCounter++; //update count as only one room is generated, and a call on this function will increment the count
    return r;
}



void checkIfRoomsAreLoadedAround(room &AroundThisRoom){
if (AroundThisRoom.toLeft == -1) {
    room newRoom = generateNewRoom();
    newRoom.toRight = AroundThisRoom.roomID; // new room knows it is to the left of current
    AroundThisRoom.toLeft = newRoom.roomID;  // current room knows about the new room on the left

    globalRoomVector.push_back(newRoom);
    printf("checkIfRoomsAreLoadedAround(), toLeft\n");
}

if (AroundThisRoom.toRight == -1) {
    room newRoom = generateNewRoom();
    newRoom.toLeft = AroundThisRoom.roomID;
    AroundThisRoom.toRight = newRoom.roomID;
    globalRoomVector.push_back(newRoom);
    printf("checkIfRoomsAreLoadedAround(), toRight\n");
}
if (AroundThisRoom.toUP == -1) {
    room newRoom = generateNewRoom();
    newRoom.toDown = AroundThisRoom.roomID;
    AroundThisRoom.toUP = newRoom.roomID;
    globalRoomVector.push_back(newRoom);
    printf("checkIfRoomsAreLoadedAround(), toUP\n");
}
if (AroundThisRoom.toDown == -1) {
    room newRoom = generateNewRoom();
    newRoom.toUP = AroundThisRoom.roomID;
    AroundThisRoom.toDown = newRoom.roomID;
    globalRoomVector.push_back(newRoom);
    printf("checkIfRoomsAreLoadedAround(), toDown\n");
}

    }
