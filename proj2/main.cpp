/*
 * main.cpp
 *
 * COMP 15 Project 2: Six Degrees of Collaboration
 *
 * Purpose: Handles command line arguments and communicates with the
 *          SixDegrees class to respond to the different command line
 *          arguments. Implements all behavior specified in the Input
 *          and Output Behavior section of the spec.
 * 
 * by Kirin Godhwani, 11/30/21
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "SixDegrees.h"

template<typename streamtype>
void open_or_die(streamtype &stream, std::string file_name);

int main(int argc, char *argv[])
{
    SixDegrees s;
    if ((argc < 2) or (argc > 4)) {
        std::cerr << "Usage: SixDegrees dataFile [commandFile] "
                  << "[outputFile]\n";
        exit(EXIT_FAILURE);
    }
    std::string artists_data = argv[1];   // artist data
    ifstream input_file;
    if (argc == 2) {                       // no command file, no output file
        open_or_die(input_file, artists_data);
        s.read_data(input_file);
        s.run(std::cin, std::cout);
    } else if ((argc == 3) or (argc == 4)) {
        std::string commands = argv[2];
        ifstream input_file_2;
        open_or_die(input_file_2, commands);
        open_or_die(input_file, artists_data);
        s.read_data(input_file);
        if (argc == 3) {                   // no output file
            s.run(input_file_2, std::cout);
        } else {                           // commands file and output file
            std::string output = argv[3];
            ofstream output_file;
            open_or_die(output_file, output);
            s.run(input_file_2, output_file);
            output_file.close();
        }
        input_file_2.close();
        input_file.close();
    } 
    return 0;
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
        std::cerr << file_name << " cannot be opened." << std::endl;
        exit(EXIT_FAILURE);
    }
}
