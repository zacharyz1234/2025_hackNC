#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
/*



*/




struct vectorGrid{
    float x;
    float y;
};

struct monster{
    int health;
    vectorGrid position;
};




struct room {
    bool init = false;
    int roomID;
    bool isPlayerIn = false;
    bool hasPlayerVisted = false;
    std::string floorType;
    std::string wallType;
    std::vector<monster> monsterNumber;
    std::string torchColor;
    int toLeft = -1;
    int toRight = -1;
    int toUP = -1;
    int toDown = -1;
};

int globalRoomIdCounter = 0;
std::vector<room> globalRoomVector;
int globalMaxMonsterSpawn = 1;
int globalPlayerIsInThisRoom = 0;


/*
When finished, this will make a new vector of completely random monsters
*/
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
    




    printf("generateNewRoom()\n");
    printf("ID: %d\n", globalRoomIdCounter);
    globalRoomIdCounter++; //update count as only one room is generated, and a call on this function will increment the count
    return r;
}


/*
checks if the room to the side of room x exist, and if they dont generates a new room and pushes it onto the vector
in place newroom.ID. SHOULD ONLY BE CALLED ON THE USERS CURRENT ROOM
*/
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
    

    void printOj(){
        printf("CURRENT ROOM: %d \n", globalRoomVector[globalPlayerIsInThisRoom].roomID);
        printf("UP: %d \n", globalRoomVector[globalPlayerIsInThisRoom].toUP);
        printf("DOWN: %d \n", globalRoomVector[globalPlayerIsInThisRoom].toDown);
        printf("RIGHT: %d \n", globalRoomVector[globalPlayerIsInThisRoom].toRight);
        printf("LEFT: %d \n", globalRoomVector[globalPlayerIsInThisRoom].toLeft);
        printf("PLAYERHASVISTED: %d \n", globalRoomVector[globalPlayerIsInThisRoom].hasPlayerVisted);
    }



int main(){
    bool gamerunning = true;



    char temp = 'o'; //til finished
    globalRoomVector.push_back(generateNewRoom()); //makes first room before window opens
    srand(time(0));
    while(temp != 'q'){
        checkIfRoomsAreLoadedAround(globalRoomVector[globalPlayerIsInThisRoom]); //global playerIsInThisRoom should always update with player
        std::cin >> temp;
        if(temp == 'p'){
            printOj();
        }

    }


}
