#include "Tree.hpp"
#include "Node.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Complex.hpp"

using namespace std;

int main()
{
    //      sf::RenderWindow window(
    //         sf::VideoMode(640, 480),
    //         "Hello World");
    //     sf::CircleShape shape(200);
    //         sf::CircleShape shape2(50);
    //         shape2.setFillColor(sf::Color::Yellow);
    //         shape2.setPosition(100, 100);

    //     while (window.isOpen())
    //     {
    //         sf::Event event;
    //         while (
    //             window.pollEvent(event))
    //             if (event.type ==
    //             sf::Event::Closed)
    //                 window.close();

    //         window.clear();
    //         window.draw(shape);
    //         window.draw(shape2);
    //         window.display();
    //     }
    Node<double> root_node = Node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    cout << "in order traversal: " << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    cout << "pre order traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "post order traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << " ";
        ;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    cout << "bfs traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    cout << "dfs traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
        // print: 1.1 1.2 1.4 1.5 1.3 1.6
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    tree.draw();

    Tree<double, 3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    three_ary_tree.draw();

    // tree of complex numbers
    Node<Complex> root_node_complex = Node(Complex(1.1, 2.2));
    Tree<Complex> tree_complex; // Binary tree that contains doubles.
    tree_complex.add_root(root_node_complex);
    Node<Complex> n1_complex = Node(Complex(1.2, 2.3));
    Node<Complex> n2_complex = Node(Complex(1.3, 2.4));
    Node<Complex> n3_complex = Node(Complex(1.4, 2.5));
    Node<Complex> n4_complex = Node(Complex(1.5, 2.6));
    Node<Complex> n5_complex = Node(Complex(1.6, 2.7));


    tree_complex.add_sub_node(root_node_complex, n1_complex);
    tree_complex.add_sub_node(root_node_complex, n2_complex);
    tree_complex.add_sub_node(n1_complex, n3_complex);
    tree_complex.add_sub_node(n1_complex, n4_complex);
    tree_complex.add_sub_node(n2_complex, n5_complex);
    

      cout << "dfs traversal:" << endl;
     for (auto node = tree_complex.begin_dfs_scan(); node != tree_complex.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
        // print: 1.1 1.2 1.4 1.5 1.3 1.6
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    tree_complex.draw();
    // destractor has problem with the complex numbers


    return 0;
}
