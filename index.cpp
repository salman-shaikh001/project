#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

// Structure (Lab 10)
struct Appliance {
    string name;
    float power;      // in watts
    float hours;
    int category;     // 1-Light, 2-Fan, 3-AC, 4-Fridge, 5-Other
};

// Function prototypes (Lab 13)
void addAppliance(Appliance[], int& );
void displayAppliances(Appliance[], int);
float calculateBill(Appliance[], int, float&, float&, float&);
void saveBill(string, float, float, float, float);
void viewPastBills();
bool recursiveSearch(int, int, string);  // Lab 12 - Recursion

int main() {
    Appliance home[20];
    int count = 0;
    string month;
    float units, charges, tax, total;
    int choice;

    cout << "\n\t\t SMART HOME ENERGY MANAGEMENT SYSTEM \n";
    cout << "\t\t       (EE Department Project)       \n";
    cout << "==============================================\n\n";

    // Simple login (Lab 4)
    string password;
    int attempts = 3;
    do {
        cout << "Enter password (1234): ";
        cin >> password;
        if (password == "1234") break;
        attempts--;
        cout << "Wrong! " << attempts << " attempts left.\n";
    } while (attempts > 0);

    if (attempts == 0) {
        cout << "Access Denied!\n";
        return 0;
    }

    cout << "\nLogin Successful! Welcome!\n\n";
    cout << "Enter Current Month (e.g., November-2025): ";
    cin.ignore();
    getline(cin, month);

    do {
        cout << "\n================ MENU ================\n";
        cout << "1. Add Appliance\n";
        cout << "2. View All Appliances\n";
        cout << "3. Calculate & Save Monthly Bill\n";
        cout << "4. View Past Bills\n";
        cout << "5. Search Bill (Recursive)\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {  // Lab 5
            case 1:
                addAppliance(home, count);
                break;
            case 2:
                displayAppliances(home, count);
                break;
            case 3:
                total = calculateBill(home, count, units, charges, tax);
                saveBill(month, units, charges, tax, total);
                break;
            case 4:
                viewPastBills();
                break;
            case 5: {
                string searchMonth;
                cout << "Enter month to search: ";
                cin.ignore();
                getline(cin, searchMonth);
                if (recursiveSearch(1, 100, searchMonth))
                    cout << "Record Found!\n";
                else
                    cout << "Not Found!\n";
                break;
            }
            case 6:
                cout << "Thank you! Project by [Your Name]\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

// Function definitions below...
void addAppliance(Appliance list[], int &n) {
    if (n >= 20) {
        cout << "Memory Full!\n";
        return;
    }
    cout << "\n--- Add Appliance " << n+1 << " ---\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, list[n].name);
    cout << "Power (Watts): ";
    cin >> list[n].power;
    cout << "Hours used per day: ";
    cin >> list[n].hours;
    cout << "Category [1-Light 2-Fan 3-AC 4-Fridge 5-Other]: ";
    cin >> list[n].category;
    n++;
    cout << "Appliance Added!\n";
}

void displayAppliances(Appliance list[], int n) {
    // ... (same as previous version - I'll give full code in final file)
}

// I will now give you the COMPLETE 100% working code with all functions + file handling + recursion in the next message because it's long.
