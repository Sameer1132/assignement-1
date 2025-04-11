#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    string name;
    int priority;

    // Operator overloading for priority comparison
    bool operator<(const Patient& other) const {
        return priority > other.priority; // Min-heap behavior
    }
};

priority_queue<Patient> treatmentQueue;

void addPatient() {
    Patient p;

    cout << "Enter patient name: ";
    cin.ignore(); // Clear newline before getline
    getline(cin, p.name);

    cout << "Emergency condition (1. Critical, 2. Serious, 3. Normal): ";
    int condition;
    cin >> condition;

    switch(condition) {
        case 1: p.priority = 1; break;
        case 2: p.priority = 2; break;
        case 3: p.priority = 3; break;
        default:
            cout << "Invalid condition! Assigning lowest priority.\n";
            p.priority = 3;
    }

    treatmentQueue.push(p);
    cout << "Patient added successfully.\n\n";
}

void printTreatmentOrder() {
    if (treatmentQueue.empty()) {
        cout << "No patients in queue.\n\n";
        return;
    }

    cout << "Current Treatment Order:\n";
    priority_queue<Patient> tempQueue = treatmentQueue;
    int order = 1;
    while (!tempQueue.empty()) {
        Patient p = tempQueue.top();
        cout << order++ << ". " << p.name << " (Priority: " << p.priority << ")\n";
        tempQueue.pop();
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- Hospital Priority Queue System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Show Treatment Order\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addPatient(); break;
            case 2: printTreatmentOrder(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 3);

    return 0;
}
