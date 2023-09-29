#ifndef WORLD_H
#define WORLD_H
using namespace std;
#include "level.h"

class world{
    public:
        world(int levels, int dimensions, int lives, int coins, int nothing, int goombas, int koopas, int mushrooms);
        ~world();
        void printWorld();
        char*** getWorld();
        
    private:
        int levels;
        int dimensions;
        char*** worldArr;
};
#endif