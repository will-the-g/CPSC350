#include "world.h"

// Constructor
world::world(int levels, int dimensions, int lives, int coins, int nothing, int goombas, int koopas, int mushrooms){
    // Adding member variables and Allocations
    char*** worldArr = new char**[levels];
    this->worldArr = worldArr;
    this->levels = levels;
    this->dimensions = dimensions;

    // creates new level, gets the 2D array from it, then adds the 2D array to world Array, with the pipe.
    for (int i = 0; i < levels - 1; i++){
        
        level* level1 = new level(dimensions, coins, nothing, goombas, koopas, mushrooms, true);
        char** levelAsArr = level1->getLevel();
        this->worldArr[i] = levelAsArr;
    }


    // Adds the last level without a pipe
    level* levelLast = new level(dimensions, coins, nothing, goombas, koopas, mushrooms, false);
    char** levelLastAsArr = levelLast->getLevel();
    this->worldArr[this->levels - 1] = levelLastAsArr;

}

// Destructor
world::~world(){
    for (int i = 0; i < this->levels; i++){
        for (int j = 0; j < dimensions; j++){
            delete[] worldArr[i][j];
        }
        delete[] worldArr[i];
    }
    delete[] worldArr;
}

// Prints out the World (for testing)
void world::printWorld(){
    for (int eachlevel = 0; eachlevel < this->levels; eachlevel++){
        cout << "Level " << eachlevel + 1 << ": " << endl;
        for (int row = 0; row < this->dimensions; ++row){
            for (int col = 0; col < this->dimensions; ++col){
                cout << this->worldArr[eachlevel][row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Accessors
char*** world::getWorld(){
    return this->worldArr;
}