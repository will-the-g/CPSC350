#include <iostream>
#include "DblList.h"
using namespace std;

int main(){
   
    DblList<int> myList;
    for(int i = 0; i < 10; ++i){
        myList.add(i,i);
    }

    myList.add(5,222);
    myList.addFront(14);
    myList.addBack(28);

    for(int i = 0; i < myList.size(); ++i){
        cout << myList.get(i) << endl;
    }

    cout << "===============" << endl;

    myList.removeFront();
    myList.removeBack();
    myList.remove(5);

    for(int i = 0; i < myList.size(); ++i){
        cout << myList.get(i) << endl;
    }
}