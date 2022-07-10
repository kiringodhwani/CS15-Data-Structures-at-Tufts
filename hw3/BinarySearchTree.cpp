/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 *
 * Edited by Kirin Godhwani, 11/6
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

/* default constructor
 *    Purpose: Initializes an empty binary search tree
 */
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

/* destructor
 *    Purpose: Frees all memory associated with the binary search tree.
 */
BinarySearchTree::~BinarySearchTree()
{
    // walk tree in post-order traversal and delete
    post_order_delete(root);
    root = nullptr;  // not really necessary, since the tree is going
                     // away, but might want to guard against someone
                     // using a pointer after deleting
}

/* post_order_delete
 *    Purpose: Recursively deletes all Nodes in the given tree in a post-order
 *             fashion.
 * Parameters: Pointer to the current Node
 *    Returns: Nothing
 */
void BinarySearchTree::post_order_delete(Node *node)
{
    if (node == nullptr) {
        return;
    } else {
        post_order_delete(node->left);
        post_order_delete(node->right);
        delete node;
    }
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
    // use pre-order traversal to copy the tree
    root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
    // check for self-assignment
    if (this->root == source.root) {
        return *this;    
    }
    
    // if the trees are not the same, delete the current tree
    post_order_delete(this->root);

    // copy the given tree to the current tree
    this->root = pre_order_copy(source.root);

    return *this;
}

/* pre_order_copy
 *    Purpose: Recursive (private) function used in the copy constructor and
 *             assignment operator. Uses a pre-order traversal to copy the
 *             given tree.
 * Parameters: Pointer to the current Node
 *    Returns: The copied tree
 */
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
    if (node == nullptr) {
        return nullptr;
        
    } else {
        
        Node *copy = newNode(node->data, node->count, node->left, node->right);
        copy->left = pre_order_copy(node->left);
        copy->right = pre_order_copy(node->right);
        return copy;
    }
}

/* find_min()
 *    Purpose: Returns the smallest data value in the entire tree. If the tree
 *             is empty, returns the largest possible integer.
 * Parameters: None
 *    Returns: The smallest data value in the tree
 */
int BinarySearchTree::find_min() const
{
    if (root == nullptr)
        return numeric_limits<int>::max(); // INT_MAX

    return find_min(root)->data;
}

/* find_min(Node *node)
 *    Purpose: Recursive (private) function for find_min. Recursively searches
 *             the given tree for its smallest data value and returns the
 *             address of the Node with the smallest data value.
 * Parameters: Pointer to the current Node
 *    Returns: The address of the Node with the smallest data value
 */
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
    if (node->left == nullptr) {
        return node;
    } else {
        return find_min(node->left);
    }
}

/* find_max()
 *    Purpose: Returns the largest data value in the entire tree. If the tree
 *             is empty, returns the smallest possible integer.
 * Parameters: None.
 *    Returns: The largest data value in the tree.
 */
int BinarySearchTree::find_max() const
{
    if (root == nullptr)
        return numeric_limits<int>::min(); // INT_MIN

    return find_max(root)->data;
}

/* find_max(Node *node)
 *    Purpose: Recursive (private) function for find_max. Recursively searches
 *             the given tree for its largest data value and returns the
 *             address of the Node with the largest data value.
 * Parameters: Pointer to the current Node
 *    Returns: The address of the Node with the largest data value
 */
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
    if (node->right == nullptr) {
        return node;
    } else {
        return find_max(node->right);
    }
}

/* contains(int value)
 *    Purpose: Checks to see if a given integer value is contained in the
 *             entire tree. 
 * Parameters: The integer value to be found or not found in the tree
 *    Returns: Returns true if the tree contains the given value, false
 *             otherwise
 */
bool BinarySearchTree::contains(int value) const
{
        return contains(root, value);
}

/* contains(Node *node, int value)
 *    Purpose: Recursive (private) function for contains. Recursively searches
 *             the given tree to see if the given integer value is contained
 *             in it.
 * Parameters: Pointer to the current Node, the integer value to be checked for
 *    Returns: Returns true if the tree contains the given value, false
 *             otherwise.
 */
bool BinarySearchTree::contains(Node *node, int value) const
{
    if (node == nullptr) {
        return false;
            
    } else if (node->data == value) {
        return true;
            
    } else if (value < node->data) {
        return contains(node->left, value);
            
    } else {
        return contains(node->right, value);
    }
}

