#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
    // Attributes
    T data;
    std::vector<Node *> children;
    // Constructor
    Node(T value) : data(value) {}

    // Methods
    // Add a child to the children vector
    void add_child(Node *child)
    {
        children.push_back(child);
    }
    // Remove a child from the children vector
    void remove_child(Node *child)
    {
        for (int i = 0; i < children.size(); i++)
        {
            if (children[i] == child)
            {
                children.erase(children.begin() + i);
                break;
            }
        }
    }

    T get_value()
    {
        return data;
    }
   
};

#endif