/**
 ** SixDegrees.h
 **
 ** Project Two: Six Degrees of Collaboration
 **
 ** Purpose: The interface of the SixDegrees class. The SixDegrees class
 **          has the following functionalities: populates the CollabGraph and
 **          runs a command loop to execute a sequence of commands and output
 **          the results. The commands the SixDegrees class supports are
 **          printing the graph, performing a breadth first search between two
 **          Artists to find the shortest path between them, performing a
 **          depth first search between two Artists to find a path between
 **          them, performing an exclusive search between two Artists to find
 **          the shortest path between them that excludes certain
 **          user-inputted Artists, and quitting the program.
 **
 ** By Kirin Godhwani, 11/30/21
 **
 **/

#ifndef __SIX_DEGREES__
#define __SIX_DEGREES__

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include "CollabGraph.h"

class SixDegrees {

    public:
        
        // Function to process the data file of artists, convert it to a
        // vector of Artists, and then use it to populate the graph.
        void read_data(std::istream &input);

        // Function to run the command loop to execute a sequence of commands
        // and output the results. Handles print, quit, not, bfs, and dfs.
        void run(std::istream &input, std::ostream &output);

    
    private:
        
        // Runs the bfs command by reading in two artist names and calling
        // the bfs function.
        void run_bfs(std::istream &input, std::ostream &output);

        // Runs the dfs command by reading in two artist names and calling
        // the dfs function.
        void run_dfs(std::istream &input, std::ostream &output);

        // Runs the not command by reading in two artist names and a
        // list of artists to exclude, and then calling the notCom function.
        void run_not(std::istream &input, std::ostream &output);

        // Function to perform a bfs and print out the shortest path between
        // the two provided artists.
        void bfs(const Artist& artistA, const Artist& artistB, 
                                            std::ostream &output);
        
        // Function to perform a dfs and print out the path between the two
        // provided artists.
        void dfs(const Artist& artistA, const Artist& artistB,
                                            std::ostream &output);
        
        // Recursive helper function for dfs, performs the dfs using
        // recursion.
        void dfs_helper(const Artist& artistA);

        // Function to perform a shortest path exclusive search of the graph
        // and print out the found path between the two provided artists.
        void notCom(const Artist& artistA, const Artist& artistB, 
                    const std::vector<Artist>& exclude, std::ostream &output);

        // Makes sure a given vector only contains artists that are in the
        // graph.
        bool checkVec(const std::vector<Artist>& exclude,
                                       std::ostream &output);
        
        // Function to check if two provided artists are in the graph.
        bool inGraph(const Artist& artistA, const Artist& artistB, 
                                               std::ostream &output);

        // Function to print out the path between two artists found from bfs,
        // dfs, or not. Called on the stack returned by report_path.
        void print_path(const Artist& artistA, const Artist& artistB, 
                        std::stack<Artist>& s, std::ostream &output);
        
        CollabGraph graph;
   
};

#endif /* __SIX_DEGREES__ */
