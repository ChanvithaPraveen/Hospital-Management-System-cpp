//
// Created by Chanvitha on 4/29/2024.
//

#ifndef C___ASSIGNMENT_PATIENT_H
#define C___ASSIGNMENT_PATIENT_H

#include <iostream>
#include <string>

using namespace std;

struct Patient {
private:
    string name;
    int age;
    string illness;

public:
    Patient();
    Patient(string name, int age, string illness);

    string &getName();
    void setName(string &name);
    int getAge();
    void setAge(int age);
    string &getIllness();
    void setIllness(string &illness);
};

#endif //C___ASSIGNMENT_PATIENT_H
