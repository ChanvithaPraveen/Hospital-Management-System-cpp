//
// Created by Chanvitha on 4/29/2024.
//

#include <string>

#include "Patient.h"

using namespace std;

Patient::Patient() {

}

Patient::Patient(std::string name, int age, std::string illness) {

}

string &Patient::getName() {
    return name;
}

void Patient::setName(string &name) {
    Patient::name = name;
}

int Patient::getAge() {
    return age;
}

void Patient::setAge(int age) {
    Patient::age = age;
}

string &Patient::getIllness() {
    return illness;
}

void Patient::setIllness(string &illness) {
    Patient::illness = illness;
}