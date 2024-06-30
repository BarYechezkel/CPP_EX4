#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node {
   private:
    // Attributes
    T data;
    std::vector<Node *> children;

   public:
    // Constructor
    Node(T value) : data(value) {}

    // Methods
    // Add a child to the children vector
    void add_child(Node *child) {
        children.push_back(child);
    }
    // Remove a child from the children vector
    void remove_child(Node *child) {
        for (int i = 0; i < children.size(); i++) {
            if (children[i] == child) {
                children.erase(children.begin() + i);
                break;
            }
        }
    }
    // Get the children vector
    vector<Node *> & get_children() {
        return children;
    }

    T get_value() {
        return data;
    }
};

#endif