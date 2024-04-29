//
// Created by Chanvitha on 4/29/2024.
//

#ifndef C___ASSIGNMENT_SYSTEMADMINISTRATOR_H
#define C___ASSIGNMENT_SYSTEMADMINISTRATOR_H

#include <iostream>
#include <string>

#include "Patient.h"
#include "Medicine.h"

using namespace std;

class SystemAdministrator {

public:
    void addPatient(Patient patients[], int &numPatients);
    int searchPatient(Patient patients[], int numPatients, const string& name);
    void updatePatient(Patient patients[], int numPatients);
    void deletePatient(Patient patients[], int &numPatients);
    void sortPatients(Patient patients[], int numPatients);
    void displayPatients(Patient patients[], int numPatients);

    void addMedicine(Medicine medicines[], int &numMedicines);
    int searchMedicine(Medicine medicines[], int numMedicines, const string& name);
    void updateMedicine(Medicine medicines[], int numMedicines);
    void deleteMedicine(Medicine medicines[], int &numMedicines);
    void displayMedicines(Medicine medicines[], int numMedicines);
    void generateReport(int numPatients, int numMedicines, const time_t& currentTime);
};

#endif //C___ASSIGNMENT_SYSTEMADMINISTRATOR_H
