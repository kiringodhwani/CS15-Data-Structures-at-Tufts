/* 
 * CharLinkedList.cpp
 * 
 * COMP 15 homework 1
 * by C.R. Calabrese, January 2021
 * edited by Kirin Godhwani, 9/26
 * 
 * Stores characters in a certain order. It imitates some functions of the
 * C++ string. 
 * 
 * NOTE: This is implemented using a doubly-linked list. It is not circular
 *       and does not have a "back" pointer.
 */

#include "CharLinkedList.h"

// for the print function
#include <iostream>

using namespace std;

/* Purpose: initializes an empty CharLinkedList */
CharLinkedList::CharLinkedList()
{
    front = nullptr;
    numElements = 0;
}

/*    Purpose: initializes a CharLinkedList containing one character
 * Parameters: the character that should be stored in the new list
 */
CharLinkedList::CharLinkedList(char c)
{
    front = newNode(c, nullptr, nullptr);
    numElements = 1;
}

/*    Purpose: initializes a CharLinkedList containing all of the specified 
 *             characters, in the given order
 * Parameters: An array (in order) of characters to be stored in the list;
 *             the length of the given array (as an int)
 */
CharLinkedList::CharLinkedList(char *arr, int size)
{
    numElements = 0;
    
    // initialize a list of one using the first character in the array
    if (size == 0) {
        return;
    }
    Node *curr = newNode(arr[0], nullptr, nullptr);
    front = curr;
    numElements++;
    
    // loop through the array of characters
    for (int i = 1; i < size; i++) {
        
        // create the next Node
        curr->next = newNode(arr[i], curr->next, curr);
        
        // updating the value of curr to the next Node
        curr = curr->next;

        // update the length of the list
        numElements++;
    }
}

/* Purpose: copy constructor -- creates a list with the same information as
 *          the one passed in
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) 
{
    numElements = 0; // start with an empty list
    front = nullptr;

    // push each item from the other list onto this one
    for (int i = 0; i < other.size(); i++) {
        pushAtBack(other.elementAt(i));
    }
}

/* Purpose: destructor -- frees all memory associated with the list */
CharLinkedList::~CharLinkedList()
{
    recycleRecursive(front);
}

/* recycleRecursive
 *    Purpose: The recursive function for the destructor (wrapper function).
 *             This function recursively loops through the list and recycles 
 *             the data. 
 * Parameters: Takes in the Node for it to start recycling from.
 *    Returns: Nothing
 */
void CharLinkedList::recycleRecursive(Node *curr)
{
    if (curr == nullptr) {
        // If the current Node is empty, return
        return;
        
    } else {
        // move to the next node and delete the current one
        recycleRecursive(curr->next);
        delete curr;
    }
}
/* Purpose: assignment operator -- makes the current list contain the same
 *          information as the one on the right hand side
 */
CharLinkedList &CharLinkedList::operator =(const CharLinkedList &rhs) 
{
    if (this != &rhs) {
        clear(); // clear the current list
      
        // add each element from the other list into this one
        for (int i = 0; i < rhs.size(); i++) {
            pushAtBack(rhs.elementAt(i));
        }
    }
    return *this;
}

/* isEmpty
 *    Purpose: Check if the list is empty
 * Parameters: none
 *    Returns: a boolean -- true if the list is empty, false if it isn't
 */
bool CharLinkedList::isEmpty() const 
{
    return size() == 0;
}

/* size
 *    Purpose: Get the number of characters being stored in the list
 * Parameters: none
 *    Returns: The number of characters currently stored in the list, as an
 *             int (will never be negative)
 */
int CharLinkedList::size() const 
{
    return numElements; // numElements is the private member variable I
                        // defined to account for the number of elements in
                        // the list
}

/* first
 *    Purpose: Get the first element in the list.
 * Parameters: none
 *    Returns: The first element in the list, as a char.
 * 
 *       Note: Prints an error message and exits if the list is empty.
 */
