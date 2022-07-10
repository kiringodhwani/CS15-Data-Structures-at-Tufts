/*
 * MetroSim.cpp
 * 
 * CS 15 homework 2, MetroSim
 * by Kirin Godhwani, 10/3/21
 *
 * Allows for access to the next train stop, station addition at the end of
 * the train line, passenger insertion onto the train, printing the state of
 * the train simulation, and moving the train to the next stop and dealing
 * with Passengers getting on and off of the train. Also implements the
 * command loop function that is called in main.cpp to simulate the green
 * line. Implements certain helper functions for the command loop.
 *
 * Notes: this implementation uses a dynamic array (vector). So, potential
 * drawbacks include slower insertions and removals at the front of the vector.
 * However, dynamic arrays have the advantage of more efficient memory usage
 * as compared to linked lists.
 */

#include "MetroSim.h"
#include "PassengerQueue.h"
#include "Passenger.h"

// for vector use
#include <vector>
#include <iostream>

// to access the characters in a string 
#include <string>

/* newStation
 *    Purpose: Inserts a new station to the list of stations
 * Parameters: The name of the station
 *    Returns: None
 */
void MetroSim::newStation(std::string StationName) 
{
    Station S;
    S.StationName = StationName;
    S.StationNum = NumStations() + 1;
    
    // Use the built-in insert() function for vectors to insert at the end.
    // The begin() function returns an iterator to the first element in the 
    // vector. An iterator is a pointer-like object that points to an element
    // in the vector.
    Stations.insert(Stations.begin(), S);
    
    // add a PassengerQueue to the train vector to represent the new Station
    PassengerQueue pq;
    train.push_back(pq);  
}

/* NumStations
 *    Purpose: Returns the number of Stations on the train line.
 * Parameters: None.
 *    Returns: The number of Stations on the train line.
 *       Note: I created this function because in my for loops, when I used 
 *             Stations.size() in the loop's condition, I was getting a
 *             warning in terminal about comparing two values of different
 *             type.
 */
int MetroSim::NumStations() {

    return Stations.size();
}

/* addPassenger
 *    Purpose: Adds a new Passenger to the simulation who boards at "arrival"
 *             and departs at "departure". These values are specified
 *             by numbers (e.g. Station 1). Passengers are enqueued at the
 *             arrival station. Passengers get consecutive IDs assigned in
 *             the order they arrive starting with the number 1.
 * Parameters: None
 *    Returns: None
 * 
 *       Note: You may assume that arrival and departure will be different.
 */
void MetroSim::addPassenger(int arrival, int departure)
{
    // initialize the Passenger to be added, set its arrival and departure 
    Passenger p;
    p.from = arrival;
    p.to = departure;
    
    for (int i = 0; i < NumStations(); i++) {
        
        // Find the Station with the name equal to the new Passenger's arrival
        if (Stations.at(i).StationNum == arrival) {

            // When the unique station is found, set the Passenger ID of the
            // new Passenger and add the new Passenger to the Station's queue
            p.id = train_goers + 1;
            Stations.at(i).board.enqueue(p);
            
            // update the number of train goers in the simulation
            train_goers++;
        } 
    }    
}

/* NextStop
 *    Purpose: Moves the train from its current stop to the next stop in line,
 *             handles the metro move command in the command loop. All
 *             Passengers at the departing station get on the train in the same
 *             order as they arrived at that Station. When the Train arrives
 *             at the next Station, any Passengers whose final destination is
 *             that Station will exit the Train and will be removed from the
 *             simulator. For each Passenger that exits at a Station, the
 *             following line will be written to the output file followed
 *             by a single newline:
 *             Passenger ID left train at station STATION_NAME
 * Parameters: None
 *    Returns: None
 * 
 */
