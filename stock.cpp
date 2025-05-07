#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Stock {
    string stock_name;
    int number_of_shares;
    double price_per_share;
};

vector<Stock> portfolio;

void showPortfolio() {
    if (portfolio.empty()) {
        cout << "Portfolio is empty.\n";
        return;
    }

    cout << "\nCurrent Portfolio:\n";
    for (const auto& stock : portfolio) {
        cout << stock.stock_name << " | " << stock.number_of_shares << " shares @ £" 
             << fixed << setprecision(2) << stock.price_per_share << endl;
    }
    cout << endl;
}

void findStock(const string& name) {
    bool found = false;
    for (const auto& stock : portfolio) {
        if (stock.stock_name == name) {
            cout << stock.stock_name << " | " << stock.number_of_shares << " shares @ £" 
                 << fixed << setprecision(2) << stock.price_per_share << endl;
            found = true;
        }
    }
    if (!found) cout << "Stock not found in portfolio.\n";
}

void buyStock(const string& name) {
    int shares;
    double price;
    cout << "Enter number of shares to buy: ";
    cin >> shares;
    if (shares <= 0) {
        cout << "Invalid number of shares.\n";
        return;
    }
    cout << "Enter price per share: ";
    cin >> price;
    if (price <= 0) {
        cout << "Invalid price.\n";
        return;
    }
    portfolio.push_back({name, shares, price});
    cout << "Shares bought successfully.\n";
}

void sellStockFIFO(const string& name, int shares_to_sell) {
    int remaining = shares_to_sell;

    for (size_t i = 0; i < portfolio.size(); ++i) {
        if (portfolio[i].stock_name == name) {
            if (portfolio[i].number_of_shares >= remaining) {
                portfolio[i].number_of_shares -= remaining;
                if (portfolio[i].number_of_shares == 0) portfolio.erase(portfolio.begin() + i);
                cout << "Sold " << shares_to_sell << " shares (FIFO).\n";
                return;
            } else {
                remaining -= portfolio[i].number_of_shares;
                portfolio.erase(portfolio.begin() + i);
                i--;  // Adjust index after erase
            }
        }
    }

    cout << "Error: Not enough shares to sell.\n";
}

void sellStockLIFO(const string& name, int shares_to_sell) {
    int remaining = shares_to_sell;

    for (int i = portfolio.size() - 1; i >= 0; --i) {
        if (portfolio[i].stock_name == name) {
            if (portfolio[i].number_of_shares >= remaining) {
                portfolio[i].number_of_shares -= remaining;
                if (portfolio[i].number_of_shares == 0) portfolio.erase(portfolio.begin() + i);
                cout << "Sold " << shares_to_sell << " shares (LIFO).\n";
                return;
            } else {
                remaining -= portfolio[i].number_of_shares;
                portfolio.erase(portfolio.begin() + i);
            }
        }
    }

    cout << "Error: Not enough shares to sell.\n";
}

void enterStockPerformance() {
    string name;
    double change;
    cout << "Enter stock name: ";
    cin >> name;
    cout << "Enter percentage change (Please include + or - for positive or negative changes. e.g. +8.5 or -2.3): ";
    cin >> change;

    if (change >= 5.0 && change <= 20.0) {
        int total_shares = 0;
        for (const auto& stock : portfolio)
            if (stock.stock_name == name)
                total_shares += stock.number_of_shares;
        if (total_shares == 0) {
            cout << "No shares available to sell.\n";
            return;
        }
        sellStockFIFO(name, min(total_shares, 300));  // Sell up to 300 from FIFO
    } else if (change >= -1.0 && change <= -0.5) {
        buyStock(name);  // Buy more
    } else if (change >= -3.0 && change <= -1.1) {
        int total_shares = 0;
        for (const auto& stock : portfolio)
            if (stock.stock_name == name)
                total_shares += stock.number_of_shares;
        if (total_shares == 0) {
            cout << "No shares available to sell.\n";
            return;
        }
        sellStockLIFO(name, min(total_shares, 250));  // Sell up to 250 from LIFO
    } else {
        cout << "No action taken.\n";
    }
}

void setupTestData() {
    portfolio.clear();
    portfolio.push_back({"MSFT", 100, 200.39});
    portfolio.push_back({"GME", 500, 9.39});
    portfolio.push_back({"MSFT", 250, 214.22});
    portfolio.push_back({"MSFT", 300, 222.59});
    portfolio.push_back({"AAPL", 150, 132.45});
    portfolio.push_back({"GME", 200, 10.12});
    portfolio.push_back({"AAPL", 100, 140.60});
    portfolio.push_back({"MSFT", 120, 230.30});
    portfolio.push_back({"GOOGL", 50, 100.00});
    portfolio.push_back({"GOOGL", 75, 102.00});
    cout << "Test data initialized.\n";
}

int main() {
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
            case 1:
                enterStockPerformance();
                break;
            case 2: {
                string name;
                cout << "Enter stock name to find: ";
                cin >> name;
                findStock(name);
                break;
            }
            case 3:
                setupTestData();
                break;
            case 4:
                showPortfolio();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (option != 0);

    return 0;
}
