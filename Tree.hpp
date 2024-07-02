#ifndef TREE_HPP
#define TREE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <stdexcept>

#include "Iterators.hpp"
#include "Node.hpp"

using namespace std;

template <typename T, int k = 2>

class Tree {
   private:
    // // Attributes
    Node<T> *root;

     void clearTree(Node<T> *node) {
        if (node == nullptr)
            return;  // Check if the node is null

        // Recursively clear children vectors for all children nodes
        if (!node->get_children().empty()) {
            for (auto child : node->get_children()) {
                clearTree(child);  // Recursively clear the children of the child node
            }
            node->get_children().clear();  // Clear the children vector of the current node
        }
    }

    // function to draw the tree using SFML library
    void draw_tree(sf::RenderWindow &window, Node<T> *node, float x, float y, float x_offset, float y_offset, sf::Font &font) {
        // Increase the distance between nodes by adjusting these multipliers
        float x_distance_multiplier = 0.9;  // Increase for more horizontal space
        float y_distance_multiplier = 0.9;  // Increase for more vertical space

        // Apply the multipliers to the offsets
        x_offset *= x_distance_multiplier;
        y_offset *= y_distance_multiplier;

        // for each child of the current node, draw a line between the node and the child and call the function recursively to draw the child
        for (auto i = 0u; i < node->get_children().size(); ++i) {
            float new_x = x + (i - node->get_children().size() / 2.0) * x_offset;
            float new_y = y + y_offset;

            // draw a line between the node and the child
            sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(x + 25, y + 25)),
                    sf::Vertex(sf::Vector2f(new_x + 25, new_y + 25), sf::Color::Black)};
            window.draw(line, 2, sf::Lines);

            // call the function recursively to draw the child
            draw_tree(window, node->get_children()[i], new_x, new_y, x_offset / 2, y_offset, font);
        }

        if (node == nullptr)
            return;

        // draw the current node
        sf::CircleShape circle(30);
        circle.setFillColor(sf::Color::White);
        circle.setOutlineColor(sf::Color::Blue);
        circle.setOutlineThickness(3);
        circle.setPosition(x, y);
        window.draw(circle);

        sf::Text text;
        text.setFont(font);
        std::ostringstream oss;
        oss << node->get_value();
        std::string str = oss.str();
        text.setString(str);
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::Black);
        // set the position of the text at the center of the circle
        text.setPosition(x + 15, y + 20);
        window.draw(text);
    }

   

   public:
    // Constructor
    Tree() : root(nullptr) {}
    // Destructor delete root and all its children
    ~Tree() {
        clearTree(root);
    }

    // Add root
    void add_root(Node<T> *node_root) {
        if (node_root == nullptr) {
            throw std::invalid_argument("Root node cannot be null");
        }
        root = node_root;
    }

    // add_sub_node
    void add_sub_node(Node<T> *parent_node, Node<T> *node) {
        if (parent_node->get_children().size() < k) {
            // cout << "Adding child " << node.data << " to " << parent_node.data << endl;
            parent_node->add_child(node);
        }
    }

    // function to render the tree
    void render_tree() {
        sf::RenderWindow window(sf::VideoMode(1200, 700), "Tree Visualization");

        sf::Font font;
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
            std::cerr << "Error loading font\n";
            return;
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            draw_tree(window, root, 600, 10, 200, 100, font);
            window.display();
        }
    }

    // Remove a child from the root node
    void remove_child(T data) {
        Node<T> *child = new Node<T>(data);
        root->remove_child(child);
    }

    dfs_iterator<T> begin_in_order() { return dfs_iterator<T>(root); }
    dfs_iterator<T> end_in_order() { return dfs_iterator<T>(nullptr); }
    dfs_iterator<T> begin_pre_order() { return dfs_iterator<T>(root); }
    dfs_iterator<T> end_pre_order() { return dfs_iterator<T>(nullptr); }
    dfs_iterator<T> begin_post_order() { return dfs_iterator<T>(root); }
    dfs_iterator<T> end_post_order() { return dfs_iterator<T>(nullptr); }
    bfs_iterator<T> begin_bfs_scan() { return bfs_iterator<T>(root); }
    bfs_iterator<T> end_bfs_scan() { return bfs_iterator<T>(nullptr); }
    dfs_iterator<T> begin_dfs_scan() { return dfs_iterator<T>(root); }
    dfs_iterator<T> end_dfs_scan() { return dfs_iterator<T>(nullptr); }
};

#endif

