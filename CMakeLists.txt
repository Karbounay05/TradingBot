cmake_minimum_required(VERSION 3.14)
project(trading_bot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Python and pybind11
find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

include_directories(include)

add_executable(trading_bot
    core/main.cpp
    core/strategy_bridge.cpp
    core/trade_executor.cpp
    core/market_data.cpp
)



target_link_libraries(trading_bot PRIVATE pybind11::embed Python::Python)
