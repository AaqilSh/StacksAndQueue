#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include <string>
#include "Stock.h"

class Portfolio {
private:
    std::vector<Stock> stocks;

public:
    void buyStock(const std::string& name, int shares, double price);
    void sellEarlyStock(const std::string& name, int shares_to_sell);
    void sellRecentStock(const std::string& name, int shares_to_sell);
    void displayStockDetails(const std::string& name) const;
    void displayPortfolio() const;
    void processStockPerformance(const std::string& name, double change);
    void loadTestData();
};

#endif
