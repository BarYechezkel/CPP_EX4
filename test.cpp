#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Iterators.hpp"
#include "Node.hpp"
#include "doctest.h"
#include "Tree.hpp"
#include "Complex.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
using namespace std;

TEST_CASE("binary tree") {
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

   /*
    the tree:
           1.1
         /     \  
       1.2     1.3
      /  \        \
    1.4   1.5      1.6
    */

SUBCASE("in order traversal") {

    double expected[] = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
    int i = 0;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        CHECK(node->get_value() == expected[i]);
        ++i;
    }
}

SUBCASE("pre order traversal") {
    double expected[] = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
    int i = 0;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        CHECK(node->get_value() == expected[i]);
        ++i;
    }
}

SUBCASE("post order traversal") {
    double expected[] = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
    int i = 0;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        CHECK(node->get_value() == expected[i]);
        ++i;
    }
}

SUBCASE("bfs traversal") {
    double expected[] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
    int i = 0;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        CHECK(node->get_value() == expected[i]);
        ++i;
    }
}

SUBCASE("dfs traversal") {
    double expected[] = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
    int i = 0;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        CHECK(node->get_value() == expected[i]);
        ++i;
    }
}

SUBCASE("heap traversal") {
    double expected[] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
    int i = 0;
    for (auto node = tree.begin_heap_scan(); node != tree.end_heap_scan(); ++node) {
        CHECK(node->get_value() == expected[i]);
        ++i;
    }
}
}



