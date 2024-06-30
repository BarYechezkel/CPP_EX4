#include <iostream>
#include <queue>
#include "Node.hpp"
// begin_in_order, end_in_order the methods returns itreators to pass on tree in in order
template <typename T>
class in_order_iterator
{
private:
    std::stack<Node<T> *> stack;
    Node<T> *current;

    void push_most_left_child(Node<T> *node)
    {
        while (node != nullptr)
        {
            stack.push(node);
            if (!node->children.empty())
                node = node->children[0]; // Go to leftmost child
            else
                break;
        }
    }

public:
    // Constructor
    in_order_iterator(Node<T> *root) : current(nullptr)
    {
        push_most_left_child(root);
        if (!stack.empty())
        {
            current = stack.top(); // Leftmost child
            stack.pop();           // Pop the leftmost child
        }
    }

    in_order_iterator &operator++()
    {
        if (current == nullptr)
            return *this;

        // If current node has a right child, push the right child and all its left children
        if (!current->children.empty() && current->children.size() > 1)
        {
            Node<T> *temp = current->children[1]; // Right child
            push_most_left_child(temp);
        }

        if (!stack.empty())
        {
            current = stack.top();
            stack.pop();
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    //    in_order_iterator operator++(int)
    // {
    //     in_order_iterator it = *this;
    //     ++(*this);
    //     return it;
    // }

    // Node<T> &operator*() const
    // {
    //     return *current;
    // }

    // Arrow operator
    Node<T> *operator->() const
    {
        return current;
    }

    // Equality operator
    bool operator==(const in_order_iterator &other) const
    {
        return current == other.current;
    }

    // Inequality operator
    bool operator!=(const in_order_iterator &other) const
    {
        return !(*this == other);
    }
};

// begin_pre_order, end_pre_order the methods returns itreators to pass on tree in pre order
template <typename T>
class pre_order_iterator
{
private:
    std::stack<Node<T> *> stack;
    Node<T> *current;

public:
    pre_order_iterator(Node<T> *root)
    {
        if (root != nullptr)
        {
            stack.push(root);
        }
        current = root; // Set current node to the root
    }

    pre_order_iterator &operator++()
    {
        if (stack.empty())
        {
            current = nullptr;
            return *this;
        }

        current = stack.top();
        stack.pop();

        // Push children onto the stack in reverse order (right child first, then left child)
        for (int i = current->children.size() - 1; i >= 0; i--)
        {
            stack.push(current->children[i]);
        }
        if (!stack.empty())
        {
            current = stack.top();
        }
        else
        {
            current = nullptr;
        }

        return *this;
    }

    pre_order_iterator operator++(int)
    {
        pre_order_iterator it = *this;
        ++(*this);
        return it;
    }

    Node<T> *operator->() const
    {
        return current;
    }

    Node<T> &operator*() const
    {
        return *current;
    }

    bool operator==(const pre_order_iterator &other) const
    {
        return current == other.current;
    }

    bool operator!=(const pre_order_iterator &other) const
    {
        return !(*this == other);
    }
};
// begin_post_order, end_post_order the methods returns itreators to pass on tree in post order

template <typename T>
class post_order_iterator
{
private:
    std::stack<std::pair<Node<T> *, bool>> stack;
    Node<T> *current;

public:
    post_order_iterator(Node<T> *root)
    {
        if (root != nullptr)
        {
            stack.push({root, false}); // Push root with false indicating not visited yet
            ++(*this);                 // Move to the first valid node
        }
        else
        {
            current = nullptr;
        }
    }

    post_order_iterator &operator++()
    {
        while (!stack.empty())
        {
            auto [node, visited] = stack.top();
            if (visited)
            {
                stack.pop();
                current = node;
                return *this;
            }
            else
            {
                stack.top().second = true; // Mark node as visited
                // Push right child with false (not visited) first
                if (node->children.size() > 1)
                {
                    stack.push({node->children[1], false});
                }
                // Push left child with false (not visited)
                if (node->children.size() > 0)
                {
                    stack.push({node->children[0], false});
                }
            }
        }
        current = nullptr;
        return *this;
    }

    post_order_iterator operator++(int)
    {
        post_order_iterator it = *this;
        ++(*this);
        return it;
    }

    Node<T> *operator->() const
    {
        return current;
    }

    Node<T> &operator*() const
    {
        return *current;
    }

    bool operator==(const post_order_iterator &other) const
    {
        return current == other.current;
    }

    bool operator!=(const post_order_iterator &other) const
    {
        return !(*this == other);
    }
};

// begin_bfs_scan, end_bfs_scan the methods returns itreators to pass on tree use bfs

template <typename T>
class bfs_iterator
{
private:
    std::queue<Node<T> *> queue;
    Node<T> *current;

public:
    bfs_iterator(Node<T> *root)
    {
        if (root != nullptr)
        {
            queue.push(root);
            ++(*this); // Move to the first valid node
        }
        else
        {
            current = nullptr;
        }
    }

    bfs_iterator &operator++()
    {
        if (!queue.empty())
        {
            current = queue.front();
            queue.pop();

            // Enqueue all children of current node
            for (Node<T> *child : current->children)
            {
                queue.push(child);
            }
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    bfs_iterator operator++(int)
    {
        bfs_iterator it = *this;
        ++(*this);
        return it;
    }

    Node<T> *operator->() const
    {
        return current;
    }

    Node<T> &operator*() const
    {
        return *current;
    }

    bool operator==(const bfs_iterator &other) const
    {
        return current == other.current;
    }

    bool operator!=(const bfs_iterator &other) const
    {
        return !(*this == other);
    }
};

// // begin_dfs_scan, end_dfs_scan the methods returns itreators to pass on tree use dfs
template <typename T>
class dfs_iterator
{
private:
    std::stack<Node<T> *> stack;
    Node<T> *current;

public:
    dfs_iterator(Node<T> *root)
    {
        if (root != nullptr)
        {
            stack.push(root);
            ++(*this); // Move to the first valid node
        }
        else
        {
            current = nullptr;
        }
    }

    dfs_iterator &operator++()
    {
        if (!stack.empty())
        {
            current = stack.top();
            stack.pop();

            // Push children onto the stack in reverse order (right child first, then left child)
            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it)
            {
                stack.push(*it);
            }
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    dfs_iterator operator++(int)
    {
        dfs_iterator it = *this;
        ++(*this);
        return it;
    }

    Node<T> *operator->() const
    {
        return current;
    }

    Node<T> &operator*() const
    {
        return *current;
    }

    bool operator==(const dfs_iterator &other) const
    {
        return current == other.current;
    }

    bool operator!=(const dfs_iterator &other) const
    {
        return !(*this == other);
    }
};