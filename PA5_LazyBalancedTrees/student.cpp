#include "student.h"

student::student(){
    
}

student::student(int ID, string name, string level, string major, double GPA, int advisor){
    this->ID = ID;
    this->name = name;
    this->level = level;
    this->major = major;
    this->GPA = GPA;
    this->advisor = advisor;
}

student::~student(){

}

int student::getID(){
    return this->ID;
}

void student::changeID(int ID){
    this->ID = ID;
}

void student::changeAdvisor(int ID){
    this->advisor = ID;
}

string student::toString(){
    return "ID: " + to_string(this->ID) + "\nName: " + this->name + "\nLevel: " + this->level + "\nMajor: " + this->major + "\nGPA: " + to_string(this->GPA) + "\nadvisor " + to_string(this->advisor);
}

// comparison operator overloading
bool student::operator<(student stu){
    return this->ID < stu.getID();
}
bool student::operator>(student stu){
    return this->ID > stu.getID();
}
bool student::operator==(student stu){
    return this->ID == stu.getID();
}
ostream& operator<<(ostream& s, student& stu){
    return s << stu.toString();
}
