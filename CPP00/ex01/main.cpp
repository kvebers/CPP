#include <iostream>
#include <string>




int main()
{
    int exit;
    std::string input;

    exit = 0;
    while (exit != 1)
    {
        std::cout << "Use commands ADD, SEARCH, EXIT: ";
        std::getline(std::cin, input);

        if (input == "EXIT")
            exit = 1;
        else if (input == "ADD")
            std::cout << "I do something" << std::endl;
        else if (input == "SEARCH")
            std::cout << "Indeed I do something dope" << std::endl;
        else
            std::cout << "This command is not valid, please redo" << std::endl;
    }
}