void MetroSim::NextStop(std::ostream &output)
{
    int stationIndex = NumStations() - currStation;
    int currSize = Stations.at(stationIndex).board.size();
    // Loop through the PassengerQueue at the current Station
    for (int i = 0; i < currSize; i++) {  
        int depF = Stations.at(stationIndex).board.front().to;
        
        // Add the Passenger at the train PassengerQueue index corresponding
        // to its departure station and remove them from the current station
        train.at(depF - 1).enqueue(Stations.at(stationIndex).board.front());
        Stations.at(stationIndex).board.dequeue();
    }   
    // If the train was at the last stop, move it to the first stop
    if (currStation == NumStations()) {
        currStation = 1;  
    // else, train moves to the next stop 
    } else {
        currStation++;
    } 
    // All passengers departing at the new stop get off, print them to output
    int numDepartingPass = train.at(currStation - 1).size();
    for (int i = 0; i < numDepartingPass; i++) {
        output << "Passenger " << train.at(currStation - 1).front().id
               << " left train at station " << 
                  Stations.at(NumStations() - currStation).StationName << "\n";
        
        train.at(currStation - 1).dequeue();
    }    
}


/* addPassenger
 *    Purpose: Prints the state of the simulation in the form described in 
 *             the "Printing the State of the Simulation" section of the lab
 *             spec.
 * Parameters: The instance of MetroSim to be printed and the output stream
 *             to be printed to.
 *    Returns: None
 */
void MetroSim::print(std::ostream &output)
{
    output << "Passengers on the train: {";
    
    // print the passengers on the train
    for (int i = 0; i < NumStations(); i++) {
        if (train.at(i).size() != 0) {
            train.at(i).print(output);
        }
    }
    output << "}\n";
    // print the stations
    for (int i = NumStations() - 1; i >= 0; i--) {
        // the output changes if the train is at the stop
        if (currStation == Stations.at(i).StationNum) {
            output << "TRAIN: ";
            
        } else {
            output << "       "; 
        }  
        output << "[" << Stations.at(i).StationNum << "] "
               << Stations.at(i).StationName << " {"; 
               
        Stations.at(i).board.print(output);
        
        output << "}\n";
    }
}

/* run_command_loop
 *    Purpose: Runs a command loop that simulates the train line using the 
 *             MetroSim member functions and by taking in commands from a
 *             command file or cin.
 * Parameters: The output file and the place commands are being received
 *             from (cin or a command file).
 *    Returns: None.
 */
void MetroSim::run_command_loop(std::ostream &output, std::istream &input)
{
    std::string cmd, move_finish;
    int user_arrival, user_departure;
    do {
        std::cout << "Command? ";
        input >> cmd;
        if (input.eof()) {
            cmd = end_sim();
        }
        // p ARRIVAL DEPARTURE
        if (cmd == "p") {
            input >> user_arrival >> user_departure;
            addPassenger(user_arrival, user_departure);
            print(std::cout);
        // m m (metro move) or m f (metro finish)
        } else if (cmd == "m") {
            input >> move_finish;
            if (move_finish == "m") {
                metro_move(output);
            }
            if (move_finish == "f") {
                cmd = end_sim();
            }
        } else if (cmd == "mm") {
            metro_move(output);
        } else if (cmd == "mf") {
            cmd = end_sim();
        }      
    } while (cmd != "end");          
}

/* end_sim
 *    Purpose: Helper function to the command loop function that prints the
 *             necessary lines to std::cout when the simulation is to be
 *             ended. Also returns the value the command should be to end
 *             the simulation.
 * Parameters: None.
 *    Returns: "end", which is the value the command must be set to to end the
 *             simulation.
 */
std::string MetroSim::end_sim()
{
    std::cout << "Thanks for playing MetroSim. Have a nice day!";
    std::cout << std::endl;
    
    std::string end = "end";
    
    return end;
}

/* metro_move
 *    Purpose: Helper function to the command loop function that runs the
 *             necessary functions to move the train to the next Station.
 * Parameters: The output file to be printed to;.
 *    Returns: None.
 */
void MetroSim::metro_move(std::ostream &output)
{
    NextStop(output);
    print(std::cout);
}
