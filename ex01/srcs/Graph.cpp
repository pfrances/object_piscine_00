#include "Graph.hpp"
#include <iostream>

Graph::Graph(const Vector2 &size)
{
    this->setSize(size);
}

Graph::~Graph()
{
}

void Graph::setSize(const Vector2 &size)
{
    if (!isValidSize(size))
        throw std::invalid_argument("Invalid size");

    _size = size;
}

const Vector2 &Graph::getSize() const
{
    return _size;
}

bool Graph::isValidSize(const Vector2 &size)
{
    return (size.getX() >= 0 && size.getY() >= 0 && size.getX() <= MAX_SIZE && size.getY() <= MAX_SIZE);
}

bool Graph::isNodeFitInSize(const Vector2 &node)
{
    return (node.getX() <= _size.getX() && node.getY() <= _size.getY());
}

void Graph::addNode(const Vector2 &node)
{
    if (!isNodeFitInSize(node))
    {
        std::cout << "Node is out of bounds" << std::endl;
        std::cout << "Map size: [X:" << _size.getX() << ", Y:" << _size.getY() << "]" << std::endl;
        return;
    }
    if (isNodeAlreadyExist(node))
    {
        std::cout << "Node already exist" << std::endl;
        return;
    }
    _nodes.push_back(node);
}

void Graph::removeNode(const Vector2 &node)
{
    if (!isNodeAlreadyExist(node))
    {
        std::cout << "Node does not exist" << std::endl;
        return;
    }
    _nodes.remove(node);
}

bool Graph::isNodeAlreadyExist(const Vector2 &node)
{
    std::list<Vector2>::iterator it;

    for (it = _nodes.begin(); it != _nodes.end(); it++)
    {
        if ((*it).getX() == node.getX() && (*it).getY() == node.getY())
            return true;
    }
    return false;
}

void Graph::printGraph()
{
    std::list<Vector2>::iterator it;

    for (int y = _size.getY(); y >= 0; y--)
    {
        std::cout << y;
        for (int x = 0; x <= _size.getX(); x++)
        {
            for (it = _nodes.begin(); it != _nodes.end(); it++)
            {
                if ((*it).getX() == x && (*it).getY() == y)
                    break;
            }
            if (it != _nodes.end())
                std::cout << " X";
            else
                std::cout << " .";
        }
        std::cout << std::endl;
    }

    std::cout << " ";
    for (int x = 0; x <= _size.getX(); x++)
        std::cout << " " << x;
    std::cout << std::endl;
}