/*
 * unit_tests.h
 * 
 * CS 15 homework 2, MetroSim
 * by Kirin Godhwani, 10/2/21
 *
 * Purpose: Uses Matt Russell's unit_test framework to test the MetroSim 
 * and the classes it is made up of - PassengerQueue, Passenger, MetroSim.
 * More information on this testing framework can be found in the Lab 1
 * handout.
 */

 #include <iostream>
 #include <cassert>
 #include <vector>
 #include "PassengerQueue.h"
 #include "Passenger.h"


/*
 * PassengerQueue and Passenger declaration test
 * Create an instance of PassengerQueue and make sure there are no runtime
 * errors or memory leaks
 */
void PassengerQueue_declaration()
{
    Passenger p1(1, 1, 2);
    
    PassengerQueue q;
}


/*
 * enqueue test
 * Create an instance of PassengerQueue, enqueue Passengers. Check to make 
 * sure enqueue worked properly with size(), front(), and assert().
 */
void enqueue_test()
{
    // initialize some Passengers and PassengerQueue
    Passenger p1(1, 1, 2);
    Passenger p2(2, 1, 3);
    Passenger p3(3, 1, 2);
    PassengerQueue q;
    
    // enqueue the Passengers, make sure the size updates, make sure front is
    // correct
    q.enqueue(p1);
    q.enqueue(p2);
    q.enqueue(p3);
    assert(q.size() == 3);
    assert(q.front().id == p1.id);
}

/*
 * dequeue test
 * Create an instance of PassengerQueue, enqueue Passengers, and then run
 * dequeue to remove Passengers. Check to make sure dequeue worked properly
 * with size(), front(), and assert().
 */
void dequeue_test()
{
    // initialize some Passengers and PassengerQueue
    Passenger p1(1, 1, 2);
    Passenger p2(2, 1, 3);
    Passenger p3(3, 1, 2);
    PassengerQueue q;
    
    // enqueue the Passengers, make sure the size updates, make sure front is
    // correct
    q.enqueue(p1);
    q.enqueue(p2);
    q.enqueue(p3);
    assert(q.size() == 3);
    assert(q.front().id == p1.id);
    
    // run dequeue to remove the front two passengers and make sure the
    // size updates and the front changes
    q.dequeue();
    q.dequeue();
    assert(q.front().id == p3.id);
    assert(q.size() == 1);
}


/*
 * Large PassengerQueue test and print() test
 * This test is made to test the function implementations of the 
 * PassengerQueue class as well as the print() function of the Passenger 
 * class. To do this, a series of passengers will be defined and then the 
 * PassengerQueue class's functions will be tested by adding passengers to
 * the end of the queue, accessing the passenger at the front the queue,
 * removing passengers from the front of the queue, and printing the queue. 
 * The success of these functions will be tested with size(), assert(), and 
 * print(), and print() will be tested by looking at the output in terminal.
 */
void Large_PassengerQueue_Passenger_Print()
{
    // initialize Passengers and a PassengerQueue
    Passenger p1(1, 1, 2);
    Passenger p2(2, 1, 3);
    Passenger p3(3, 1, 2);
    Passenger p4(4, 1, 4);
    Passenger p5(5, 2, 3);
    Passenger p6(6, 2, 5);
    PassengerQueue q;
    
    // Run enqueue and dequeue, use assert, size, and front to check success
    assert(q.size() == 0);
    q.enqueue(p1);
    assert(q.front().id == p1.id and q.front().from == p1.from);
    assert(q.size() == 1);
    q.enqueue(p2);
    assert(q.front().id == p1.id and q.front().to == p1.to);
    assert(q.size() == 2);
    q.enqueue(p3);
    q.enqueue(p4);
    q.enqueue(p5);
    q.enqueue(p6);
    assert(q.front().id == p1.id and q.front().from == p1.from);
    assert(q.size() == 6);
    q.dequeue();
    assert(q.front().id == p2.id and q.front().from == p2.from);
    assert(q.size() == 5);
    
    // print the final PassengerQueue with the print() function
    q.print(std::cout);
}
 