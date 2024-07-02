#include <SFML/Graphics.hpp>
#include <iostream>

#include "Complex.hpp"
#include "Node.hpp"
#include "Tree.hpp"

using namespace std;

int main() {

    
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);
    Tree<double> tree;  // Binary tree that contains doubles.
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    cout << "in order traversal: " << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    cout << "pre order traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "post order traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << node->get_value() << " ";
        ;
    }  // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    cout << "bfs traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    cout << "dfs traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }  // prints:  1.1 1.2 1.4 1.5 1.3 1.6
    cout << endl;

    cout << "heap traversal:" << endl;
    for (auto node = tree.begin_heap_scan(); node != tree.end_heap_scan(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    tree.render_tree();

    Tree<double, 3> three_ary_tree;  // 3-ary tree.
    three_ary_tree.add_root(&root_node);
    three_ary_tree.add_sub_node(&root_node, &n1);
    three_ary_tree.add_sub_node(&root_node, &n2);
    three_ary_tree.add_sub_node(&root_node, &n3);
    three_ary_tree.add_sub_node(&n1, &n4);
    three_ary_tree.add_sub_node(&n2, &n5);

    cout << "in order traversal: " << endl;
    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    cout << "pre order traversal:" << endl;
    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "post order traversal:" << endl;
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node) {
        cout << node->get_value() << " ";
        ;
    }  // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    cout << "bfs traversal:" << endl;
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    three_ary_tree.render_tree();

    // tree of complex numbers
    Node<Complex> root_node_complex(Complex(1.1, 2.2));
    Node<Complex> n1_complex(Complex(1.2, 2.3));
    Node<Complex> n2_complex(Complex(1.3, 2.4));
    Node<Complex> n3_complex(Complex(1.4, 2.5));
    Node<Complex> n4_complex(Complex(1.5, 2.6));
    Node<Complex> n5_complex(Complex(1.6, 2.7));
    Tree<Complex> tree_complex;  // Binary tree that contains doubles.
    tree_complex.add_root(&root_node_complex);

    tree_complex.add_sub_node(&root_node_complex, &n1_complex);
    tree_complex.add_sub_node(&root_node_complex, &n2_complex);
    tree_complex.add_sub_node(&n1_complex, &n3_complex);
    tree_complex.add_sub_node(&n1_complex, &n4_complex);
    tree_complex.add_sub_node(&n2_complex, &n5_complex);

    cout << "dfs traversal:" << endl;
    for (auto node = tree_complex.begin_dfs_scan(); node != tree_complex.end_dfs_scan(); ++node) {
        cout << node->get_value() << " ";
        // print: 1.1 1.2 1.4 1.5 1.3 1.6
    }  // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    tree_complex.render_tree();


    return 0;
}
