#include "trade_executor.h"
#include <iostream>

void TradeExecutor::execute(const std::string &action) {
    if (action == "buy") {
        std::cout << "[TradeExecutor] Executing BUY order." << std::endl;
    } else if (action == "sell") {
        std::cout << "[TradeExecutor] Executing SELL order." << std::endl;
    } else {
        std::cout << "[TradeExecutor] HOLD - No trade executed." << std::endl;
    }
}
