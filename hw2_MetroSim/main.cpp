/*
 * main.cpp
 * 
 * CS 15 homework 2, MetroSim
 * by Kirin Godhwani, 10/3/21
 *
 * Purpose: Handles simple driver functions such as reading in files from 
 *          the command line and outputting to output files. Also calls the
 *          public command loop in the MetroSim interface that uses MetroSim
 *          to imitate the green line.
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include "PassengerQueue.h"
#include "Passenger.h"

// for vector use
#include <vector>

using namespace std;

// function declarations 
void read_stations_data(std::string filename, MetroSim *sim);

template<typename streamtype>
void open_or_die(streamtype &stream, std::string file_name);

int main(int argc, char *argv[])
{
    if (not((argc == 3) or (argc == 4))) {
        std::cerr << "Usage: ./MetroSim stationsFile " << 
                     "outputFile [commandsFile]" << std::endl;
        exit(EXIT_FAILURE);
    } 
    // read in the file of station names and print the state of stations
    std::string filename_stations = argv[1];
    MetroSim sim;
    read_stations_data(filename_stations, &sim);
    sim.print(std::cout);
    // open the file to write output to
    std::string exitingPassengers = argv[2];
    ofstream output_file;
    open_or_die(output_file, exitingPassengers);
    // run the command loop with cin or the command loop with file input
    if (argc == 3) {
        //sim.run_command_loop(&sim, output_file, cin);
        sim.run_command_loop(output_file, cin);
    }
    if (argc == 4) {
        std::string commands = argv[3];
        ifstream input_file_2;
        open_or_die(input_file_2, commands);
        //sim.run_command_loop(&sim, output_file, input_file_2);
        sim.run_command_loop(output_file, input_file_2);
        input_file_2.close();
    }
    output_file.close();
    return 0;
}

/* read_stations_data
 *    Purpose: Opens the file containing the list of stations and then adds 
 *             them to the vector list of stations (the train line). Also
 *             closes the file.
 * Parameters: The name of the file containing the station names, the address
 *             of an instance of MetroSim
 *    Returns: Returns true if the file was read successfully, and false 
 *             if the file could not be opened.
 */
void read_stations_data(std::string filename, MetroSim *sim)
{  
    // Open File and check to make sure it was opened successfully
    ifstream input_file;
    open_or_die(input_file, filename);
    
    std::string name;
    
    // Read in the station names
    while (getline(input_file, name)) {

        sim->newStation(name);
    }
    
    input_file.close();
}

/* open_or_die
 *    Purpose: Opens a file and checks to make sure it is successfully opened
 * Parameters: The variable of file stream class (e.g. ofstream, ifstream),
 *             the file that is being opened.
 *    Returns: None
 */
template<typename streamtype>
void open_or_die(streamtype &stream, std::string file_name)
{
    stream.open(file_name);
    if (not stream.is_open()) {
        std::cerr << "Error: could not open file "
                  << file_name << std::endl;
        exit(EXIT_FAILURE);
    }
}
