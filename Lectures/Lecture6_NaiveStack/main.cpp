#include "NaiveCharStack.h"
#include <iostream>
using namespace std;

int main(){
    NaiveCharStack myStack(10); // created in the stack since theres no "new"
    myStack.push('h');
    myStack.push('e');
    myStack.push('l');
    myStack.push('l');
    myStack.push('o');

    cout << myStack.size() << endl << endl;
    cout << myStack.peek() << endl << endl;;

    while(!myStack.isEmpty()){
        cout << myStack.pop() << endl;
    }
    
    cout << endl;
    cout << myStack.size() << endl;
    cout << endl;
    
    return 0;
}