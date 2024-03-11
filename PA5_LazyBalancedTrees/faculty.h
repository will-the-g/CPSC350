#ifndef FACULTY_H
#define FACULTY_H
#include <string>
using namespace std;

class faculty{
    public:
        faculty();
        faculty(int ID, string name, string level, string department, int* advisees);
        ~faculty();
        int getID();
        void changeID(int ID);
        void addAdvisee(int ID);
        bool removeAdvisee(int ID);
        string listAdvisee();
        string toString();
        bool operator<(faculty fac);
        bool operator>(faculty fac);
        bool operator==(faculty fac);
        friend ostream& operator<<(ostream& s, faculty& fac);
    private:
        int ID;
        string name;
        string level;
        string department;
        int* advisees;
        int arrCount;
        int arrSize;

};
#endif