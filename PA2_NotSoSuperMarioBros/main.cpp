#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <cstdlib>
#include "fileProcessor.h"
#include "world.h"
#include "mario.h"
using namespace std;

int main(int argc, char** argv){
    // processes the file to put information in an int array
    string input = argv[1];
    string output = argv[2];
    fileProcessor* processor = new fileProcessor(input, output);
    int* info = processor->processInput();
    // if the percentages of the coins, nothing, goombas, koopas, and mushrooms aren't 100, then it ends the program.
    if (info[3] + info[4] + info[5] + info[6]+ info[7] != 100){
        throw runtime_error("Please make sure the percentages for lines 4-8 add up to 100");
    }
    int L = info[0];
    int N = info[1];
    
    // Creating the World
    world* theWorld = new world(info[0], info[1], info[2], info[3], info[4], info[5], info[6], info[7]);
    char*** worldArr = theWorld->getWorld();
    // Creating Mario
    mario* MarioMC = new mario(info[2]);
    // putting mario in a random first spot
    int num, row, col, theLevel, EnemyStreak;
    num = rand() % (N * N);
    row = num / N;
    col = num % N;
    theLevel = 0;
    int current[3] = {theLevel, row, col};
    bool win, stay = false;
    srand(time(0));
    // outputs to file
    fstream outputFile;
    outputFile.open(output, ios::app);
    processor->outputLevel(worldArr, current[0], N);
    outputFile << "Mario is starting at position: (" << (N - current[1]) << "," << (N - current[2]) << ")\n";
    // Running the simulation
    int totalMoveCount = 0;
    while (MarioMC->isAlive() && win == false){
        totalMoveCount++;
        // outputs
        outputFile.open(output, ios::app);
        processor->outputLevel(worldArr, current[0], N);
        outputFile << "Level: " << current[0] + 1 << ". ";
        outputFile << "Mario is at position: (" << (N - current[1]) << "," << (N - current[2]) << "). ";
        outputFile << "Mario is at power level " << MarioMC->getPL() << ". ";
        // updates the variables 
        theLevel = current[0];
        row = current[1];
        col = current[2];
        // switch case that does different actions based off which char is in the position.
        switch(worldArr[theLevel][row][col]){
            case 'c':
                MarioMC->increaseCoins(1);
                worldArr[theLevel][row][col] = 'x';
                outputFile << "Mario collected a coin. ";
                break;
            case 'x':
                outputFile << "Mario visited an empty space. ";
                break;
            case 'g':
                num = rand() % 10;
                if (num < 8){
                    // Wins against goomba
                    outputFile << "Mario encountered a goomba and won. ";
                    worldArr[theLevel][row][col] = 'x';
                    EnemyStreak++;
                    if (EnemyStreak == 7){
                        MarioMC->changeLives(1);
                        EnemyStreak = 0;
                    }
                }else{
                    // Loses against goomba
                    outputFile << "Mario encountered a goomba and lost. ";
                    if(MarioMC->getPL() == 0){
                        MarioMC->changeLives(-1);
                        EnemyStreak = 0;
                    }else{
                        MarioMC->changePowerLevel(-1);
                    }
                }
                break;
            case 'k':
                num = rand() % 100;
                if (num < 65){
                    // wins against koopa
                    outputFile << "Mario encountered a koopa and won. ";
                    worldArr[theLevel][row][col] = 'x';
                    EnemyStreak++;
                    if (EnemyStreak == 7){
                        MarioMC->changeLives(1);
                        EnemyStreak = 0;
                    }
                }else{
                    // loses against koopa
                    outputFile << "Mario encountered a koopa and lost. ";
                    if(MarioMC->getPL() == 0){
                        MarioMC->changeLives(-1);
                        EnemyStreak = 0;
                    }else{
                        MarioMC->changePowerLevel(-1);
                    }
                }
                break;
            case 'm':
                outputFile << "Mario ate a mushroom. ";
                MarioMC->changePowerLevel(1);
                worldArr[theLevel][row][col] = 'x';
                break;
            case 'b':
                stay = true;
                num = rand() % 2;
                if (num == 0){
                    // wins against boss
                    outputFile << "Mario encountered a boss and won. ";
                    if (current[0] == (L -1)){
                        // Final level
                        win = true;
                        stay = true;
                    }else{
                        // Other levels
                        current[0]++;
                        stay = false;
                        num = rand() % (N * N);
                        current[1] = num / N;
                        current[2] = num % N;
                    }
                }else{
                    // loses against boss
                    outputFile << "Mario encountered a boss and lost. ";
                    if (MarioMC->getPL() <= 1 ){
                        MarioMC->changeLives(-1);
                    }else{
                        MarioMC->changePowerLevel(-2);
                    }
                }
                break;
            case 'w':
                outputFile << "Mario encountered a warp pipe. ";
                current[0]++;
                num = rand() % (N * N);
                current[1] = num / N;
                current[2] = num % N;
                break;

        }

        // grammar :)
        if (MarioMC->getLives() == 1){
            outputFile << "Mario has " << MarioMC->getLives() << " life left. ";
        }else{
            outputFile << "Mario has " << MarioMC->getLives() << " lives left. ";
        }
        outputFile << "Mario has " << MarioMC->getCoins() << " coins . ";

        // Movements
        if (stay == false){
            int num1 = rand() % 4;
            switch(num1){
                case 0:
                    // moves down
                    outputFile << "Mario will move DOWN.\n";
                    if (current[1] == (N - 1)){
                        current[1] = 0;
                    }else{
                        current[1]++;
                    }
                    break;
                case 1:
                    // moves up
                    outputFile << "Mario will move UP.\n";
                    if (current[1] == 0){
                        current[1] = N - 1;
                    }else{
                        current[1]--; 
                    }
                    break;
                case 2:
                    // moves right
                    outputFile << "Mario will move RIGHT.\n";
                    if (current[2] == (N - 1)){
                        current[2] = 0;
                    }else{
                        current[2]++; 
                    }
                    break;
                case 3:
                    // moves left
                    outputFile << "Mario will move LEFT.\n";
                    if (current[2] == 0){
                        current[2] == N - 1;
                    }else{
                        current[2]--; 
                    }
                    break;
                
            }
        }else{
            // staying still if a boss was encountered or mario won the game.
            if (win == false){
                totalMoveCount--; // no moves happened since mario stayed
                outputFile << "Mario will STAY.\n";
            }else{
                outputFile << "\n";
            }
        }
        outputFile << "===========\n";
        outputFile.close();
    }

    outputFile.open(output, ios::app);
    if (!MarioMC->isAlive()){
        outputFile << "Mario Died\n";
    }else{
        outputFile << "Mario WON THE GAME!!!\n";
    }
    outputFile << "Total Moves: " << totalMoveCount << "\n";


    // Deallocation
    outputFile.close();
    delete theWorld;
    delete processor;
    delete MarioMC;

    return 0;



}