// specialisation of the Tree class for k=2
template <typename T>
class Tree<T, 2> {
   private:
    // // Attributes
    Node<T> *root;

    void clearTree(Node<T> *node) {
        if (node == nullptr)
            return;  // Check if the node is null

        // Recursively clear children vectors for all children nodes
        if (!node->get_children().empty()) {
            for (auto child : node->get_children()) {
                clearTree(child);  // Recursively clear the children of the child node
            }
            node->get_children().clear();  // Clear the children vector of the current node
        }
    }

    // function to draw the tree using SFML library
    void draw_tree(sf::RenderWindow &window, Node<T> *node, float x, float y, float x_offset, float y_offset, sf::Font &font) {
        // Increase the distance between nodes by adjusting these multipliers
        float x_distance_multiplier = 0.9;  // Increase for more horizontal space
        float y_distance_multiplier = 0.9;  // Increase for more vertical space

        // Apply the multipliers to the offsets
        x_offset *= x_distance_multiplier;
        y_offset *= y_distance_multiplier;

        // for each child of the current node, draw a line between the node and the child and call the function recursively to draw the child
        for (auto i = 0u; i < node->get_children().size(); ++i) {
            float new_x = x + (i - node->get_children().size() / 2.0) * x_offset;
            float new_y = y + y_offset;

            // draw a line between the node and the child
            sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(x + 25, y + 25)),
                    sf::Vertex(sf::Vector2f(new_x + 25, new_y + 25), sf::Color::Black)};
            window.draw(line, 2, sf::Lines);

            // call the function recursively to draw the child
            draw_tree(window, node->get_children()[i], new_x, new_y, x_offset / 2, y_offset, font);
        }

        if (node == nullptr)
            return;

        // draw the current node
        sf::CircleShape circle(30);
        circle.setFillColor(sf::Color::White);
        circle.setOutlineColor(sf::Color::Blue);
        circle.setOutlineThickness(3);
        circle.setPosition(x, y);
        window.draw(circle);

        sf::Text text;
        text.setFont(font);
        std::ostringstream oss;
        oss << node->get_value();
        std::string str = oss.str();
        text.setString(str);
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::Black);
        // set the position of the text at the center of the circle
        text.setPosition(x + 15, y + 20);
        window.draw(text);
    }

   public:
    // Constructor
    Tree() : root(nullptr) {}
    // Destructor delete root and all its children
    ~Tree() {
        clearTree(root);
    }

    // Add root
    void add_root(Node<T> *node_root) {
        if (node_root == nullptr) {
            throw std::invalid_argument("Root node cannot be null");
        }
        root = node_root;
    }

    // add_sub_node
    void add_sub_node(Node<T> *parent_node, Node<T> *node) {
        if (parent_node->get_children().size() < 2) {
            // cout << "Adding child " << node.data << " to " << parent_node.data << endl;
            parent_node->add_child(node);
        }
    }

    // get root
    Node<T> *get_root() {
        return root;
    }

    // Remove a child from the root node
    void remove_child(T data) {
        Node<T> *child = new Node<T>(data);
        root->remove_child(child);
    }

    in_order_iterator<T> begin_in_order() { return in_order_iterator<T>(root); }
    in_order_iterator<T> end_in_order() { return in_order_iterator<T>(nullptr); }
    pre_order_iterator<T> begin_pre_order() { return pre_order_iterator<T>(root); }
    pre_order_iterator<T> end_pre_order() { return pre_order_iterator<T>(nullptr); }
    post_order_iterator<T> begin_post_order() { return post_order_iterator<T>(root); }
    post_order_iterator<T> end_post_order() { return post_order_iterator<T>(nullptr); }
    bfs_iterator<T> begin_bfs_scan() { return bfs_iterator<T>(root); }
    bfs_iterator<T> end_bfs_scan() { return bfs_iterator<T>(nullptr); }
    dfs_iterator<T> begin_dfs_scan() { return dfs_iterator<T>(root); }
    dfs_iterator<T> end_dfs_scan() { return dfs_iterator<T>(nullptr); }
    heap_iterator<T> begin_heap_scan() { return heap_iterator<T>(root); }
    heap_iterator<T> end_heap_scan() { return heap_iterator<T>(nullptr); }

    // function to render the tree
    void render_tree() {
        sf::RenderWindow window(sf::VideoMode(1200, 700), "Tree Visualization");

        sf::Font font;
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
            std::cerr << "Error loading font\n";
            return;
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            draw_tree(window, root, 600, 10, 200, 100, font);
            window.display();
        }
    }
};
