#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include <string>
#include "Stock.h"

class Portfolio {
private:
    std::vector<Stock> stocks;

public:
    void addStock(const std::string& name, int shares, double price);
    void sellStockFIFO(const std::string& name, int shares_to_sell);
    void sellStockLIFO(const std::string& name, int shares_to_sell);
    void displayStockDetails(const std::string& name) const;
    void displayAllHoldings() const;
    void processStockPerformance(const std::string& name, double change);
    void loadTestData();
};

#endif
