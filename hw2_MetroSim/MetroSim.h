/*
 * MetroSim.h
 * 
 * CS 15 homework 2, MetroSim
 * by Kirin Godhwani, 10/3/21
 *
 * Purpose: The implementation of the MetroSim interface. Creates the train 
 * (vector of PassengerQueue objects) and the vector of Stations (Station
 * structs), and handles the public member functions used in the command loop
 * (i.e. moving to the next stop, printing the state of the simulation). Also
 * defines the Station struct which holds the information for each station
 * (a queue of passengers waiting to board the train, the name of the
 * station) and provides the function to add Stations to the train line. 
 * Both the train and the list of Stations are implemented using vectors. Also
 * creates the command loop that is called in main.cpp to simulate the green
 * line (certain command loop helper functions are defined).
 *
 * Note: The train stops and the list of stations are implemented using a
 * dynamic array (vector).
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"

// Put any other necessary includes here
#include "PassengerQueue.h"

// for vector use
#include <vector>
#include <iostream>

// Put any other structs you need here
// Struct for the list of stations
struct Station
{
    PassengerQueue board;
    std::string StationName;
    int StationNum;
};

class MetroSim
{
    public:
        // Inserts a new station at the end of the train line
        void newStation(std::string StationName);
      
        // Prints the state of the simulation, i.e. the passengers on the train
        void print(std::ostream &output);
      
        // runs the command loop
        void run_command_loop(std::ostream &output,
                                           std::istream &input);
      

    private:
    
        // Adds a passenger to the simulation
        void addPassenger(int arrival, int departure);
  
        // Moves the train to the next stop 
        void NextStop(std::ostream &output);
    
        // Returns the number of Stations on the train line, I created this
        // function because in my for loops, when I used Stations.size() in
        // the loop's condition, I was getting a warning in terminal about
        // comparing two values of different type.
        int NumStations();
    
        // Helper functions for the command loop
        std::string end_sim();
        void metro_move(std::ostream &output);
    
        // define the vector to represent the train of PassengerQueues
        std::vector<PassengerQueue> train;
    
        // define the vector to represent the list of stations 
        std::vector<Station> Stations;
    
        // holds the value of the station number the train is at
        int currStation = 1;
    
        // keeps track of the number of people in the simulator 
        int train_goers = 0;
};

#endif
