//
// Created by Chanvitha on 4/29/2024.
//

#ifndef C___ASSIGNMENT_MEDICINE_H
#define C___ASSIGNMENT_MEDICINE_H

#include <iostream>
#include <string>

using namespace std;

struct Medicine {
private:
    string name;
    int dosage;
public:
    Medicine();
    Medicine(string name, int dosage);
    virtual ~Medicine();

    string &getName();
    void setName(string &name);
    int getDosage();
    void setDosage(int dosage);
};

#endif //C___ASSIGNMENT_MEDICINE_H
