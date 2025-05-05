#include "Portfolio.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Portfolio::buyStock(const std::string& name, int shares, double price) {
    stocks.push_back(Stock(name, shares, price));
}

void Portfolio::sellFIFO(const std::string& name, int shares_to_sell) {
    int remaining = shares_to_sell;
    for (size_t i = 0; i < stocks.size(); ++i) {
        if (stocks[i].stock_name == name) {
            if (stocks[i].number_of_shares >= remaining) {
                stocks[i].number_of_shares -= remaining;
                if (stocks[i].number_of_shares == 0)
                    stocks.erase(stocks.begin() + i);
                return;
            } else {
                remaining -= stocks[i].number_of_shares;
                stocks.erase(stocks.begin() + i);
                i--;
            }
        }
    }
    cout << "Error: Not enough shares.\n";
}