/* insert(int value)
 *    Purpose: Inserts the given value into the binary search tree.
 * Parameters: The value to be inserted
 *    Returns: None
 *       Note: Preserves the BST invariant. If the number to be inserted is not
 *             in the tree, a new Node with count equal to 1 is created. If the
 *             value is already present in the tree, we increase the count in
 *             that Node by 1.
 */ 
void BinarySearchTree::insert(int value)
{
    insert(root, nullptr, value);
}

/* insert(Node *node, Node *parent, int value)
*    Purpose: Recursive (private) function for insert. Recursively searches
*             the given tree for the correct place to insert the given value
*             and inserts the value.
* Parameters: Pointer to the current Node, pointer to the parent of the current
*             Node, the integer value to be inserted
*    Returns: None.
*       Note: Same note as for the public insert function
*/
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
    if (node == nullptr) {
        
        // empty tree
        if (parent == nullptr) {
            node = newNode(value, 1, nullptr, nullptr);
            root = node;
            
        } else if (parent->data < value) {
            parent->right = newNode(value, 1, nullptr, nullptr);
            
        } else {
            parent->left = newNode(value, 1, nullptr, nullptr);
        }
    
    // value is a duplicate
    } else if (value == node->data) {
        (node->count)++;
    
    } else if (value < node->data) {
        insert(node->left, node, value);
        
    } else {
        insert(node->right, node, value);
    }
}

/* remove(int value)
 *    Purpose: Removes the Node with the given value from the BST.
 * Parameters: The value of the Node to to be removed
 *    Returns: True if an element was removed from the tree, false otherwise
 *       Note: Uses the smallest value in the right subtree to replace a
 *             removed Node that has two children.
 */
bool BinarySearchTree::remove(int value)
{
    return remove(root, nullptr, value);
}

/* remove(Node *node, Node *parent, int value)
 *    Purpose: Recursive (private function) for remove. Recursively searches
 *             the given BST for the given value. If the value is found, the
 *             count of its corresponding Node is lowered by 1. If the count
 *             is lowered below 1, then the Node is completely removed from the
 *             BST.
 * Parameters: Pointer to the current Node, pointer to the parent of the
 *             current Node, the value to be removed
 *    Returns: True if an element was removed from the tree, false otherwise
 *       Note: Same note as for the public remove function.
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
    Node *curr = get(node, value); // get the value in the BST
    if (curr == nullptr)
        return false;
    if (curr->count > 1) {    // deleting a duplicate
        (curr->count)--;
        return true;
    }
    parent = find_parent(node, curr); // set the parent pointer
    // Node to delete is a leaf
    if (curr->left == nullptr and curr->right == nullptr) {
        remove_leaf(curr, parent);
    // 1 child cases
    } else if (curr->left == nullptr and curr->right != nullptr) {
        remove_one_child_right(curr, parent);
    } else if (curr->left != nullptr and curr->right == nullptr) {
        remove_one_child_left(curr, parent);
    // Node to delete has two children
    } else {
        int newValue = find_min(curr->right)->data;
        int newCount = find_min(curr->right)->count;
        if (newCount > 1)         // Ensure replacement Node is deleted
            find_min(curr->right)->count = 1;
        remove(root, nullptr, newValue);
        curr->data = newValue;
        curr->count = newCount;                    
    }
    return true;
}

/* remove_leaf
 *    Purpose: Handles the case when the Node to be removed is a leaf Node.
 * Parameters: Pointer to the current Node, pointer to the parent of the
 *             current Node
 *    Returns: None.
 */
void BinarySearchTree::remove_leaf(Node *node, Node *parent)
{
    if (node == root) {
        root = nullptr;
    } else if (parent->left == node) {
        parent->left = nullptr;
    } else {
        parent->right = nullptr;
    }
    delete node;
}

/* remove_one_child_right
 *    Purpose: Handles the case when the Node to be removed has one child
 *             in its right child.
 * Parameters: Pointer to the current Node, pointer to the parent of the
 *             current Node
 *    Returns: None.
 */
