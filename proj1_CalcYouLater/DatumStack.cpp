/*
 * DatumStack.cpp
 * 
 * CS 15 project 1, CalcYouLater
 * by Kirin Godhwani, 10/14/21
 *
 * Purpose: Implementation of the DatumStack class's member functions. Allows
 * for the construction of instances of the DatumStack stack
 * when given no parameters or an array of Datum, clearing the stack to
 * create an empty stack, returning the number of elements in the stack,
 * returning the top element in the stack, removing the top element in the
 * stack, and adding an element to the top of the stack. The stack is
 * composed of instances of Datum so each element is of the Datum class.
 *
 * Note: This implementation uses a dynamic array (vector), so the end of the
 * vector is defined as the front of the stack. This makes it so that push()
 * and pop() both act on the end of the vector, and insertion and deletion
 * at the end of a dynamic array is not expensive - it is O(1).
 */
 
#include "Datum.h"
#include "DatumStack.h"


#include <iostream>

// for vector use 
#include <vector>

/* default constructor
 *    Purpose: initializes an empty DatumStack stack.
 */
DatumStack::DatumStack()
{
    // no code is written here because nothing needs to be initialized 
}

/* second constructor
 *    Purpose: constructor that takes an array of Datum and an integer
 *             specifying the size of the array creates a stack initialized
 *             so that the elements of the array are on the stack with the
 *             array’s element 0 pushed on first and it’s (size - 1)th element
 *             at the top of the stack.
 * Parameters: an array of Datum and an integer specifying the size of the
 *             array
 *    Returns: the DatumStack stack
 */
DatumStack::DatumStack(Datum *arr, int size)
{
    // adds the given elements in the Datum array to the back of the stack
    // so that the 0th element of the array is pushed on first and the
    // (size - 1)th element ends up at the top of the stack.
    for (int i = 0; i < size; i++) {
      
        // use the push() function to add the element at the front of the stack
        push(arr[i]);
      
    }
}

/* isEmpty
 *    Purpose: Check if the stack is empty.
 * Parameters: none
 *    Returns: a boolean -- true if the list is empty, false if it isn't
 */
bool DatumStack::isEmpty()
{
    return size() == 0;
}

/* size
 *    Purpose: Returns the number of Datum elements in the stack.
 * Parameters: None
 *    Returns: The number of Datum elements in the stack
 */
int DatumStack::size() 
{
    // uses the built-in size() function for vectors
    return stack.size();
}

/* clear
 *    Purpose: Makes the current stack into an empty stack.
 * Parameters: None
 *    Returns: None
 */
void DatumStack::clear()
{
    // uses the built-in clear() function for vectors
    stack.clear();
}

/* top
 *    Purpose: Returns the top Datum element on the stack.
 * Parameters: None
 *    Returns: The top Datum element on the stack
 *
 *       Notes: Does not remove the top element from the stack. If the stack
 *              is empty, it throws a std::runtime_error exception with the
 *              message “empty stack”.
 */
Datum DatumStack::top()
{
    // If the stack is empty, throws a std::runtime_error exception with the
    // message “empty stack”.
    if (isEmpty()) {
        throw std::runtime_error("empty_stack");
    }
    return stack.back();
}

/* pop
 *    Purpose: Removes the top Datum element on the stack.
 * Parameters: None
 *    Returns: None
 *
 *       Notes: Does not return the element. If the stack is empty it throws
 *              a std::runtime_error exception with the message “empty stack”.
 */
void DatumStack::pop()
{
    // If the stack is empty, throws a std::runtime_error exception with the
    // message “empty stack”.
    if (isEmpty()) {
        throw std::runtime_error("empty_stack");
    }
    stack.pop_back();
}

/* push
 *    Purpose: Takes a Datum element and puts it on the top of
 *             the stack.
 * Parameters: The Datum element to be pushed onto the top of the stack
 *    Returns: None
 */
void DatumStack::push(const Datum &datum)
{
    // uses the built-in push_back function in the vector library
    stack.push_back(datum);
}

/* debug_print
 *    Purpose: Prints the current stack. Used for debugging.
 * Parameters: None
 *    Returns: None
 *
 *       Note: This is not a function required by the spec
 */
void DatumStack::debug_print()
{
    std::cout << "Bottom ";
    
    // traverse the stack and print each element 
    for (int i = 0; i < size(); i++) {
      
        // use the toString() function for Datum to allow for printing
        std::cout << "[" << stack.at(i).toString() << "]";
    }
    std::cout << " Top" << std::endl;
}

