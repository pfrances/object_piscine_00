#ifndef GRAPH_USER_INTERFACE_HPP
#define GRAPH_USER_INTERFACE_HPP

#include "Graph.hpp"
#include <iostream>

class GraphUserInterface
{
private:
    Graph *_graph;
    bool _running;

    float convertStringToFloat(std::string str);
    Vector2 extractVector2();
    void initialiseGraph();

    void printCommands();
    std::string extractCommand();
    void interpreteCommand(std::string command);

public:
    GraphUserInterface();
    ~GraphUserInterface();
    void run();
};

#endif
