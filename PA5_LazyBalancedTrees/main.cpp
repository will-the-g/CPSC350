#include "BST.h"
#include <iostream>
#include "student.h"
#include "faculty.h"
using namespace std;

// function to check if a string is a integer.
bool idCheck(string idStr){
    int id;
    try{
        id = stoi(idStr);
    }catch(const invalid_argument &){
        cout << "Please enter a number" << endl;
        return false;
    }
    // checks if the id is greater than 0
    if(id < 0){
        cout << "Please enter a number greater than or equal to 0" << endl;
        return false;
    }
    return true;
}




int main(){
    // tables
    BST<student> students;
    BST<faculty> faculties;
    // variable initilizations
    
    // tempStu and tempFac are temperorary objects that are created to lookup nodes in the BST, since only the IDs are compared, I only need temp objects with just IDs.
    student tempStu;
    faculty tempFac;
    // students
    string placeholder;
    string optionS;
    int id;
    string idStr;
    string name;
    string level;
    string major;
    string GPAStr;
    double GPA;
    string advisor;
    int advisorID;
    // additional faculty
    string department;
    int* advisees;
    int facID;
    while (true){
        int option;
        cout << "------------------------------------------------" << endl;
        cout << "1. Print all students and their information (in ascending id #)." << endl;
        cout << "2. Print all faculty and their information (in ascending id #)." << endl;
        cout << "3. Find and display a student's information given their id. " << endl;
        cout << "4. Find and display a faculty's information given their id. " << endl;
        cout << "5. Add a new student. " << endl;
        cout << "6. Delete a student given their id. " << endl;
        cout << "7. Add a new faculty member. " << endl;
        cout << "8. Delete a faculty member given their id. " << endl;
        cout << "9. Change a student’s advisor given the student id and the new faculty id. " << endl;
        cout << "10. Remove an advisee from a faculty member given the ids. " << endl;
        cout << "11. Exit. " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Please choose an option: ";
        cin >> optionS;
        // changes it to integer, if its not an integer it changed option to 0 to set off the default case.
        try{
            option = stoi(optionS);
        }catch(const invalid_argument &){
            option = 0;
        }
        cout << endl;

        switch(option){
            case 1:
                students.printInOrder();
                break;
            case 2:
                faculties.printInOrder();
                break;
            case 3:
                getline(cin, placeholder);
                getline(cin, idStr);
                // checks if a integer
                if (idCheck(idStr)){
                    id = stoi(idStr);
                }else{
                    break;
                }
                tempStu = student();
                tempStu.changeID(id);
                if (students.contains(tempStu)){ // checks if the BST contains the node
                    student stu;
                    stu = students.find(tempStu); // returns the node from the BST
                    cout << stu.toString() << endl; // converts to string for printing
                }else{
                    cout << "Student ID does not exist!" << endl;
                }
                break;
            case 4: 
                getline(cin, placeholder);
                cout << "Enter the faculty ID: ";
                getline(cin, idStr);
                // checks if it's a number
                if (idCheck(idStr)){
                    id = stoi(idStr);
                }else{
                    break;
                }
                tempFac = faculty();
                tempFac.changeID(id);
                if (faculties.contains(tempFac)){ // checks if the BST contains the node
                    faculty fac;
                    fac = faculties.find(tempFac); // returns the node from the BST
                    cout << fac.toString() << endl; // converts to string for printing
                }else{
                    cout << "Faculty ID does not exist!" << endl;
                }
                break;
            case 5:
                getline(cin, placeholder);
                cout << "Enter the student ID: ";
                getline(cin, idStr);
                // check if its a number
                if (idCheck(idStr)){
                    id = stoi(idStr);
                }else{
                    break;
                }
                // checks if the id already exists
                tempStu = student();
                tempStu.changeID(id);
                if (students.contains(tempStu)){
                    cout << "ID has already been assigned to another student." << endl;
                    break;
                }
                cout << "Enter the student's name: ";
                getline(cin, name);
                cout << "Enter the student's level: ";
                getline(cin, level);
                cout << "Enter the student's major: ";
                getline(cin, major);
                cout << "Enter the student's GPA: ";
                getline(cin, GPAStr);
                // checks if the gpa is a double
                try{
                    GPA = stod(GPAStr);
                } catch(const invalid_argument &){
                    cout << "You did not enter a double for the GPA." << endl;
                    break;
                }
                if (GPA < 0.0 || GPA > 4.0){
                    cout << "GPA must be between 0.0 and 4.0" << endl;
                    break;
                }
                cout << "Enter the student's advisor's faculty ID: ";
                getline(cin, advisor);
                // checks if the advisor exists
                if (idCheck(advisor)){
                    advisorID = stoi(advisor);
                }else{
                    break;
                }
                tempFac = faculty();
                tempFac.changeID(advisorID);
                if (!faculties.contains(tempFac)){
                    cout << "Faculty ID does not exist" << endl;
                    break;
                }
                tempStu = student(id, name, level, major, GPA, advisorID);
                students.insert(tempStu);
                cout << "Student " << id << " Added." << endl;
                break;
            case 6:
                getline(cin, placeholder);
                cout << "Enter the ID of the student you want to delete: ";
                getline(cin, idStr);
                if (idCheck(idStr)){
                    id = stoi(idStr);
                }else{
                    break;
                }
                tempStu = student();
                tempStu.changeID(id);
                if (students.contains(tempStu)){
                    students.remove(tempStu);
                    if (!students.contains(tempStu)){
                        cout << "Student Deleted" << endl;
                    }
                }else{
                    cout << "Student does not exist." << endl;
                    break;
                }
                break;
            case 7: 
                getline(cin, placeholder); // clears inputs
                cout << "Enter the faculty ID: ";
                getline(cin, idStr);
                // checks if id is a number
                if (idCheck(idStr)){
                    id = stoi(idStr);
                }else{
                    break;
                }
                tempFac = faculty();
                tempFac.changeID(id);
                if (faculties.contains(tempFac)){
                    cout << "Faculty ID has already been assigned" << endl;
                    break;
                }
                cout << "Enter the faculty's name: ";
                getline(cin, name);
                cout << "Enter the faculty's level: ";
                getline(cin, level);
                cout << "Enter the faculty's department: ";
                getline(cin, department);
                tempFac = faculty(id, name, level, department, advisees);
                faculties.insert(tempFac);
                cout << "Faculty " << id << " added!" << endl;
                break;
            case 8:
                getline(cin, placeholder);
                cout << "Enter the faculty ID: ";
                getline(cin, idStr);
                if (idCheck(idStr)){
                    id = stoi(idStr);
                }else{
                    break;
                }
                tempFac = faculty();
                tempFac.changeID(id);
                if (faculties.contains(tempFac)){ // checks if faculty is in BST
                    faculties.remove(tempFac); // removes faculty
                    if (!faculties.contains(tempFac)){ // checks if it exists to see if it's really been removed
                        cout << "Faculty Deleted" << endl;
                    }
                }else{
                    cout << "Faculty ID does not exist." << endl;
                    break;
                }
                break;
            case 9:
                getline(cin, placeholder);
                cout << "Enter the student's ID: ";
                getline(cin, idStr);
                if (idCheck(idStr)){
                    id = stoi(idStr);
                }else{
                    break;
                }
                cout << "Enter the Faculty's ID: ";
                getline(cin, idStr);
                // checks if its a number
                if (idCheck(idStr)){
                    facID = stoi(idStr);
                }else{
                    break;
                }
                tempFac = faculty();
                tempFac.changeID(facID);
                if (!faculties.contains(tempFac)){
                    cout << "Faculty ID does not exist." << endl;
                    break;
                }
                tempStu = student();
                tempStu.changeID(id);
                if (students.contains(tempStu)){ // checks if the BST has the student
                    student stu;
                    stu = students.find(tempStu); // creates a copy of the student node from the BST
                    stu.changeAdvisor(facID); // changes the student's advisor
                    students.changeData(stu); // overwrites the node in the BST with the changed copy node's data
                    faculty fac;
                    fac = faculties.find(tempFac); // creates copy of faculty node from BST
                    fac.addAdvisee(id); // adds advisee to copy
                    faculties.changeData(fac); // overwrites node in BST with the changed copy
                }else{
                    cout << "Student ID does not exist." << endl;
                    break;
                }
                cout << "Student " << id << "'s advisor changed to " << facID << endl;
                break;
            case 10:
                getline(cin, placeholder);
                cout << "Enter the Faculty's ID: ";
                getline(cin, idStr);
                // checks if its a number
                if (idCheck(idStr)){
                    facID = stoi(idStr);
                }else{
                    break;
                }
                tempFac = faculty();
                tempFac.changeID(facID);
                if (!faculties.contains(tempFac)){
                    cout << "Faculty ID does not exist" << endl;
                    break;
                }else{
                    faculty fac;
                    fac = faculties.find(tempFac);
                    cout << fac.listAdvisee() << endl;
                    cout << "Enter the student's ID: ";
                    getline(cin, idStr);
                    if (idCheck(idStr)){
                        id = stoi(idStr);
                    }else{
                        break;
                    }
                    if (fac.removeAdvisee(id)){
                        cout << "Advisee removed. " << endl;
                    }else{
                        cout << "Student is not an advisee of this faculty" << endl;
                    }
                }
                break;
            case 11:
                exit(0);
                break;
            default:
                cout << "That is not an option. Please choose a number 1 - 11." << endl;
                break;
        }
    }







    return 0;
}







