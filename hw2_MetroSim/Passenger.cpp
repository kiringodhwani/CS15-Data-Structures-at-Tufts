/*
 * Passenger.cpp
 * 
 * CS 15 homework 2, MetroSim
 * Edited by Kirin Godhwani, 10/2/21
 *
 * Purpose: Implements the public print function of the Passenger interface.
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/* print
 *    Purpose: Prints the information of a Passenger
 * Parameters: The output stream to be printed to
 *    Returns: None
 */
void Passenger::print(std::ostream &output) 
{  
      output << "[" << id << ", " << from << "->" << to << "]";
}
