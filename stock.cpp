#include "Stock.h"

Stock::Stock(std::string name, int shares, double price)
    : stock_name(name), number_of_shares(shares), price_per_share(price) {}
