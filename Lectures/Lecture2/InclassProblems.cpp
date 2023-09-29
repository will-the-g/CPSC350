#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



void matrixRandom(int** matrix, int m, int n){
    srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            matrix[i][j] = rand();
        }
    }
}

int matrixDiagonal(int** matrix, int m){
    int sum = 0;
    if (sizeof(matrix) == sizeof(matrix[0])){
        for (int i = 0; i < sizeof(matrix); ++i){
            sum += matrix[i][i];
        }
    }
    return sum;
}
int main(){
    if (argc != 3) {
        cout << "please input command line arguments for m and n" << endl;
        return 1;
    }

    int m = stoi(argv[1]);
    int n = stoi(argv[2]);

    if (m != n){
        cout << "make sure m and n are equal so its a square matrix" << endl;
        return 1;
    }
    int m, n = 3;
    int** matrix = new int* [m];
    for (int i = 0; i < m; ++i){
        matrix[i] = new int[n];
    }
    matrixRandom(matrix, m, n);
    int sum = matrixDiagonal(matrix, 3);
    cout << sum << endl;


    // clear memory

}