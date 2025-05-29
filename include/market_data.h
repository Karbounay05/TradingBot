#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include <string>
#include <vector>

class MarketData {
public:
    void load_from_csv(const std::string& filepath);

    // Add this getter method
    std::vector<double> get_price_history() const;

private:
    std::vector<double> prices_;  // Store loaded prices
};

#endif
