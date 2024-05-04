#include <string>
#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree;

template <typename T>
class Node
{
private:
    T data;
    Node<T>* left;
    Node<T>* right;

    /**
       Inserts a new node as a descendant of a given node.
       @param parent the root node
       @param new_node the node to insert
    */
public:
    void add_node(Node<T>* new_node);
    void delete_tree(Node<T>* node);
    void print() const;
    friend class BinarySearchTree<T>;
};

/*
   This class implements a binary search tree whose
   nodes hold strings.
*/
template <typename T>
class BinarySearchTree
{
public:
    /**
       Constructs an empty tree.
    */
    BinarySearchTree();

    /**
       Deconstructs a tree
    */
    ~BinarySearchTree();

    /**
      Constructs the tree with another tree
    */
    BinarySearchTree(BinarySearchTree& tree);

    /**
       Inserts a new node into the tree.
       @param element the element to insert
    */
    void insert(T element);

    /**
       Tries to find an element in the tree.
       @param element the element to find
       @return 1 if the element is contained in the tree
    */
    int count(T element) const;

    /**
       Tries to remove an element from the tree. Does nothing
       if the element is not contained in the tree.
       @param element the element to remove
    */
    void erase(T element);

    /**
       Prints the contents of the tree in sorted order.
    */
    void print() const;

    /**
       Assignment operator
    */
    BinarySearchTree<T>& operator=(BinarySearchTree<T>& other_tree);

    /**
       Get method
    */
    int get_total() const;

private:
    int total;
    void add_node(Node<T>* new_node);
    Node<T>* root;
};


template <typename T>
void Node<T>::add_node(Node<T>* new_node)
{
    if (new_node->data < data)
    {
        if (left == nullptr)
        {
            left = new_node;
        }
        else
        {
            left->add_node(new_node);
        }
    }
    else if (new_node->data > data)
    {
        if (right == nullptr)
        {
            right = new_node;
        }
        else
        {
            right->add_node(new_node);
        }
    }
}

template <typename T>
void Node<T>::print() const
{
    if (left != nullptr) {
        left->print();
    }
    cout << data << endl;
    if (right != nullptr) {
        right->print();
    }
}

template <typename T>
void Node<T>::delete_tree(Node<T>* node) {
    if (node != nullptr) {
        if (node->left != nullptr)
            delete_tree(node->left);
        if (node->right != nullptr)
            delete_tree(node->right);
        delete node;
    }
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
    total = 0;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree& tree) {
    root = tree.root;
    total = tree.total;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    root->delete_tree(root);
}

template <typename T>
int BinarySearchTree<T>::get_total() const {
    return total;
}

template <typename T>
void BinarySearchTree<T>::add_node(Node<T>* new_node) {
    root->add_node(new_node);
}

template <typename T>
void BinarySearchTree<T>::insert(T element)
{
    Node<T>* new_node = new Node<T>;
    new_node->data = element;
    new_node->left = nullptr;
    new_node->right = nullptr;
    if (root == nullptr)
    {
        root = new_node;
    }
    else
    {
        add_node(new_node);
        total++;
    }
}

template <typename T>
int BinarySearchTree<T>::count(T element) const
{
    Node<T>* current = root;
    while (current != nullptr)
    {
        if (element < current->data)
        {
            current = current->left;
        }
        else if (element > current->data)
        {
            current = current->right;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

template <typename T>
void BinarySearchTree<T>::erase(T element)
{
    // Find node to be removed

    Node<T>* to_be_removed = root;
    Node<T>* parent = nullptr;
    bool found = false;
    while (!found && to_be_removed != nullptr)
    {
        if (element == to_be_removed->data)
        {
            found = true;
        }
        else
        {
            parent = to_be_removed;
            if (element < to_be_removed->data)
            {
                to_be_removed = to_be_removed->left;
            }
            else
            {
                to_be_removed = to_be_removed->right;
            }
        }
    }

    if (!found)
    {
        return;
    }

    // to_be_removed contains element

    // If one of the children is empty, use the other

    if (to_be_removed->left == nullptr || to_be_removed->right == nullptr)
    {
        Node<T>* new_child;
        if (to_be_removed->left == nullptr)
        {
            new_child = to_be_removed->right;
        }
        else
        {
            new_child = to_be_removed->left;
        }

        if (parent == nullptr) // Found in root
        {
            root = new_child;
        }
        else if (parent->left == to_be_removed)
        {
            parent->left = new_child;
        }
        else
        {
            parent->right = new_child;
        }
        return;
    }

    // Neither subtree is empty

    // Find smallest element of the right subtree

    Node<T>* smallest_parent = to_be_removed;
    Node<T>* smallest = to_be_removed->right;
    while (smallest->left != nullptr)
    {
        smallest_parent = smallest;
        smallest = smallest->left;
    }

    // smallest contains smallest child in right subtree

    // Move contents, unlink child

    to_be_removed->data = smallest->data;
    if (smallest_parent == to_be_removed)
    {
        smallest_parent->right = smallest->right;
    }
    else
    {
        smallest_parent->left = smallest->right;
    }
}

template <typename T>
void BinarySearchTree<T>::print() const
{
    root->print();
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>& other_tree) {
    delete root;
    if (other_tree.root == nullptr)
        root = nullptr;
    else
        this->root = other_tree.root;
    return other_tree;
}