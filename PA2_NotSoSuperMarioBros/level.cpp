#include "level.h"


level::level(int N, int coins, int nothing, int goombas, int koopas,  int mushrooms, bool pipe){
    srand(time(0));
    //initalize 2D array of char pointers
    char** levelArr = new char* [N];
    for  (int i = 0; i < N; ++i){
        levelArr[i] = new char[N];
    }
    // converts all variables into member variables
    this->levelArr = levelArr;
    this->N = N;
    this->coins = coins;
    this->nothing = nothing;
    this->goombas = goombas;
    this->koopas = koopas;
    this->mushrooms = mushrooms;

    // converts all the percentages in number of spaces depending on the total number of spaces avaliable
    int total_spaces = (N * N) - 2;
    int coins_spaces = total_spaces * (static_cast<float>(coins) / 100);
    int nothing_spaces = total_spaces * (static_cast<float>(nothing) / 100);
    int goombas_spaces = total_spaces * (static_cast<float>(goombas) / 100);
    int koopas_spaces = total_spaces * (static_cast<float>(koopas) / 100);
    int mushroom_spaces = total_spaces * (static_cast<float>(mushrooms) / 100);
    int spacesArr [5] = {coins_spaces, nothing_spaces, goombas_spaces, koopas_spaces, mushroom_spaces};
    
    // puts a 0 in every spot
    int row, col, num;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            this->levelArr[i][j] = '0';
        }
    }

    
    // adds pipe to level
    if (pipe){
        num = rand() % (N * N);
        row = num / N;
        col = num % N;
        this->levelArr[row][col] = 'w';
    }
    //adds the boss to a random spot, and checks if a pipe is already there
    num = rand() % (N * N);
    row = num / N;
    col = num % N;
    while(this->levelArr[row][col] != '0'){
        num = rand() % (N * N);
        row = num / N;
        col = num % N;
    }
    this->levelArr[row][col] = 'b';
    // fills the level with entities or nothing spaces
    for (int i = 0; i < 5; ++i){ // loops through the types of entities
        for (int j = 0; j < spacesArr[i]; ++j){ // loops through number of each entity needed
            // generates a random row and column
            num = rand() % (N * N);
            row = num / N;
            col = num % N;
            // if there's already something in the row and column, then it keeps generating new ones until theres not
            while (this->levelArr[row][col] != '0'){
                num = rand() % (N * N);
                row = num % N;
                col = num / N;
            }
            switch(i){
                case 0:
                    this->levelArr[row][col] = 'c';
                    break;
                case 1:
                    this->levelArr[row][col] = 'x';
                    break;
                case 2:
                    this->levelArr[row][col] = 'g';
                    break;
                case 3:
                    this->levelArr[row][col] = 'k';
                    break;
                case 4:
                    this->levelArr[row][col] = 'm';
                    break;
            }

        }   
    }

    // Algorithm that reorders the array of spaces based off highest to lowest.
    int OrderedSpaces[5]; 
    for (int i = 0; i < 5; i++){
        OrderedSpaces[i] = spacesArr[i];
    }
    int temp;
    for(int i= 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){ 
            if(OrderedSpaces[i] > OrderedSpaces[j]){
                int temp = OrderedSpaces[i];
                OrderedSpaces[i] = OrderedSpaces[j];
                OrderedSpaces[j] = temp;
            }
        }
    }
    // creates a char array of the ordered array
    char charArr[5];
    for (int i = 0; i < 5; i++){
        if (OrderedSpaces[i] == coins_spaces){
            charArr[i] = 'c';
        }else if(OrderedSpaces[i] == nothing_spaces){
            charArr[i] = 'x';
        }else if(OrderedSpaces[i] == koopas_spaces){
            charArr[i] = 'k';
        }else if(OrderedSpaces[i] == goombas_spaces){
            charArr[i] = 'g';
        }else if(OrderedSpaces[i] == mushroom_spaces){
            charArr[i] = 'm';
        }
    }
    int count = 0;
    // Fills empty spaces in order of highest frequency of spaces
    for (int row = 0; row < N; ++row){
        for (int col = 0; col < N; ++col){
            while (this->levelArr[row][col] == '0'){
                if (charArr[count] == 'c'){
                    if (coins_spaces != 0){
                        this->levelArr[row][col] = 'c';
                    }else{
                        count++;
                    }
                }
                if(charArr[count] == 'x'){
                    if (nothing_spaces != 0){
                        this->levelArr[row][col] = 'x';
                    }else{
                        count++;
                    }
                }
                if(charArr[count] == 'k'){
                    if (koopas_spaces != 0){
                        this->levelArr[row][col] = 'k';
                    }else{
                        count++;
                    }
                }
                if(charArr[count] == 'g'){
                    if (goombas_spaces != 0){
                        this->levelArr[row][col] = 'g';
                    }else{
                        count++;
                    }
                }
                if(charArr[count] == 'm'){
                    if (mushroom_spaces != 0){
                        this->levelArr[row][col] = 'm';
                    }else{
                        count++;
                    }
                }
                count++;
                if (count > 4){
                    count = 0;
                }
            }
        }
    }
}
// Destructor
level::~level(){
    for  (int i = 0; i < this->N; ++i){
        delete[] levelArr[i];
    }
    delete[] levelArr;
}

// Level Accessor
char** level::getLevel(){
    return this->levelArr;
}

// Size Accessor
int level::getSize(){
    return this->N;
}