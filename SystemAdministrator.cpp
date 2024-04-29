//
// Created by Chanvitha on 4/29/2024.
//

#include <iostream>
#include <string>
#include <fstream>

#include "SystemAdministrator.h"
#include "Medicine.h"

using namespace std;

// Function to add new patient (void function)
void SystemAdministrator::addPatient(Patient patients[], int &numPatients) {
    if (numPatients == 100) { // Adjust size limit as needed
        cout << "Patient list is full!" << endl;
        return;
    }
    cout << "Enter patient name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, patients[numPatients].name);
    cout << "Enter patient age: ";
    cin >> patients[numPatients].age;
    cout << "Enter patient illness: ";
    cin.ignore();
    getline(cin, patients[numPatients].illness);
    numPatients++;
    cout << "Patient added successfully!" << endl;
}

// Function to search for patient (pass by value)
int SystemAdministrator::searchPatient(Patient patients[], int numPatients, const string& name) {
    for (int i = 0; i < numPatients; i++) {
        if (patients[i].name == name) {
            return i;
        }
    }
    return -1;
}

// Function to update patient (void function)
void SystemAdministrator::updatePatient(Patient patients[], int numPatients) {
    string name;
    int index;
    cout << "Enter patient name to update: ";
    cin.ignore();
    getline(cin, name);
    index = searchPatient(patients, numPatients, name);
    if (index == -1) {
        cout << "Patient not found!" << endl;
        return;
    }

    cout << "Update patient details:\n";
    cout << "  Name: " << patients[index].name << endl;
    cout << "  Age: " << patients[index].age << endl;
    cout << "  Illness: " << patients[index].illness << endl;

    cout << "Enter new name (leave blank to keep unchanged): ";
    cin.ignore();
    getline(cin, name);
    if (!name.empty()) {
        patients[index].name = name;
    }

    cout << "Enter new age (enter -1 to keep unchanged): ";
    int newAge;
    cin >> newAge;
    if (newAge != -1) {
        patients[index].age = newAge;
    }
    cin.ignore(); // Clear input buffer

    cout << "Enter new illness (leave blank to keep unchanged): ";
    getline(cin, name);
    if (!name.empty()) {
        patients[index].illness = name;
    }

    cout << "Patient updated successfully!" << endl;
}

// Function to delete patient (void function)
void SystemAdministrator::deletePatient(Patient patients[], int &numPatients) {
    string name;
    int index;
    cout << "Enter patient name to delete: ";
    cin.ignore();
    getline(cin, name);
    index = searchPatient(patients, numPatients, name);
    if (index == -1) {
        cout << "Patient not found!" << endl;
        return;
    }

    // Shift elements to remove deleted patient
    for (int i = index; i < numPatients - 1; i++) {
        patients[i] = patients[i + 1];
    }
    numPatients--;
    cout << "Patient deleted successfully!" << endl;
}

// Function to sort patients by name (void function)
void SystemAdministrator::sortPatients(Patient patients[], int numPatients) {
    for (int i = 0; i < numPatients - 1; i++) {
        for (int j = i + 1; j < numPatients; j++) {
            if (patients[i].name > patients[j].name) {
                swap(patients[i], patients[j]);
            }
        }
    }
}

// Function to display patients (void function)
void SystemAdministrator::displayPatients(Patient patients[], int numPatients) {
    if (numPatients == 0) {
        cout << "No patients found!" << endl;
        return;
    }
    cout << "\nPatient List:\n";
    for (int i = 0; i < numPatients; i++) {
        cout << "  Name: " << patients[i].name << endl;
        cout << "  Age: " << patients[i].age << endl;
        cout << "  Illness: " << patients[i].illness << endl << endl;
    }
}

// Function to add new medicine (void function)
void SystemAdministrator::addMedicine(Medicine medicines[], int &numMedicines) {
    if (numMedicines == 50) { // Adjust size limit as needed
        cout << "Medicine list is full!" << endl;
        return;
    }
    cout << "Enter medicine name: ";
    cin.ignore(); // Clear input buffer
    string name;
    getline(cin, name);
    medicines[numMedicines].setName(name); // Set the name using the setter function
    cout << "Enter medicine dosage: ";
    string dosageStr;
    getline(cin, dosageStr);
    // Convert dosage string to integer and set the dosage using the setter function
    medicines[numMedicines].setDosage(stoi(dosageStr));
    numMedicines++;
    cout << "Medicine added successfully!" << endl;
}

// Function to search for medicine (pass by value)
int SystemAdministrator::searchMedicine(Medicine medicines[], int numMedicines, const string& name) {
    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

// Function to update medicine (void function)
void SystemAdministrator::updateMedicine(Medicine medicines[], int numMedicines) {
    string name;
    int index;
    cout << "Enter medicine name to update: ";
    cin.ignore();
    getline(cin, name);
    index = searchMedicine(medicines, numMedicines, name);
    if (index == -1) {
        cout << "Medicine not found!" << endl;
        return;
    }

    cout << "Update medicine details:\n";
    cout << "  Name: " << medicines[index].getName() << endl;
    cout << "  Dosage: " << medicines[index].getDosage() << endl;

    cout << "Enter new name (leave blank to keep unchanged): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty()) {
        medicines[index].setName(newName); // Set the name using the setter function
    }

    cout << "Enter new dosage (leave blank to keep unchanged): ";
    string newDosageStr;
    getline(cin, newDosageStr);
    if (!newDosageStr.empty()) {
        // Convert dosage string to integer and set the dosage using the setter function
        medicines[index].setDosage(stoi(newDosageStr));
    }

    cout << "Medicine updated successfully!" << endl;
}



// Function to delete medicine (void function)
void SystemAdministrator::deleteMedicine(Medicine medicines[], int &numMedicines) {
    string name;
    int index;
    cout << "Enter medicine name to delete: ";
    cin.ignore();
    getline(cin, name);
    index = searchMedicine(medicines, numMedicines, name);
    if (index == -1) {
        cout << "Medicine not found!" << endl;
        return;
    }

    // Shift elements to remove deleted medicine
    for (int i = index; i < numMedicines - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    numMedicines--;
    cout << "Medicine deleted successfully!" << endl;
}

// Function to display medicines (void function)
void SystemAdministrator::displayMedicines(Medicine medicines[], int numMedicines) {
    if (numMedicines == 0) {
        cout << "No medicines found!" << endl;
        return;
    }
    cout << "\nMedicine List:\n";
    for (int i = 0; i < numMedicines; i++) {
        cout << "  Name: " << medicines[i].getName() << endl;
        cout << "  Dosage: " << medicines[i].getDosage() << endl << endl;
    }
}

// Function to generate statistics report (void function)
void SystemAdministrator::generateReport(int numPatients, int numMedicines, const time_t& currentTime) {
    struct tm* localTime = localtime(&currentTime);

    ofstream reportFile("hospital_report.txt");
    if (reportFile.is_open()) {
        reportFile << "Hospital System Report\n";
        reportFile << "Date: " << localTime->tm_mday << "/" << localTime->tm_mon + 1 << "/" << localTime->tm_year + 1900 << endl;
        reportFile << "Time: " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << endl;
        reportFile << "Number of Patients: " << numPatients << endl;
        reportFile << "Number of Medicines: " << numMedicines << endl;
        reportFile.close();
        cout << "Report generated successfully!" << endl;
    } else {
        cout << "Error opening report file!" << endl;
    }
}