char CharLinkedList::first() const 
{
    // if statement to confirm list is non-empty
    if (isEmpty()) {
        cerr << "Cannot get the first element of an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    
    // use elementAt() to return the first element
    return elementAt(0);
}

/* last
 *    Purpose: Get the last element in the list.
 * Parameters: none
 *    Returns: The last element in the list, as a char.
 * 
 *       Note: Prints an error message and exits if the list is empty.
 */
char CharLinkedList::last() const 
{
    // if statement to confirm list is non-empty
    if (isEmpty()) {
        cerr << "Cannot get the last element of an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    
    // use elementAt() to return the last element
    return elementAt(size() - 1);
}

/* elementAt
 *    Purpose: Get the character at a given position.
 * Parameters: The index to be accessed, as an int. Should be in bounds; in 
 *             other words, should be in the range [0, size() )
 *    Returns: The element at the specified index, as a char
 *
 *       Note: prints an error and exits if given index is out of range.
 */
char CharLinkedList::elementAt(int idx) const
{
    // if statement to confirm the given index is within the bounds of the 
    // list
    if (idx >= 0 and idx < size()) {
        
        // create a Node we can use to traverse the list
        Node *curr = front;
        
        // loop through the linked list until the Node at the given index is 
        // reached
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        return curr->c;
        
    } else {
      
        cerr << "index " << idx << " not in range [0.." << size() << ")" 
             << endl;
        exit(EXIT_FAILURE);
    }
}

/* print
 *    Purpose: Prints the list to the terminal (cout)
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::print() const
{
    cout << "[CharLinkedList of size " << numElements << " <<";
    
    // call the recursive function to print the full list
    printRecHelper(front);
    
    cout << ">>]" << endl;
}

/* printRecHelper
 *    Purpose: The recursive function for the print() function. This
 *             function recursively loops through the list from a given 
 *             starting point and prints the data.
 * Parameters: Takes in the Node for it to start printing from
 *    Returns: Nothing
 */
void CharLinkedList::printRecHelper(Node *curr) const
{    
    if (curr == nullptr) {
        // if the current Node is empty, print nothing
        cout << "";
        return;
        
    } else {
        // print the current node's character and move to the next Node
        cout << curr->c;
        printRecHelper(curr->next);
    }
}

/* clear
 *    Purpose: Makes the list empty
 * Parameters: None
 *    Returns: None
 */
void CharLinkedList::clear() 
{
  
    // if the list is already empty, just return
    if (front == nullptr) {
        return;
    }
    // declare a Node we can use to hold a place in the list while 
    // front traverses the list
    Node *curr;
    
    // if the list is not empty, traverse the array and clear the elements
    while (front != nullptr) {
        
        curr = front;
        front = front->next;
        delete curr;
        
        numElements--;    
    }
    
    
}

/* pushAtBack
 *    Purpose: Adds a character to the back of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtBack(char c)
{
  /*
    // if the list is empty, call pushAtFront() to add the new element at the
    // beginning of the list and then return size() == 0
    if (front == nullptr) {
        pushAtFront(c);
        return;
    }
    
    // declare a Node we can use to traverse the list
    Node *curr = front;
    
    // loop through the array until the last Node is reached
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    
    // add the new Node to the back of the list
    curr->next = newNode(c, nullptr, curr);

    numElements++;
    */
    // All of the above code exists in insertAt() so I changed the code to
    // just call that.
    insertAt(c, size());
}

/* pushAtFront
 *    Purpose: Adds a character to the front of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharLinkedList::pushAtFront(char c)
{
    front = newNode(c, front, nullptr);
    
    // set the previous pointer of the Node after the inserted Node to the 
    // inserted Node as long as it doesn't equal nullptr;
    if (front->next != nullptr) {
        front->next->prev = front;
    }
    // update the length of the list
    numElements++;
    
}

/* insertAt
 *    Purpose: Adds a character to the list at a given position
 * Parameters: The character to be added to the list and the position at which
 *             it should be added. The position should be in-bounds, that is,
 *             in the range [0, size()]. Providing size() as the index will
 *             insert the character at the back of the list.
 *    Returns: None
 *
 *       Note: prints an error and exits if given index is out of range.
 * 
 */
void CharLinkedList::insertAt(char c, int idx)
{
    // confirm the given index is within the bounds of the list
    if (idx < 0 or idx > size()) {
        cerr << "index " << idx << " not in range [0.." << size() << "]" 
             << endl;
        exit(EXIT_FAILURE);
    }
    // if the given position is the first index, use front()
    if (idx == 0) {
        pushAtFront(c);
        return;
    }
    
    // declare a Node we can use to traverse the list
    Node *curr = front;
    
    // traverse the list until the Node before the index is reached
    for (int i = 0; i < idx - 1; i++) {
        curr = curr->next;
    }    
    // add the new Node at the provided index (one after the Node we 
    // traversed to with the for loop)
    curr->next = newNode(c, curr->next, curr);
    
    // set the previous pointer of the Node after the inserted Node to the 
    // inserted Node if the Node after is not equal to nullptr
    if (curr->next->next != nullptr) {
        curr->next->next->prev = curr->next;
    }
    numElements++;    
}

/* popFromFront
 *    Purpose: Removes the first element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromFront()
{
    // confirm list is non-empty
    if (isEmpty()) {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }  
    // set a Node equal to front
    Node *curr = front;
    
    // move to the next Node
    front = curr->next;
    delete curr;
    
    // set the previous Node of what front is pointing to to nullptr if
    // front is pointing to a Node
    if (front != nullptr) {
        front->prev = nullptr;
    }
    numElements--;
}

/* popFromBack
 *    Purpose: Removes the last element from the list
 * Parameters: None
 *    Returns: None
 *       Note: Prints an error message and exits if the list is empty
 */
void CharLinkedList::popFromBack()
{
    // confirm list is non-empty
    if (isEmpty()) {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    
    // use removeAt() to remove the last element
    removeAt(size() - 1);
}

/* removeAt
 *    Purpose: Removes the element at a given index
 * Parameters: The position at which to remove an element, which should be the
 *             index of an element currently in the list; in other words,
 *             should be in the interval [0, size)
 *    Returns: None
 */
void CharLinkedList::removeAt(int idx)
{
    // confirm index is in range
    if (idx < 0 or idx >= size()) {
        cerr << "index " << idx << " not in range [0.." << size() << ")"
             << endl;
        exit(EXIT_FAILURE);
    }
    // when the first element is the one to be removed
    if (idx == 0) {
        popFromFront();
        return;
    }  
    // create a Node to traverse the list and a Node to be behind it
    Node *curr = front;
    Node *behind;
  
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
        behind = curr->prev;
    }
    
    // remove the Node at the index
    Node *after = curr->next;
    behind->next = after;
    if (after != nullptr) {
        after->prev = behind;
    }
    delete curr;
    numElements--;
}

/* replaceAt
 *    Purpose: Replaces the element at the given index with the given value
 * Parameters: A character to put in the list and the index of the
 *             element to replace. The index should be in-bounds, in the
 *             range [0, size() )
 *       Note: Prints an error message and exits if the index is out of bounds
 */
void CharLinkedList::replaceAt(char c, int idx)
{
    // confirm the given index is within the bounds of the list
    if (idx < 0 or idx >= size()) {
        cerr << "index " << idx << " not in range [0.." << size() << ")" 
             << endl;
        exit(EXIT_FAILURE);
    }
    // create a Node we can use to traverse the list
    Node *curr = front;
    
    // loop through the linked list until the Node at the given index is 
    // reached
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->c = c;
    
}

/* concatenate
 *    Purpose: Adds the contents of a CharLinkedList to the back of the current 
 *             one.
 * Parameters: A CharLinkedList whose contents should be pushed to the back of 
 *             the current list. Will not be altered
 *    Returns: None
 */
void CharLinkedList::concatenate(const CharLinkedList &other)
{
    for (int i = 0; i < other.size(); i++) {
        pushAtBack(other.elementAt(i));
    }
}

/* newNode
 *    Purpose: Creates a new Node.
 * Parameters: A character, the pointer to the next Node, the pointer to the
 *             previous Node.
 *    Returns: The new Node.
 */
CharLinkedList::Node *CharLinkedList::newNode(char c, 
                                              Node *next, Node *prev)
{   
    // create the new Node and assign the given data
    Node *new_node = new Node;
    new_node->c = c;
    new_node->next = next;
    new_node->prev = prev;

    return new_node;
}
