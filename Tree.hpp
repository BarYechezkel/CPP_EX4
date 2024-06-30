#ifndef TREE_HPP
#define TREE_HPP
#include "Node.hpp"
#include <stack>
#include <iostream>
#include <queue>
#include <SFML/Graphics.hpp>
#include "Iterators.hpp"
#include <sstream>

using namespace std;

template <typename T, int k = 2>

class Tree
{
private:
    // // Attributes
    // Node<T> *root;

public:
    // Attributes
    Node<T> *root;
    // Constructor
    Tree() : root(nullptr) {}
    // Destructor delete root and all its children
    ~Tree()
    {
        clearTree(root);
        // delete root;
    }

    void clearTree(Node<T> *node)
    {
        if (node == nullptr)
            return; // Check if the node is null

        // Recursively clear children vectors for all children nodes
        if (!node->children.empty())
        {
            for (auto child : node->children)
            {
                clearTree(child); // Recursively clear the children of the child node
            }
            node->children.clear(); // Clear the children vector of the current node
        }
    }

    // Add root
    void add_root(Node<T> &node_root)
    {
        root = &node_root;
    }

    // add_sub_node
    void add_sub_node(Node<T> &parent_node, Node<T> &node)
    {
        if (parent_node.children.size() < k)
        {
            // cout << "Adding child " << node.data << " to " << parent_node.data << endl;
            parent_node.add_child(&node);
        }
    }

    in_order_iterator<T> begin_in_order()
    {
        return in_order_iterator<T>(root);
    }
    in_order_iterator<T> end_in_order()
    {
        return in_order_iterator<T>(NULL);
    }

    pre_order_iterator<T> begin_pre_order()
    {
        return pre_order_iterator<T>(root);
    }
    pre_order_iterator<T> end_pre_order()
    {
        return pre_order_iterator<T>(NULL);
    }

    post_order_iterator<T> begin_post_order()
    {
        return post_order_iterator<T>(root);
    }
    post_order_iterator<T> end_post_order()
    {
        return post_order_iterator<T>(NULL);
    }

    bfs_iterator<T> begin_bfs_scan()
    {
        return bfs_iterator<T>(root);
    }
    bfs_iterator<T> end_bfs_scan()
    {
        return bfs_iterator<T>(NULL);
    }

    dfs_iterator<T> begin_dfs_scan()
    {
        return dfs_iterator<T>(root);
    }
    dfs_iterator<T> end_dfs_scan()
    {
        return dfs_iterator<T>(NULL);
    }

    // // myHeap make turn binary tree to min heap
    // void myHeap(Node<T> *root)
    // {
    //     if (root == NULL)
    //     {
    //         return;
    //     }
    //     Node<T> *min = root;
    //     if (root->children.size() > 0)
    //     {
    //         for (int i = 0; i < root->children.size(); i++)
    //         {
    //             if (root->children[i]->data < min->data)
    //             {
    //                 min = root->children[i];
    //             }
    //         }
    //         if (min->data < root->data)
    //         {
    //             T temp = root->data;
    //             root->data = min->data;
    //             min->data = temp;
    //         }
    //         myHeap(min);
    //     }
    // }

    // Remove a child from the root node
    void remove_child(T data)
    {
        Node<T> *child = new Node<T>(data);
        root->remove_child(child);
    }

    

    // פונקציה שמציירת את העץ בחלון SFML

    void draw_tree(sf::RenderWindow &window, Node<T> *node, float x, float y, float x_offset, float y_offset, sf::Font &font)
    {
        

        // עבור כל ילד של הצומת הנוכחי, צייר קו בין הצומת להילד ותקרא לפונקציה רקורסיבית לצייר את הילד
        for (auto i = 0u; i < node->children.size(); ++i)
        {
            float new_x = x + (i - node->children.size() / 2.0) * x_offset;
            float new_y = y + y_offset;

            // צייר קו בין הצומת להילד
            sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(x + 25, y + 25)),
                    sf::Vertex(sf::Vector2f(new_x + 25, new_y + 25))};
            window.draw(line, 2, sf::Lines);

            // צייר את הילד
            draw_tree(window, node->children[i], new_x, new_y, x_offset / 2, y_offset, font);
        }

        if (node == nullptr)
            return;

        // צייר את הצומת הנוכחי
        sf::CircleShape circle(40);
        circle.setFillColor(sf::Color::White);
        circle.setPosition(x, y);
        window.draw(circle);

        sf::Text text;
        text.setFont(font);
        std::ostringstream oss;
        oss << node->get_value();
        std::string str = oss.str();
        text.setString(str);
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::Blue);
        //set the position of the text at the center of the circle
        text.setPosition(x + 10, y + 25);
        window.draw(text);
    }

    // פונקציה ראשית שמציירת את העץ בחלון SFML
    void draw()
    {
        sf::RenderWindow window(sf::VideoMode(1200, 700), "Tree Visualization");

        sf::Font font;
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf"))
        {
            std::cerr << "Error loading font\n";
            return;
        }

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::Black);
            draw_tree(window, root, 600, 10, 200, 100, font);
            window.display();
        }
    }
};

#endif