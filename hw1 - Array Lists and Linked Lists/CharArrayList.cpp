/*
 * CharArrayList.cpp
 * 
 * COMP 15 homework 1
 * by C.R. Calabrese, January 2021
 * edited by Kirin Godhwani, 9/26
 * 
 * Stores characters in a certain order. It imitates some functions of the
 * C++ string. 
 * 
 * Notes: this implementation uses a dynamic array. So, potential
 * drawbacks as compared to the CharLinkedList class include slower insertions
 * and removals at the front of the list. On the other hand, since only one
 * pointer variable is needed for the entire list (as opposed to one pointer
 * per element in the CharLinkedList), the CharArrayList class has the
 * advantage of more efficient memory usage over the CharLinkedList.
 *
 */

#include "CharArrayList.h"

// for print
#include <iostream>

using namespace std;

/* Purpose: initializes an empty CharArrayList */
CharArrayList::CharArrayList()
{
    len  = 0;
    cap  = INITIAL_CAPACITY;
    data = nullptr;
}

/*    Purpose: initializes a CharArrayList containing one character
 * Parameters: the character that should be stored in the new list
 */
CharArrayList::CharArrayList(char c)
{
    data = new char[INITIAL_CAPACITY];
    len = 1;
    cap = INITIAL_CAPACITY;
    data[0] = c;
}

/*    Purpose: initializes a CharArrayList containing all of the specified 
 *             characters, in the given order
 * Parameters: An array (in order) of characters to be stored in the list;
 *             the length of the given array (as an int)
 */
CharArrayList::CharArrayList(char *arr, int size)
{
    data = new char[INITIAL_CAPACITY];
    len = 0;
    cap = INITIAL_CAPACITY;
    
    // copies the given array to the CharArrayList and updates the length
    for (int i = 0; i < size; i++) {
        // expand the array list if the current length is equal to its capacity
        if (len == cap) {
            expand();
        }
        // copy the elements and update the length
        data[i] = arr[i];
        len++;
    }  
}

/* Purpose: copy constructor -- creates a list with the same information as
 *          the one passed in
 * 
 *    Note: The array capacity may be different from the capacity of the list
 *          that is copied from. That is fine. What is important is that both
 *          lists will store the same information -- to the client, they will
 *          be the same.
 * 
 */
CharArrayList::CharArrayList(const CharArrayList &other) 
{
    len = 0; // start with an empty list
    cap = 0;
    data = nullptr;

    // push each item from the other list onto this one
    for (int i = 0; i < other.size(); i++) {
        pushAtBack(other.elementAt(i));
    }
}

/* Purpose: destructor -- frees all memory associated with the list */
CharArrayList::~CharArrayList()
{
    delete [] data;
    data = nullptr;
}

/* Purpose: assignment operator -- makes the current list contain the same
 *          information as the one on the right hand side
 * 
 *    Note: The array capacity may be different from the list that is being
 *          copied from.
 * 
 */
CharArrayList &CharArrayList::operator =(const CharArrayList &rhs) 
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
 * 
 *       Note: "empty" refers to if the client is currently storing any
 *             information in the list. The capacity of the ArrayList is
 *             irrelevant.
 */
bool CharArrayList::isEmpty() const 
{
    return size() == 0;
}

/* size
 *    Purpose: Get the number of characters being stored in the list
 * Parameters: none
 *    Returns: The number of characters currently stored in the list, as an
 *             int (but will never be negative)
 */
int CharArrayList::size() const 
{
    return len;
}

/* first
 *    Purpose: Get the first element in the list.
 * Parameters: none
 *    Returns: The first element in the list, as a char.
 * 
 *       Note: Prints an error and exits if the list is empty.
 */
