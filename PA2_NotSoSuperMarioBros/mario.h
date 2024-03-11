#ifndef MARIO_H
#define MARIO_H

class mario{
    public:
        mario(int lives);
        ~mario();
        void increaseCoins(int inc);
        void changePowerLevel(int inc);
        void changeLives(int inc);
        int getLives();
        int getCoins();
        bool isAlive();
        int getPL();
        
        
        

    private:
        int lives;
        int coins;
        int PL;
        int Alive;
};

#endif