void BinarySearchTree::remove_one_child_right(Node *node, Node *parent)
{
    if (node == root) {
        root = node->right;
    } else if (parent->left == node) {
        parent->left = node->right;
    } else {
        parent->right = node->right;
    }
    delete node;
}

/* remove_one_child_left
 *    Purpose: Handles the case when the Node to be removed has one child
 *             in its left child.
 * Parameters: Pointer to the current Node, pointer to the parent of the
 *             current Node
 *    Returns: None.
 */
void BinarySearchTree::remove_one_child_left(Node *node, Node *parent)
{
    if (node == root) {
        root = node->left;
    } else if (parent->left == node) {
        parent->left = node->left;
    } else {
        parent->right = node->left;
    }
    delete node;
}

/* tree_height()
 *    Purpose: Returns the maximum distance from the root to it's farthest
 *             leaf (i.e. the height of the tree).
 * Parameters: None
 *    Returns: The maximum distance from the root to it's farthest leaf.
 *       Note: An empty tree has a height of -1, a tree with just a root has
 *             a height of 0, and a tree with a root and one or two children
 *             has a height of 1, etc.
 */
int BinarySearchTree::tree_height() const
{
    return tree_height(root);
}

/* tree_height(Node *node)
 *    Purpose: Recursive (private) function for tree_height. Determines the
 *             maximum distance from a given Node to it's farthest leaf using
 *             recursion.
 * Parameters: The Node to have its height determined
 *    Returns: The maximum distance from the given Node to it's farthest leaf.
 *       Note: Same note as for the public contains function
 */
int BinarySearchTree::tree_height(Node *node) const
{
    if (node == nullptr) {
        return -1;
    }
    return 1 + max(tree_height(node->left), tree_height(node->right));
}

/* node_count
 *    Purpose: Returns the total number of Nodes in the tree.
 * Parameters: None
 *    Returns: The total mumber of Nodes in the tree
 *       Note: The count field in the Node struct is ignored for this function.
 *             So a single number that has been inserted 10 times still counts
 *             as a single Node.
 */
int BinarySearchTree::node_count() const
{
    return node_count(root);
}

/* node_count(Node *node)
 *    Purpose: Recursive (private) function for node_count. Determines the
 *             total number of Nodes in the given tree using recursion.
 * Parameters: Pointer to the current Node
 *    Returns: Returns the total number of Nodes in the tree
 *       Note: Same note as for the public node_count function
 */
int BinarySearchTree::node_count(Node *node) const
{
    if (node == nullptr) {
        return 0;
    }
    return 1 + node_count(node->left) + node_count(node->right);
}

/* count_total()
 *    Purpose: Returns the sum of all the Node values in the tree (including
 *             duplicates).
 * Parameters: None
 *    Returns: The sum of all the node values in the tree (including
 *             duplicates).
 */
int BinarySearchTree::count_total() const
{
    return count_total(root);
}

/* count_total(Node *node)
 *    Purpose: Recursive (private) function for count_total. Determines the
 *             total number of Nodes in the given tree using recursion.
 * Parameters: Pointer to the current Node
 *    Returns: Returns the total number of Nodes in the tree
 *       Note: Same note as for the public count_total function
 */
int BinarySearchTree::count_total(Node *node) const
{
    if (node == nullptr) {
        return 0;
    }
    return (node->count * node->data) + count_total(node->left)
                                      + count_total(node->right);
}

/* newNode
 *    Purpose: Creates a new Node.
 * Parameters: A character, the pointer to the next Node, the pointer to the
 *             previous Node.
 *    Returns: The new Node.
 */
BinarySearchTree::Node *BinarySearchTree::newNode(int data, int count, 
                                                Node *left, Node *right) const
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->count = count;
    new_node->left = left;
    new_node->right = right;
    
    return new_node;
    
}

/* get(Node *node, int value)
 *    Purpose: Recursively searches the given tree for a given value and
 *             returns the Node with the value.
 * Parameters: Pointer to the current Node, the value of the Node to get
 *    Returns: The Node with the given value
 */
BinarySearchTree::Node *BinarySearchTree::get(Node *node, int value) const
{
    if (node == nullptr) {
        return nullptr;
          
    } else if (node->data == value) {
        return node;
          
    } else if (value < node->data) {
        return get(node->left, value);
          
    } else {
        return get(node->right, value);
    }
}


BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}
