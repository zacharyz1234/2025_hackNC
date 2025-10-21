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
for(int i = 0; i < amount; i++){
    //push_back monster
}

}


/*
Generates and returns a new room
*/
room generateNewRoom(){
    std::string floorTypes[6] = {"dirt", "gravel", "glass", "sand", "etc", "etc"};
    std::string wallTypes[3] = {"wall1", "wall2", "wall3"}; 
    std::string torchColor[5] = {"blue", "green", "purple", "red", "none"};
    room r;
    srand(time(0));
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
    if(AroundThisRoom.toLeft == -1){
        room newRoom = generateNewRoom();
        AroundThisRoom.toLeft = newRoom.roomID; //set side to that rooms Id
        globalRoomVector.push_back(newRoom);
        printf("checkIfRoomsAreLoadedAround(), toLeft");
    }
    if(AroundThisRoom.toRight == -1){
        room newRoom = generateNewRoom();
        AroundThisRoom.toRight = newRoom.roomID; //set side to that rooms Id
        globalRoomVector.push_back(newRoom);
        printf("checkIfRoomsAreLoadedAround(), toRight");
    }
    if(AroundThisRoom.toUP == -1){
        room newRoom = generateNewRoom();
        AroundThisRoom.toUP = newRoom.roomID; //set side to that rooms Id     
        globalRoomVector.push_back(newRoom);
        printf("checkIfRoomsAreLoadedAround(), toUP");
    }
    if(AroundThisRoom.toDown == -1){
        room newRoom = generateNewRoom();
        AroundThisRoom.toDown = newRoom.roomID; //set side to that rooms Id 
        globalRoomVector.push_back(newRoom);   
        printf("checkIfRoomsAreLoadedAround(), toDown");
    }
    }
    





int main(){
    bool gamerunning = true;



    char temp = 'q'; //til finished
    globalRoomVector.push_back(generateNewRoom()); //makes first room before window opens
    while(temp != 'q'){
        checkIfRoomsAreLoadedAround(globalRoomVector[globalPlayerIsInThisRoom]); //global playerIsInThisRoom should always update with player
        cin >> temp;

    }


}