char CharArrayList::first() const 
{
    // if statement to confirm list is non-empty
    if (isEmpty()) {
        cerr << "Cannot get the first element of an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    return data[0];
}

/* last
 *    Purpose: Get the last element in the list.
 * Parameters: none
 *    Returns: The last element in the list, as a char.
 * 
 *       Note: prints an error and exits if the list is empty.
 */
char CharArrayList::last() const 
{
    // if statement to confirm list is non-empty
    if (isEmpty()) {
        cerr << "Cannot get the last element of an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    return data[len - 1];
}

/* elementAt
 *    Purpose: Get the character at a given position.
 * Parameters: The index to be accessed, as an int. Should be in bounds; in 
 *             other words, should be in the range [0, size() )
 *    Returns: The element at the specified index, as a char
 *
 *       Note: prints an error and exits if given index is out of range.
 */
char CharArrayList::elementAt(int idx) const
{
    // if statement to confirm the given index is within the bounds of the 
    // list
    if (idx >= 0 and idx < size()) {
        return data[idx];
        
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
 * 
 */
void CharArrayList::print() const
{
    cout << "[CharArrayList of size " << size() <<  " <<";

    for (int i = 0; i < size(); i++) {
            cout << elementAt(i);
    }

    cout << ">>]" << endl;
}

/* clear
 *    Purpose: Makes the list empty
 * Parameters: None
 *    Returns: None
 */
void CharArrayList::clear() 
{
    // create a new, empty array list
    char *new_data = new char [0]; 
    
    // replace the old array list with the new, empty one
    delete [] data;
    data = new_data;
    len = 0;
    cap = 0;
}

/* pushAtBack
 *    Purpose: Adds a character to the back of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharArrayList::pushAtBack(char c)
{
    // expand the array list if the current length is equal to its capacity
    if (len == cap) {
        expand();
    }
      
    // condition for when pushAtBack is called on an empty list created by
    // the default constructor 
    if (data == nullptr) {
        
        pushAtFront(c);
        return;
    }

    // add the character to the back of the list and add one to the length
    data[len] = c;
    len++;
}

/* pushAtFront
 *    Purpose: Adds a character to the front of the list
 * Parameters: The character to be added to the list
 *    Returns: None
 */
void CharArrayList::pushAtFront(char c)
{
    // expand the array list if the current length is equal to its capacity
    if (len == cap) {
        expand();
    }
    
    // create a new array list and copy in the old array list's elements
    // after the addition of the character at the front of the list
    char *new_data = new char [cap];
    
    new_data[0] = c;
    
    for (int i = 0; i < len; i++) {
        new_data[i + 1] = data[i];
    }
    
    // replace the old array list with the new one, update the length
    delete [] data;
    data = new_data;
    len++;    
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
 */
void CharArrayList::insertAt(char c, int idx)
{
    // expand the array list if the current length is equal to its capacity
    if (len == cap) {
        expand();
    }
    // confirm the given index is within the bounds of the list
    if (idx < 0 or idx > size()) {
        cerr << "index " << idx << " not in range [0.." << size() << "]" 
             << endl;
        exit(EXIT_FAILURE);
    }
    // create a new array list and copy in the old elements based on the
    // position of the newly inserted character
    char *new_data = new char [cap];  
    new_data[idx] = c;
    
    for (int i = 0; i < idx; i++) {
        new_data[i] = data[i];
    }
    
    for (int i = idx; i < len; i++) {
        new_data[i + 1] = data[i];
    }
    
    // replace the old array list with the new one, update the length
    delete [] data;
    data = new_data;
    len++;     
}

/* popFromFront
 *    Purpose: Removes the first element from the list
 * Parameters: None
 *    Returns: None
 *
 *       Note: Prints an error message and quits if the list is empty
 */
void CharArrayList::popFromFront()
{
    // confirm list is non-empty
    if (isEmpty()) {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    removeAt(0);
}

/* popFromBack
 *    Purpose: Removes the last element from the list
 * Parameters: None
 *    Returns: None
 * 
 *       Note: Prints an error message and exits if the list is empty
 */
void CharArrayList::popFromBack()
{
    // confirm list is non-empty
    if (isEmpty()) {
        cerr << "Cannot pop from an empty list" << endl;
        exit(EXIT_FAILURE);
    }
    removeAt(size() - 1);
}

/* removeAt
 *    Purpose: Removes the element at a given index
 * Parameters: The position at which to remove an element, which should be the
 *             index of an element currently in the list; in other words,
 *             should be in the interval [0, size)
 *    Returns: None
 * 
 *       Note: If the amount of space in the array that is in use drops to less 
 *             than one fourth, the array should be shrunk to half its size.
 */
void CharArrayList::removeAt(int idx)
{
    // confirm index is in range
    if (idx < 0 or idx >= size()) {
        cerr << "index " << idx << " not in range [0.." << size() << ")"
             << endl;
        exit(EXIT_FAILURE);
    }
    // remove the element by shifting all subsequent elements to the left
    for (int i = idx; i < size() - 1; i++) {
        data[i] = data[i + 1];
    }
    // update the length
    len--;

    // shrink the array if appropriate
    if (len < (cap / 4)) {
        shrink();
    }
}

/* replaceAt
 *    Purpose: Replaces the element at the given index with the given value
 * Parameters: A character to put in the list and the index of the
 *             element to replace. The index should be in-bounds, in the
 *             range [0, size() )
 * 
 *       Note: Prints an error message and exits if the index is out of bounds
 */
void CharArrayList::replaceAt(char c, int idx)
{
    // confirm the given index is within the bounds of the list
    if (idx < 0 or idx >= size()) {
        cerr << "index " << idx << " not in range [0.." << size() << ")" 
             << endl;
        exit(EXIT_FAILURE);
    }
    
    // replace the element at the given index with the given value
    data[idx] = c;
}

/* concatenate
 *    Purpose: Adds the contents of a CharArrayList to the back of the current 
 *             one.
 * Parameters: A CharArrayList whose contents should be pushed to the back of
 *             the current list. Will not be altered
 *    Returns: None
 */
void CharArrayList::concatenate(const CharArrayList &other)
{
    // copy the given CharArrayList's elements to the current one
    for (int i = 0; i < other.size(); i++) {
        // expand the array list if the current length is equal to its 
        // capacity
        
        //if (len == cap) {
        //    expand();
        //}
        
        // copy the contents of the given CharArrayList to the back of the
        // current one and update the length each time an element is added
        //data[len] = other.data[i];
        //len++;
        pushAtBack(other.data[i]);
    }
}

/* expand
 *    Purpose: Increases/expands the capacity of the array list by 2 * current
 *             capacity + 2 each time the array list reaches its capacity
 * Parameters: None
 *    Returns: None
 */
void CharArrayList::expand()
{
    char *new_data = new char [2 * cap + 2];
    
    for (int i = 0; i < len; i++) {
        new_data[i] = data[i];
    }
        
    delete [] data;
    data = new_data;
    cap = 2 * cap + 2;
}

/* shrink
 *    Purpose: shrinks the array list when its size falls below 1/4 of its 
 *             capacity by subtracting 2 and then dividing by 2
 * Parameters: None
 *    Returns: None
 */
void CharArrayList::shrink()
{
    char *new_data = new char [(cap - 2) / 2];
    
    for (int i = 0; i < len; i++) {
        new_data[i] = data[i];
    }
    
    delete [] data;
    data = new_data;
    cap = (cap - 2) / 2;
}

/* return_cap
 *    Purpose: Get the total capacity of the list (the capacity not the 
 *             length)
 * Parameters: none
 *    Returns: The total capacity of the list.
 */
//int CharArrayList::return_cap() const 
//{
//    return cap;
//}
