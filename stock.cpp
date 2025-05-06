#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock {
public:
    std::string stock_name;
    int number_of_shares;
    double price_per_share;

    Stock(std::string name, int shares, double price);
};

#endif

#include "Stock.h"

Stock::Stock(std::string name, int shares, double price)
    : stock_name(name), number_of_shares(shares), price_per_share(price) {}
