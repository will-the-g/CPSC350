#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

class student{
    public:
        student();
        student(int ID, string name, string level, string major, double GPA, int advisor);
        ~student();
        int getID();
        void changeID(int ID);
        void changeAdvisor(int ID);
        string toString();
        bool operator<(student stu);
        bool operator>(student stu);
        bool operator==(student stu);
        friend ostream& operator<<(ostream& s, student& stu);
    private:
        int ID;
        string name;
        string level;
        string major;
        double GPA;
        int advisor;



};

#endif