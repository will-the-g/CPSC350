
#include <iostream>
using namespace std;

int simpleSearch(int* arr, int len, int key){
    int idx;
    int comparisons = 0;
    for (int i = 0; i < len; i++){
        ++comparisons;
        if (arr[i] == key){
            idx = i;
            break;
        }
    }
    cout << "I did " << comparisons << " comparisons in this simple search";
    return idx;
}

int binarySearch(int* arr, int len, int key){
    int idx = -1;
    int comparisons = 0;
    int right = len;
    int left = 0;

    while (right >= left){
        ++comparisons;
        int middle = (right + left) / 2; // find / update middle
        if (arr[middle] == key){
            // we found the key
            idx = middle;
            break;
        }
        if (key < arr[middle]){
            // keep left, change right
            right = middle - 1;
        } else{
            // keep right, change left
            left = middle + 1;
        }
    }
    cout << "I did " << comparisons << " comparisons in this binary search";
}

int main(){
    cout << "Populating array." << endl;
    int len = 10000000;
    int key = 800000;

    int* myArr = new int[len];
    for (int i = 0; i < len; ++i){
        myArr[i] = i*2;
    }
    cout << "Starting simple search..." << endl;
    cout << "Found the key " << key << " at index " << simpleSearch(myArr, len, key) << endl;
    cout << "Ending simple search..." << endl;

    cout << "Starting binary search..." << endl;
    cout << "Found the key " << key << " at index " << binarySearch(myArr, len, key) << endl;
    cout << "Ending binary search..." << endl;

    delete[] myArr; // clean up after yourself :) 
    return 0;
}