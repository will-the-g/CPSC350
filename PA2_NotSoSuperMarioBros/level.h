#ifndef LEVEL_H
#define LEVEL_H
#include<cstdlib>
#include<iostream>
#include<time.h>
using namespace std;

class level{
    public:
        level(int N, int coins, int nothing, int goombas, int koopas,  int mushrooms, bool pipe);
        ~level();
        char** getLevel();
        int getSize();

    private:
        char** levelArr;
        int N;
        int coins;
        int nothing;
        int goombas;
        int koopas;
        int mushrooms;
};


#endif