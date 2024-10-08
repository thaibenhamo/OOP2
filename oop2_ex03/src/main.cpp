#include "Controller.h"
#include <iostream>

int main()
{
    try
    {
        Controller game;
        game.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1; // Return error code
    }
}
	