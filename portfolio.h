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
    void sellFIFO(const std::string& name, int shares_to_sell);
    void sellLIFO(const std::string& name, int shares_to_sell);
    void findStock(const std::string& name) const;
    void showPortfolio() const;
    void handlePerformance(const std::string& name, double change);
    void setupTestData();
};

#endif
