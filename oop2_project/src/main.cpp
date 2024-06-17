#pragma once
#include "Controller.h"

int main() try {

    Controller c;
    c.run();

    return EXIT_SUCCESS;
}
catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return EXIT_FAILURE;
}