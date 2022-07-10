/*
 * PassengerQueue.h
 * 
 * CS 15 homework 2, MetroSim
 * by Kirin Godhwani, 10/2/21
 *
 * Purpose: The implementation of the PassengerQueue interface. Upon boarding
 * the train, Passengers are assigned to a PassengerQueue vector list based on
 * their destination. The train is represented by a list of PassengerQueue
 * objects where each PassengerQueue represents a train station. The
 * PassengerQueue class provides multiple public member functions that can be
 * used to access members in the queue, remove members from the queue, and
 * add members to the queue. 
 *
 * Note: This is implemented using a dynamic array (vector).
 *
 */

#ifndef __PASSENGER_QUEUE_H__
#define __PASSENGER_QUEUE_H__
 

#include "Passenger.h"

// for vector use
#include <vector>
#include <iostream>

class PassengerQueue {
    public:
        // Returns, but does not remove, the Passenger at the front of the
        // queue
        Passenger front();
        
        // Removes the Passenger at the front of the queue
        void dequeue();
        
        // Inserts a new Passenger at the end of the queue
        void enqueue(const Passenger &passenger);
        
        // Returns the number of Passengers in the queue
        int size();
        
        // Prints each Passenger in the PassengerQueue to the given output
        // stream from front to back, with no spaces in between and no
        // trailing newline.
        void print(std::ostream &output);
    
    private:
        
        // define the vector to be used to store the list of Passengers
        std::vector<Passenger> queue;
};

#endif