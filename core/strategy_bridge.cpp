#include "strategy_bridge.h"
#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;
using namespace py::literals;

std::string run_python_strategy(double price) {
    try {
        static py::scoped_interpreter guard{}; // start Python interpreter once

        // Add parent directory to Python sys.path so 'python.strategy_template' can be found
        py::module sys = py::module::import("sys");
        sys.attr("path").attr("insert")(1, "..");

        py::module strategy = py::module::import("python.strategy_template");

        py::object decide = strategy.attr("decide_action");

        std::string action = decide(price).cast<std::string>();

        return action;
    }
    catch (const std::exception &e) {
        std::cerr << "Python error: " << e.what() << std::endl;
        return "hold";  // default action on error
    }
}