TEST_CASE(" 3-ary tree") {
    Node<double> root_node(1);
    Node<double> n1(2);
    Node<double> n2(3);
    Node<double> n3(4);
    Node<double> n4(5);
    Node<double> n5(6);
    Tree<double, 3> three_ary_tree;  // 3-ary tree.
    three_ary_tree.add_root(&root_node);
    three_ary_tree.add_sub_node(&root_node, &n1);
    three_ary_tree.add_sub_node(&root_node, &n2);
    three_ary_tree.add_sub_node(&root_node, &n3);
    three_ary_tree.add_sub_node(&n1, &n4);
    three_ary_tree.add_sub_node(&n2, &n5);
    /*
    // the tree:
    //        1
    //     /  |  \
    //    2   3   4
    //   /    |
    //  5     6
    */
   // will use dfs iterator
    SUBCASE("in order traversal") {
        double expected[] = {1, 2, 5, 3, 6, 4};
        int i = 0;
        for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }
    // will use dfs iterator
    SUBCASE("pre order traversal") {
        double expected[] = {1, 2, 5, 3, 6, 4};
        int i = 0;
        for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }
    // will use dfs iterator
    SUBCASE("post order traversal") {
        double expected[] = {1, 2, 5, 3, 6, 4};
        int i = 0;
        for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("bfs traversal") {
        double expected[] = {1, 2, 3, 4, 5, 6};
        int i = 0;
        for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("dfs traversal") {
        double expected[] = {1, 2, 5, 3, 6, 4};
        int i = 0;
        for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }
}


TEST_CASE ("tree with strings "){
    Node<string> root_node("A");
    Node<string> B("B");
    Node<string> C("C");
    Node<string> D("D");
    Node<string> E("E");
    Node<string> F("F");

    /*
    // the tree:
    //       A
    //     /  \
    //    B    C
    //   / \  /
    //  D   E F
    //       
    */
   
    Tree<string> tree;  // Binary tree that contains doubles.
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &B);
    tree.add_sub_node(&root_node, &C);
    tree.add_sub_node(&B, &D);
    tree.add_sub_node(&B, &E);
    tree.add_sub_node(&C, &F);

    SUBCASE("in order traversal") {
        string expected[] = {"D", "B", "E" ,"A","F","C"};
        int i = 0;
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("pre order traversal") {
        string expected[] = {"A", "B", "D", "E", "C", "F"};
        int i = 0;
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("post order traversal") {
        string expected[] = {"D", "E", "B", "F", "C", "A"};
        int i = 0;
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("bfs traversal") {
        string expected[] = {"A", "B", "C", "D", "E", "F"};
        int i = 0;
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }
    
}

TEST_CASE("Binary Tree wuth complex numbers"){
    Node <Complex> root_node(Complex(1.1, 2.2));
    Node <Complex> n1(Complex(1.2, 2.3));
    Node <Complex> n2(Complex(1.3, 2.4));
    Node <Complex> n3(Complex(1.4, 2.5));
    Node <Complex> n4(Complex(1.5, 2.6));
    Node <Complex> n5(Complex(1.6, 2.7));
    Tree<Complex> tree;  // Binary tree that contains doubles.
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    /*
    // the tree:
    //       1.1+2.2i
    //     /  \
    //  1.2+2.3i  1.3+2.4i
    //   / \      /
    // 1.4+2.5i  1.5+2.6i  1.6+2.7i
    */

    SUBCASE("in order traversal") {
        Complex expected[] = {Complex(1.4, 2.5), Complex(1.2, 2.3), Complex(1.5, 2.6), Complex(1.1, 2.2), Complex(1.6, 2.7), Complex(1.3, 2.4)};
        int i = 0;
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("pre order traversal") {
        Complex expected[] = {Complex(1.1, 2.2), Complex(1.2, 2.3), Complex(1.4, 2.5), Complex(1.5, 2.6), Complex(1.3, 2.4), Complex(1.6, 2.7)};
        int i = 0;
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("post order traversal") {
        Complex expected[] = {Complex(1.4, 2.5), Complex(1.5, 2.6), Complex(1.2, 2.3), Complex(1.6, 2.7), Complex(1.3, 2.4), Complex(1.1, 2.2)};
        int i = 0;
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("bfs traversal") {
        Complex expected[] = {Complex(1.1, 2.2), Complex(1.2, 2.3), Complex(1.3, 2.4), Complex(1.4, 2.5), Complex(1.5, 2.6), Complex(1.6, 2.7)};
        int i = 0;
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("dfs traversal") {
        Complex expected[] = {Complex(1.1, 2.2), Complex(1.2, 2.3), Complex(1.4, 2.5), Complex(1.5, 2.6), Complex(1.3, 2.4), Complex(1.6, 2.7)};
        int i = 0;
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

    SUBCASE("heap traversal") {
        Complex expected[] = {Complex(1.1, 2.2), Complex(1.2, 2.3), Complex(1.3, 2.4), Complex(1.4, 2.5), Complex(1.5, 2.6), Complex(1.6, 2.7)};
        int i = 0;
        for (auto node = tree.begin_heap_scan(); node != tree.end_heap_scan(); ++node) {
            CHECK(node->get_value() == expected[i]);
            ++i;
        }
    }

}


TEST_CASE ("empty tree"){
    Tree<int,2> tree;
        
    SUBCASE("in order traversal") {
        CHECK(tree.begin_in_order() == tree.end_in_order());
    }
}

    // SUBCASE("pre order traversal") {
    //     CHECK(tree.begin_pre_order() == tree.end_pre_order());
    // }

    // SUBCASE("post order traversal") {
    //     CHECK(tree.begin_post_order() == tree.end_post_order());
    // }

    // SUBCASE("bfs traversal") {
    //     CHECK(tree.begin_bfs_scan()== tree.end_bfs_scan());
    // }

    // SUBCASE("dfs traversal") {
    //     CHECK(tree.begin_dfs_scan() == tree.end_dfs_scan());
    // }

    // SUBCASE("heap traversal") {
    //     CHECK(tree.begin_heap_scan()== tree.end_heap_scan());
    // }



    
   


// TEST_CASE("clearTree") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;
//     tree.add_root(root_node);

//     Node<double> n1 = Node(1.2);
//     tree.add_sub_node(root_node, n1);

//     Node<double> n2 = Node(1.3);
//     tree.add_sub_node(root_node, n2);

//     tree.clearTree(tree.get_root());
//     CHECK(tree.get_root() == nullptr);
// }



// TEST_CASE("add_sub_node_with_nullptr_root") {
//     Tree<double> tree;
//     Node<double> n1 = Node(1.2);
//     CHECK_THROWS_AS(tree.add_sub_node(nullptr, &n1), std::invalid_argument);
// }

// TEST_CASE("add_sub_node_with_nullptr_child") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;
//     tree.add_root(root_node);
//     CHECK_THROWS_AS(tree.add_sub_node(&root_node, nullptr), std::invalid_argument);
// }

// TEST_CASE("remove_child_with_nullptr") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;
//     tree.add_root(root_node);
//     CHECK_THROWS_AS(tree.remove_child(1.2), std::invalid_argument);
// }

// TEST_CASE("begin_in_order") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;
//     tree.add_root(root_node);

//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);

//     tree.add_sub_node(root_node, n1);
//     tree.add_sub_node(root_node, n2);
//     tree.add_sub_node(n1, n3);
//     tree.add_sub_node(n1, n4);
//     tree.add_sub_node(n2, n5);

//     double expected[] = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
//     int i = 0;
//     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };



// TEST_CASE("preorder") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;  // Binary tree that contains doubles.
//     tree.add_root(&root_node);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);

//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);

//     double expected[] = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
//     int i =0 ;
//     for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };
// TEST_CASE("postorder") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;  // Binary tree that contains doubles.
//     tree.add_root(&root_node);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);

//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);
//     double expected[] = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
//     int i =0 ;
//     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };
// TEST_CASE("inOrder") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;  // Binary tree that contains doubles.
//     tree.add_root(&root_node);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);

//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);
//     double expected[] = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
//     int i =0 ;
//     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };
// TEST_CASE("BFS") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;  // Binary tree that contains doubles.
//     tree.add_root(&root_node);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);

//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);
//     double expected[] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
//     int i =0 ;
//     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };
// TEST_CASE("DFS") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;  // Binary tree that contains doubles.
//     tree.add_root(&root_node);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);

//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);
//     double expected[] = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
//     int i =0 ;
//     for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };
// TEST_CASE("heap") {
//     Node<double> root_node = Node(1.1);
//     Tree<double> tree;  // Binary tree that contains doubles.
//     tree.add_root(&root_node);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);

//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);
//     double expected[] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
//     int i =0 ;
//     for (auto node = tree.begin_heap_scan(); node != tree.end_heap_scan(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };

// TEST_CASE("in order with tree k>2") {  // use DFS iterator
//     Node<double> root_node = Node(1.1);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);
//     Tree<double, 3> three_ary_tree;  // 3-ary tree.
//     three_ary_tree.add_root(&root_node);
//     three_ary_tree.add_sub_node(&root_node, &n1);
//     three_ary_tree.add_sub_node(&root_node, &n2);
//     three_ary_tree.add_sub_node(&root_node, &n3);
//     three_ary_tree.add_sub_node(&n1, &n4);
//     three_ary_tree.add_sub_node(&n2, &n5);
//     double expected[] = {1.1, 1.2, 1.5, 1.3, 1.6, 1.4};
//     int i =0 ;
//     for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };
// // The tree should look like:
/**
 *       root = 1.1
 *     /      |     \
 *    1.2    1.3    1.4
 *   /        |
 *  1.5      1.6
 */

// TEST_CASE("pre order with tree k>2") {
//     Node<double> root_node = Node(1.1);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);
//     Tree<double, 3> three_ary_tree;  // 3-ary tree.
//     three_ary_tree.add_root(&root_node);
//     three_ary_tree.add_sub_node(&root_node, &n1);
//     three_ary_tree.add_sub_node(&root_node, &n2);
//     three_ary_tree.add_sub_node(&root_node, &n3);
//     three_ary_tree.add_sub_node(&n1, &n4);
//     three_ary_tree.add_sub_node(&n2, &n5);
//     double expected[] = {1.1, 1.2, 1.5, 1.3, 1.6, 1.4};
//     int i =0 ;
//     for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };

// TEST_CASE("post order with tree k>2") {//DFS
//     Node<double> root_node = Node(1.1);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);
//     Tree<double, 3> three_ary_tree;  // 3-ary tree.
//     three_ary_tree.add_root(&root_node);
//     three_ary_tree.add_sub_node(&root_node, &n1);
//     three_ary_tree.add_sub_node(&root_node, &n2);
//     three_ary_tree.add_sub_node(&root_node, &n3);
//     three_ary_tree.add_sub_node(&n1, &n4);
//     three_ary_tree.add_sub_node(&n2, &n5);
//     double expected[] = {1.1, 1.2, 1.5, 1.3, 1.6, 1.4};
//     int i =0 ;
//     for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };

// // test with complax
// TEST_CASE("post order with tree binary complex") {
//     Complex c1 = Complex(1.1, 2.2);
//     Complex c2 = Complex(1.2, 2.3);
//     Complex c3 = Complex(1.3, 2.4);
//     Complex c4 = Complex(1.4, 2.5);
//     Complex c5 = Complex(1.5, 2.6);
//     Complex c6 = Complex(1.6, 2.7);

//     Node<Complex> root_node = Node(c1);
//     Node<Complex> n1 = Node(c2);
//     Node<Complex> n2 = Node(c3);
//     Node<Complex> n3 = Node(c4);
//     Node<Complex> n4 = Node(c5);
//     Node<Complex> n5 = Node(c6);

//     Tree<Complex> tree;  // 3-ary tree.
//     tree.add_root(&root_node);
//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);
//     // prints: c4 c5 c2 c6 c3 c1

//     Complex expected[] = {c4, c5, c2, c6, c3, c1};
//     int i =0 ;
//     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };
// TEST_CASE(" DFS iter with tree k>2 complex"){
//     Complex c1 = Complex(1.1, 2.2);
//     Complex c2 = Complex(1.2, 2.3);
//     Complex c3 = Complex(1.3, 2.4);
//     Complex c4 = Complex(1.4, 2.5);
//     Complex c5 = Complex(1.5, 2.6);
//     Complex c6 = Complex(1.6, 2.7);

//     Node<Complex> root_node = Node(c1);
//     Node<Complex> n1 = Node(c2);
//     Node<Complex> n2 = Node(c3);
//     Node<Complex> n3 = Node(c4);
//     Node<Complex> n4 = Node(c5);
//     Node<Complex> n5 = Node(c6);

//     Tree<Complex, 3> three_ary_tree;  // 3-ary tree.
//     three_ary_tree.add_root(&root_node);
//     three_ary_tree.add_sub_node(&root_node, &n1);
//     three_ary_tree.add_sub_node(&root_node, &n2);
//     three_ary_tree.add_sub_node(&root_node, &n3);
//     three_ary_tree.add_sub_node(&n1, &n4);
//     three_ary_tree.add_sub_node(&n2, &n5);
//     Complex expected[] = {c1, c2, c5, c3, c6, c4};
//     int i =0 ;
//     for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };
// TEST_CASE(" BFS iter with tree k=4 string"){
//     Node<const char*> root_node = Node("1.1");
//     Node<const char*> n1 = Node("2.2");
//     Node<const char*> n2 = Node("3.3");
//     Node<const char*> n3 = Node("4.4");
//     Node<const char*> n4 = Node("5.5");
//     Tree<const char*, 4> four_ary_tree;  // 3-ary tree.
//     four_ary_tree.add_root(&root_node); 
//     four_ary_tree.add_sub_node(&root_node, &n1);
//     four_ary_tree.add_sub_node(&root_node, &n2);
//     four_ary_tree.add_sub_node(&root_node, &n3);
//     four_ary_tree.add_sub_node(&root_node, &n4);
//     string expected[] = {"1.1", "2.2", "3.3", "4.4", "5.5"};
//     int i =0 ;
//     for (auto node = four_ary_tree.begin_bfs_scan(); node != four_ary_tree.end_bfs_scan(); ++node) {
//         CHECK(node->get_value() == expected[i]);
//         ++i;
//     }
// };