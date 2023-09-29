#include <iostream>
#include <cstdlib>
using namespace std;

/*
Write a C++ function, sumRows(), that takes a matrix of numbers 
(an array of arrays) and a one-dimensional array fill the array up with 
the sum of each row of the matrix. Make sure to use pointers! 
Then, create a main function where you ask for user input for 
the size of the matrix (rows & cols) and then ask the user for 
numbers to fill up the matrix. Call sumRows() and display the sums 
of each row to the user.
*/


// Write a C++ program that takes a matrix of numbers 
// and returns an array with the sum of each row of the matrix 
// use pointers!  

// function for summing rows of a 2D array 

void rowSums(int** matrix, int rows, int cols, int* sums){
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            sums[i] += matrix[i][j];
        }
    }
}

// main method  char** = array of strings
int main(int argc, char** argv) {  
    int rows, cols;
    // ask user for dimensions 
    //cout << "How many rows do you want? " << endl;
    //cin >> rows;
    //cout << "How many columns do you want? " << endl;
    //cin >> col;

    // using command line arguments instead of user input 
    cout << argv[0] << endl; // program name
    rows = stoi(argv[1]);
    cols = stoi(argv[2]);

    cout << "rows: " << rows << " " << "cols: " << cols << endl;


    // create matrix of appropriate dimensions
    int** matrix = new int* [rows]; // a pointer to a 1D array which has int pointers inside of it
    // populates the arrays of that each pointer is pointing to
    int val;
    for (int i = 0; i < rows; ++i){
        matrix[i] = new int[cols]; // allocating memory
        for (int j = 0; j < cols; ++j){
            cout << "Value for [" << i << "][" << j << "]" << endl;
            cin >> val;
            matrix[i][j] = val;
        }
    }



    // get the sums of the rows and save them into a new array 
    int* sums = new int[rows];
    rowSums(matrix, rows, cols, sums);
    cout << "Displaying Row Sums: ";
    for (int i = 0; i < rows; ++i){
        cout << sums[i] << " ";

    }
    cout << "done" << endl;
    // free up memory 
    delete[] sums;

    //deallocate a 2D array
    // first delete inner arrays
    for (int i = 0; i < rows; ++i){
        delete[] matrix[i];
    }
    // then you can delete the outer shell array
    delete[] matrix;
    
    return 0;
}