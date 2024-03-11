#include "mario.h"

// Constructor
mario::mario(int lives){
    this->lives = lives;
    this->coins = 0;
    this->PL = 0;
    this->Alive = true;

}

// Destructor
mario::~mario(){
}

// Increases the amount of coins by "inc"
void mario::increaseCoins(int inc = 1){
    this->coins += inc;
    while (coins >= 20){
        this->lives += 1;
        this->coins -= 20;
    }
}

// changes the power level by "inc"
void mario::changePowerLevel(int inc){
    if (inc > 0 && this->PL != 2){
        this->PL += 1;
    }
    if (inc < 0 && this->PL != 0){
        this->PL -= 1;
    }
}

// changes the amount of lives by "inc"
void mario::changeLives(int inc){
    this->lives += inc;
    if (lives < 1){
        this->Alive = false;
    }
}

// Accessors
int mario::getLives(){
    return this->lives;
}

int mario::getCoins(){
    return this->coins;
}

bool mario::isAlive(){
    return this->Alive;
}

int mario::getPL(){
    return this->PL;
}
