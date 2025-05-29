#include "market_data.h"
#include <fstream>
#include <sstream>
#include <iostream>

void MarketData::load_from_csv(const std::string& filepath) {
    std::cout << "Loading data from " << filepath << std::endl;
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return;
    }

    prices_.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, price_str;
        std::getline(ss, date, ',');      // Skip date column
        std::getline(ss, price_str, ','); // Price assumed second column

        double price = std::stod(price_str);
        prices_.push_back(price);
    }
}

std::vector<double> MarketData::get_price_history() const {
    return prices_;
}
