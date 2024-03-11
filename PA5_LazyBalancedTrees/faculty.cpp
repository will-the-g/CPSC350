#include "faculty.h"


faculty::faculty(){
    this->advisees = new int[10];
    this->arrCount = 0;
    this->arrSize = 10;
}

faculty::faculty(int ID, string name, string level, string department, int* advisees){
    this->ID = ID;
    this->name = name;
    this->level = level;
    this->department = department;
    this->advisees = new int[10];
    this->arrCount = 0;
    this->arrSize = 10;

}

faculty::~faculty(){}

int faculty::getID(){
    return this->ID;
}

void faculty::changeID(int ID){
    this->ID = ID;
}

void faculty::addAdvisee(int ID){
    // if the count is larger than the size then it will check for empty spots or resize
    if (arrCount > arrSize){
        for (int i = 0; i < arrSize; i++){ // removed spots were replaced with -1, so it will check those to readd
            if (this->advisees[i] = -1){
                this->advisees[i] = ID;
                return;
            }
        }
        // since all spots are full it will resize the array to double
        int* newArr = new int[this->arrSize * 2];
        for (int i = 0; i < this->arrSize; i++){
            newArr[i] = this->advisees[i];
        }
        this->advisees = newArr;
        this->arrSize *= 2;
        this->advisees[this->arrCount] = ID;
        this->arrCount++;

    }else{
        this->advisees[this->arrCount] = ID;
        this->arrCount++;
    }
    
}

bool faculty::removeAdvisee(int ID){

    for (int i = 0; i < this->arrCount; i++){
        if (this->advisees[i] == ID){
            this->advisees[i] == -1;
            return true;
        }
    }
    return false;
}

string faculty::listAdvisee(){
    string list = "List of Advisees: ";
    for (int i = 0; i < this->arrCount; i++){
        if (this->advisees[i] != -1){
            list += (to_string(this->advisees[i]) + ", ");
        }
    }
    return list;
}

string faculty::toString(){
    string temp = "ID: " + to_string(this->ID) + "\nName: " + this->name + "\nLevel: " + this->level + "\nDepartment: " + this->department + "\nAdvisees: "; 
    if (this->advisees != NULL){
        for (int i = 0; i < arrCount; i++){
            temp += to_string(this->advisees[i]);
        }
    }

    return temp;
}

// comparison opreator overloading
bool faculty::operator<(faculty fac){
    return this->ID < fac.getID();
}
bool faculty::operator>(faculty fac){
    return this->ID > fac.getID();
}
bool faculty::operator==(faculty fac){
    return this->ID == fac.getID();
}

ostream& operator<<(ostream& s, faculty& fac){
    return s << fac.toString();
}