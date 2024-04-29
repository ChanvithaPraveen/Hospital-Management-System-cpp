//
// Created by Chanvitha on 4/29/2024.
//

#include <string>

#include "Medicine.h"

using namespace std;

Medicine::Medicine() {

}

Medicine::Medicine(string name, int dosage) {
    this->setName(name);
    this->setDosage(dosage);
}

Medicine::~Medicine() {

}

string &Medicine::getName() {
    return name;
}

void Medicine::setName(string &name) {
    Medicine::name = name;
}

int Medicine::getDosage() {
    return dosage;
}

void Medicine::setDosage(int dosage) {
    Medicine::dosage = dosage;
}




