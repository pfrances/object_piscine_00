#include "GraphUserInterface.hpp"
#include <stdlib.h>

GraphUserInterface::GraphUserInterface() : _graph(NULL), _running(false)
{
}

GraphUserInterface::~GraphUserInterface()
{
    if (_graph != NULL)
        delete _graph;
}

float GraphUserInterface::convertStringToFloat(std::string str)
{
    char *ending;
    float converted_value = strtof(str.c_str(), &ending);
    if (*ending != '\0')
        throw std::invalid_argument("Invalid input");

    return converted_value;
}

Vector2 GraphUserInterface::extractVector2()
{
    std::cout << "X: ";
    std::string input;
    std::getline(std::cin, input);
    float x = convertStringToFloat(input);

    std::cout << "Y: ";
    std::getline(std::cin, input);
    float y = convertStringToFloat(input);

    return Vector2(x, y);
}

void GraphUserInterface::initialiseGraph()
{
    std::cout << "Enter Graph Size: " << std::endl;
    Vector2 size = extractVector2();
    _graph = new Graph(size);
}

void GraphUserInterface::printCommands()
{
    std::cout << "Commands: " << std::endl;
    std::cout << "[ADD] - add a node" << std::endl;
    std::cout << "[REMOVE] - remove a node" << std::endl;
    std::cout << "[PRINT] - print graph" << std::endl;
    std::cout << "[EXIT] - exit" << std::endl;
    std::cout << std::endl;
}

std::string GraphUserInterface::extractCommand()
{
    std::string command;
    std::getline(std::cin, command);
    return command;
}

void GraphUserInterface::interpreteCommand(std::string command)
{
    if (command == "EXIT")
    {
        _running = false;
    }
    else if (command == "ADD")
    {
        Vector2 v = extractVector2();
        _graph->addNode(v);
    }
    else if (command == "REMOVE")
    {
        Vector2 v = extractVector2();
        _graph->removeNode(v);
    }
    else if (command == "PRINT")
    {
        _graph->printGraph();
    }
    else
    {
        std::cout << " Invalid command: '" << command << "'" << std::endl;
    }
}

void GraphUserInterface::run()
{
    _running = true;
    while (_running)
    {
        try
        {
            if (_graph == NULL)
                initialiseGraph();
            else
            {
                printCommands();
                interpreteCommand(extractCommand());
            }
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
}