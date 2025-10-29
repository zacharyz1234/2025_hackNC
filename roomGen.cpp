#include "prim.cpp"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>

class RoomGenerator {
public:
    RoomGenerator() {
        srand(static_cast<unsigned>(time(nullptr))); //seed
    }

    room generateNewRoom() {
        static const char floorTypes[6] = { 'd', 'g', 'w', 'r', 'e', 'e' };
        static const char wallTypes[6]  = { 'd', 'g', 'w', 'r', 'e', 'e' };
        static const char torchColor[6] = { 'd', 'g', 'w', 'r', 'e', 'e' };

        room r;
        int floor = rand() % 6;
        int wall = rand() % 3;
        int torch = rand() % 5;
        int monsterCount = (rand() % global_MaxMonsterSpawn) + 1;

        r.roomID = global_RoomIdCounter++;
        r.floorType = floorTypes[floor];
        r.wallType = wallTypes[wall];
        r.torchColor = torchColor[torch];
        r.monsterNumber = makeNewMonstersVector(monsterCount);

        printf("generateNewRoom() called\n");
        printf("ID: %d\n", r.roomID);

        return r;
    }

    void checkIfRoomsAreLoadedAround(room& aroundThisRoom) {
        if (aroundThisRoom.toLeft == -1) {
            room newRoom = generateNewRoom();
            newRoom.toRight = aroundThisRoom.roomID;
            aroundThisRoom.toLeft = newRoom.roomID;
            roomVec.push_back(newRoom);
            printf("Loaded room toLeft\n");
        }

        if (aroundThisRoom.toRight == -1) {
            room newRoom = generateNewRoom();
            newRoom.toLeft = aroundThisRoom.roomID;
            aroundThisRoom.toRight = newRoom.roomID;
            roomVec.push_back(newRoom);
            printf("Loaded room toRight\n");
        }

        if (aroundThisRoom.toUP == -1) {
            room newRoom = generateNewRoom();
            newRoom.toDown = aroundThisRoom.roomID;
            aroundThisRoom.toUP = newRoom.roomID;
            roomVec.push_back(newRoom);
            printf("Loaded room toUP\n");
        }

        if (aroundThisRoom.toDown == -1) {
            room newRoom = generateNewRoom();
            newRoom.toUP = aroundThisRoom.roomID;
            aroundThisRoom.toDown = newRoom.roomID;
            roomVec.push_back(newRoom);
            printf("Loaded room toDown\n");
        }
    }

private:
    std::vector<monster> makeNewMonstersVector(int amount) {
        std::vector<monster> monsters;
        monsters.reserve(amount);

        for (int i = 0; i < amount; i++) {
            monster m;
            m.health = 1 + rand() % 5;
            m.position = { static_cast<float>(rand() % 10), static_cast<float>(rand() % 10) };
            monsters.push_back(m);
        }
        return monsters;
    }
};
