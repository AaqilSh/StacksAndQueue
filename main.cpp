#include <iostream>
#include "Portfolio.h"

using namespace std;

int main() {
    Portfolio portfolio;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter stock performance\n";
        cout << "2. Find Stock\n";
        cout << "3. Set up Test Data\n";
        cout << "4. Show stock portfolio\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            double percent;
            cout << "Enter stock name: ";
            cin >> name;
            cout << "Enter percentage change: ";
            cin >> percent;
            portfolio.processStockPerformance(name, percent);
        } else if (choice == 2) {
            string name;
            cout << "Enter stock name: ";
            cin >> name;
            portfolio.displayStockDetails(name);
        } else if (choice == 3) {
            portfolio.loadTestData();
        } else if (choice == 4) {
            portfolio.displayPortfolio();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid option. Please Try again.\n";
        }
    }

    return 0;
}
