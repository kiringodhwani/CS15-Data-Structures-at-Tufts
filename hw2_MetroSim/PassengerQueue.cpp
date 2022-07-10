/*
 * PassengerQueue.cpp
 * 
 * CS 15 homework 2, MetroSim
 * by Kirin Godhwani, 10/2/21
 *
 * Allows for passenger access at the front of the queue, passenger removal
 * at the front of the queue, passenger insertion at the end of the queue,
 * returning the size of the queue, and printing the queue.
 *
 * Notes: this implementation uses a dynamic array (vector). So, potential
 * drawbacks include slower insertions and removals at the front of the vector.
 * However, dynamic arrays have the advantage of more efficient memory usage
 * as compared to linked lists.
 */
 
#include "Passenger.h"
#include "PassengerQueue.h"

// for print
#include <iostream>

// for vector use 
#include <vector>

using namespace std;

/* front
 *    Purpose: Returns, but does not remove, the Passenger at the front of the 
 *             queue. Allows for element access to the front Passenger in the
 *             queue.
 * Parameters: None
 *    Returns: The Passenger at the front of the queue.
 * 
 *       Note: Does not remove the Passenger at the front of the queue, only
 *             returns it.
 *       Note: For this program, we define the first element in the vector
 *             as the end of the queue and the last element as the front
 */
Passenger PassengerQueue::front() 
{    
    // uses the built-in front() function for vectors
    return queue.back();
    
}


/* dequeue
 *    Purpose: Removes the Passenger at the front of the queue
 * Parameters: None
 *    Returns: None
 *       Note: For this program, we define the first element in the vector
 *             as the end of the queue and the last element as the front
 */
void PassengerQueue::dequeue() 
{
    // uses the built-in pop_back() function for vectors
    queue.pop_back();
    
}

/* enqueue
 *    Purpose: Inserts a new Passenger at the end of the queue
 * Parameters: The address of the Passenger to be inserted
 *    Returns: None
 *       Note: For this program, we define the first element in the vector
 *             as the end of the queue and the last element as the front
 */
void PassengerQueue::enqueue(const Passenger &passenger) 
{
    // Use the built-in insert() function for vectors to insert at the end.
    // The begin() function returns an iterator to the first element in the 
    // vector. An iterator is a pointer-like object that points to an element
    // in the vector.
    queue.insert(queue.begin(), passenger);
}

/* size
 *    Purpose: Returns the number of Passengers in the queue
 * Parameters: None
 *    Returns: The number of Passengers in the queue
 */
int PassengerQueue::size() 
{
    // uses the built-in size() function for vectors
    return queue.size();
}

/* print
 *    Purpose: Prints each Passenger in the PassengerQueue to the given 
 *             output stream from front to back, with no spaces in between
 *             and no trailing newline.
 * Parameters: The output stream to be printed to
 *    Returns: None
 */
void PassengerQueue::print(std::ostream &output) 
{
    // for loop to traverse the vector from front to back, the loop goes from
    // the last element to the first because I defined the last element as 
    // the front of the list
    for (int i = size() - 1; i >= 0; i--) {
        
        // use the at() function for vectors to access the individual 
        // elements and use the print() function for the Passenger interface
        // to print 
        queue.at(i).print(output);
    }
}


