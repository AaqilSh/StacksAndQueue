#include <iostream>
#include "Portfolio.h"

using namespace std;

int main() {
    Portfolio portfolio;
    int option;

    do {
        cout << "\n--- Stock Portfolio Menu ---\n";
        cout << "1. Enter Stock Performance\n";
        cout << "2. Find Stock\n";
        cout << "3. Set Up Test Data\n";
        cout << "4. Show Stock Portfolio\n";
        cout << "0. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1: {
                string name;
                double change;
                cout << "Enter stock name: ";
                cin >> name;
                cout << "Enter percentage change: ";
                cin >> change;
                portfolio.handlePerformance(name, change);
                break;
            }
            case 2: {
                string name;
                cout << "Enter stock name to find: ";
                cin >> name;
                portfolio.findStock(name);
                break;
            }
            case 3:
                portfolio.setupTestData();
                break;
            case 4:
                portfolio.showPortfolio();
                break;
            case 0:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (option != 0);

    return 0;
}
