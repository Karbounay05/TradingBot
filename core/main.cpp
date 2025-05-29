#include "strategy_bridge.h"
#include "market_data.h"
#include "trade_executor.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Starting trading bot...\n";

    MarketData data;
    data.load_from_csv("../data/BTCUSD.csv");

    TradeExecutor executor;

    for (double price : data.get_price_history()) {
        std::string action = run_python_strategy(price);
        executor.execute(action);
    }

    return 0;
}
