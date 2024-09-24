#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vector2.hpp"
#include <list>

class Graph
{
private:
    std::list<Vector2> _nodes;
    static const int MAX_SIZE = 32;
    Vector2 _size;

    bool isNodeFitInSize(const Vector2 &node);
    bool isValidSize(const Vector2 &size);
    bool isNodeAlreadyExist(const Vector2 &node);

public:
    Graph(const Vector2 &size);
    ~Graph();

    void setSize(const Vector2 &size);
    const Vector2 &getSize() const;

    void addNode(const Vector2 &node);

    void removeNode(const Vector2 &node);

    void printGraph();
};

#endif