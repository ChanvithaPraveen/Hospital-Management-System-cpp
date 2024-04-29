//
// Created by Chanvitha on 4/29/2024.
//

#ifndef C___ASSIGNMENT_SYSTEM_H
#define C___ASSIGNMENT_SYSTEM_H

class System {
public:
    void readData(Patient patients[], Medicine medicines[], int &numPatients, int &numMedicines, const string& filename);
    void writeData(Patient patients[], Medicine medicines[], int numPatients, int numMedicines, const string& filename);
    void displayMenu();
    int getUserInput();
    void runner();
};

#endif //C___ASSIGNMENT_SYSTEM_H
