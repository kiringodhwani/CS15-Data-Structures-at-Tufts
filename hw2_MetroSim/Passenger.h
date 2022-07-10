/*
 * Passenger.h
 * 
 * CS 15 homework 2, MetroSim
 * Edited by Kirin Godhwani, 10/2/21
 *
 * Purpose: The implementation of the Passenger interface. Defines the 
 * Passenger struct which consists of an id, an arrival station, and a
 * departure station. Defines and implements a default constructor and second
 * constructor to declare Passengers. The second constructor allows for the 
 * declaration of Passenger with a specific id, arrival station, and
 * departure station. Also includes a public print function to print out the
 * details of a Passenger.
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }


        void print(std::ostream &output);

};

#endif
