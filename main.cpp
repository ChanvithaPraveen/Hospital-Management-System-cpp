#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "Patient.h"
#include "Medicine.h"
#include "SystemAdministrator.h"

using namespace std;

void readData(Patient patients[], Medicine medicines[], int &numPatients, int &numMedicines, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> numPatients >> numMedicines;
        for (int i = 0; i < numPatients; i++) {
            file >> patients[i].name >> patients[i].age >> patients[i].illness;
        }
        for (int i = 0; i < numMedicines; i++) {
            string medicineName;
            int medicineDosage;
            file >> medicineName >> medicineDosage;
            // Set the values using the setter functions of Medicine
            medicines[i].setName(medicineName);
            medicines[i].setDosage(medicineDosage);
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

// Function to write data to file (pass by reference)
void writeData(Patient patients[], Medicine medicines[], int numPatients, int numMedicines, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << numPatients << " " << numMedicines << endl;
        for (int i = 0; i < numPatients; i++) {
            file << patients[i].name << " " << patients[i].age << " " << patients[i].illness << endl;
        }
        for (int i = 0; i < numMedicines; i++) {
            file << medicines[i].getName() << " " << medicines[i].getDosage() << endl;
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

// Function to display menu (void function)
void displayMenu() {
    cout << "\nHospital System Menu:\n";
    cout << "1. Add New Patient\n";
    cout << "2. Search Patient\n";
    cout << "3. Update Patient\n";
    cout << "4. Delete Patient\n";
    cout << "5. Sort Patients\n";
    cout << "6. Display Patients\n";
    cout << "7. Add New Medicine\n";
    cout << "8. Search Medicine\n";
    cout << "9. Update Medicine\n";
    cout << "10. Delete Medicine\n";
    cout << "11. Display Medicines\n";
    cout << "12. Exit\n";
    cout << "Enter your choice: ";
}

// Function to get user input (pass by value)
int getUserInput() {
    int choice;
    cin >> choice;
    return choice;
}

int main() {
    SystemAdministrator sysAd = SystemAdministrator();
    Medicine medi = Medicine();

    const int MAX_PATIENTS = 100; // Adjust size limit as needed
    const int MAX_MEDICINES = 50; // Adjust size limit as needed

    Patient patients[MAX_PATIENTS];
    Medicine medicines[MAX_MEDICINES];
    int numPatients = 0;
    int numMedicines = 0;

    // Read data from file
    readData(patients, medicines, numPatients, numMedicines, "patients.txt");

    int choice;
    do {
        displayMenu();
        choice = getUserInput();

        switch (choice) {
            case 1:
                sysAd.addPatient(patients, numPatients);
                break;
            case 2: {
                string name;
                cout << "Enter patient name to search: ";
                cin.ignore();
                getline(cin, name);
                int index = sysAd.searchPatient(patients, numPatients, name);
                if (index != -1) {
                    cout << "\nPatient Details:\n";
                    cout << "  Name: " << patients[index].name << endl;
                    cout << "  Age: " << patients[index].age << endl;
                    cout << "  Illness: " << patients[index].illness << endl;
                } else {
                    cout << "Patient not found!" << endl;
                }
                break;
            }
            case 3:
                sysAd.updatePatient(patients, numPatients);
                break;
            case 4:
                sysAd.deletePatient(patients, numPatients);
                break;
            case 5:
                sysAd.sortPatients(patients, numPatients);
                cout << "Patients sorted by name!" << endl;
                break;
            case 6:
                sysAd.displayPatients(patients, numPatients);
                break;
            case 7:
                sysAd.addMedicine(medicines, numMedicines);
                break;
            case 8: {
                string name;
                cout << "Enter medicine name to search: ";
                cin.ignore();
                getline(cin, name);
                int index = sysAd.searchMedicine(medicines, numMedicines, name);
                if (index != -1) {
                    cout << "\nMedicine Details:\n";
                    cout << "  Name: " << medicines[index].getName() << endl;
                    cout << "  Dosage: " << medicines[index].getDosage() << endl;
                } else {
                    cout << "Medicine not found!" << endl;
                }
                break;
            }
            case 9:
                sysAd.updateMedicine(medicines, numMedicines);
                break;
            case 10:
                sysAd.deleteMedicine(medicines, numMedicines);
                break;
            case 11:
                sysAd.displayMedicines(medicines, numMedicines);
                break;
            case 12:
                // Write data to file before exiting
                writeData(patients, medicines, numPatients, numMedicines, "patients.txt");
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 12);

    // Generate report at program exit
    time_t currentTime = time(0);
    sysAd.generateReport(numPatients, numMedicines, currentTime);

    return 0;
}
