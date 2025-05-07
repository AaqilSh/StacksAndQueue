#include "Portfolio.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Portfolio::buyStock(const string& name, int shares, double price) {
    stocks.emplace_back(name, shares, price);
    cout << "Bought " << shares << " shares of " << name << " at £" << fixed << setprecision(2) << price << "\n";
}

// Sell shares from the earliest purchase - FIFO
void Portfolio::sellEarlyStock(const std::string& name, int desired_shares) {
    for (size_t i = 0; i < stocks.size(); ++i) {
        if (stocks[i].stock_name == name) {
            int sellable = std::min(desired_shares, stocks[i].number_of_shares);
            cout << "Selling stocks from earliest purchase: " << sellable << " shares of " << name << ".\n";

            stocks[i].number_of_shares -= sellable;

            if (stocks[i].number_of_shares == 0) {
                stocks.erase(stocks.begin() + i);
            }

            return;
        }
    }

    cout << "Error: No available lots found to sell " << desired_shares << " shares of " << name << ".\n";
}


// Sell shares from the most recent purchase - LIFO
void Portfolio::sellRecentStock(const std::string& name, int desired_shares) {
    for (int i = static_cast<int>(stocks.size()) - 1; i >= 0; --i) {
        if (stocks[i].stock_name == name) {
            int sellable = std::min(desired_shares, stocks[i].number_of_shares);
            cout << "Selling from latest purchase: " << sellable << " shares of " << name << " .\n";

            stocks[i].number_of_shares -= sellable;

            if (stocks[i].number_of_shares == 0) {
                stocks.erase(stocks.begin() + i);
            }

            return;
        }
    }

    cout << "Error: No available lots found to sell " << desired_shares << " shares of " << name << ".\n";
}


// Display Stock Details
void Portfolio::displayStockDetails(const string& name) const {
    bool found = false;
    for (const auto& stock : stocks) {
        if (stock.stock_name == name) {
            cout << stock.stock_name << ": " << stock.number_of_shares << " shares at £" << fixed << setprecision(2) << stock.price_per_share << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Stock not found.\n";
    }
}

//Display stock portfolio
void Portfolio::displayPortfolio() const {
    if (stocks.empty()) {
        cout << "Portfolio is empty.\n";
        return;
    }
    cout << "\n--- Portfolio ---\n";
    for (const auto& stock : stocks) {
        cout << stock.stock_name << ": " << stock.number_of_shares << " shares at £" << fixed << setprecision(2) << stock.price_per_share << "\n";
    }
    cout << "-----------------\n";
}

// Load test data
void Portfolio::loadTestData() {
    stocks.clear();
    buyStock("GME", 500, 9.39);
    buyStock("GME", 300, 10.20);
    buyStock("GME", 100, 12.50);
    buyStock("MSFT", 100, 200.39);
    buyStock("MSFT", 250, 214.22);
    buyStock("MSFT", 300, 222.59);
    buyStock("MSFT", 150, 230.45);
    buyStock("AAPL", 150, 135.60);
    buyStock("AAPL", 100, 140.75);
    buyStock("AAPL", 200, 145.30);
    buyStock("AMZN", 80, 3100.99);
    buyStock("AMZN", 120, 3050.00);
    buyStock("TSLA", 60, 720.50);
    buyStock("TSLA", 90, 710.25);
    cout << "Test data loaded.\n";
}


// Process stock performance
void Portfolio::processStockPerformance(const string& name, double change_percent) {
    if (change_percent >= 5.0 && change_percent <= 20.0) {
        cout << "Price increased by " << change_percent << "% . Sell using FIFO.\n";
        sellEarlyStock(name, 300);
    } else if (change_percent >= -1.0 && change_percent <= -0.5) {
        int new_shares;
        double new_price;
        cout << "Price decreased by " << change_percent << "% . Buy more shares.\n";
        cout << "Enter number of shares to buy: ";
        cin >> new_shares;
        cout << "Enter price per share: £";
        cin >> new_price;
        if (new_shares > 0 && new_price > 0) {
            buyStock(name, new_shares, new_price);
        } else {
            cout << "Invalid input.\n";
        }
    } else if (change_percent >= -3.0 && change_percent <= -1.1) {
        cout << "Price decreased by " << change_percent << "% . Sell using LIFO.\n";
        sellRecentStock(name, 250);
    } else {
        cout << "Portfolio retained. No action taken based on performance.\n";
    }
}
