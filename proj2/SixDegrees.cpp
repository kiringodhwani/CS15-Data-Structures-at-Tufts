/**
 ** SixDegrees.cpp
 **
 ** Project Two: Six Degrees of Collaboration
 **
 ** Purpose: The implementation of the SixDegrees class. Includes the
 **          implementations of the key functions regarding the
 **          functionalities of the SixDegrees class. These include the
 **          function to populate the Collabgraph, the function to run the
 **          command loop to respond to sequences of commands and correctly
 **          output the results, the functions to perform a breadth first
 **          search, the functions to perform a depth first search, and the
 **          functions to perform an exclusive search.
 **   
 ** By Kirin Godhwani, 11/30/21
 **
 **/

#include <algorithm>
#include <exception>
#include <functional>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


#include "CollabGraph.h"
#include "SixDegrees.h"

using namespace std;

/* read_data
 *    Purpose: Takes in the data file of artists, creates a vector of
 *             Artists, and uses the vector to populate the graph.
 * Parameters: The input file to read in Artists from.
 *    Returns: None.
 */
void SixDegrees::read_data(std::istream &input)
{
    string s;
    vector<Artist> artists;

    while (getline(input, s)) {
        
        Artist a(s);

        while (getline(input, s) and s != "*") {
            a.add_song(s);
        }
        artists.push_back(a);
        
    }
    graph.populate_graph(artists);
        
}

/* run
 *    Purpose: Runs the command loop to process the following commands:
 *             bfs, dfs, not, quit, print.
 * Parameters: The place commands are being received from (either std::cin or
 *             a command file), the place that should be outputted to
 *             (either std::cout or an output file)
 *    Returns: None.
 */
void SixDegrees::run(std::istream &input, std::ostream &output)
{
    std::string cmd;
    while (getline(input, cmd)) {

        graph.clear_metadata();
        // print command
        if (cmd == "print") {
            graph.print_graph(output);

        // dfs command
        } else if (cmd == "dfs") {
            run_dfs(input, output);

        // bfs command
        } else if (cmd == "bfs") {
            run_bfs(input, output);
        
        // not command
        } else if (cmd == "not") {
            run_not(input, output);

        // quit command
        } else if (cmd == "quit") {
            return;
         
        // unrecognized input
        } else {
            output << cmd << " is not a command. Please try again.\n";
        } 
    }
}

/* run_bfs
 *    Purpose: Runs the bfs command by reading in two artist names and calling
 *             the bfs function.
 * Parameters: The input stream to read in artists from, the output stream to
 *             be printed to.
 *    Returns: None.
 */ 
void SixDegrees::run_bfs(std::istream &input, std::ostream &output) {
    std::string s1, s2;
    getline(input, s1);
    getline(input, s2);
    Artist a1(s1);
    Artist a2(s2);
    if (inGraph(a1, a2, output)) {
        bfs(a1, a2, output);
    }
}

/* run_dfs
 *    Purpose: Runs the dfs command by reading in two artist names and calling
 *             the dfs function.
 * Parameters: The input stream to read in artists from, the output stream to
 *             be printed to.
 *    Returns: None.
 */ 
void SixDegrees::run_dfs(std::istream &input, std::ostream &output) {
    std::string s1, s2;
    getline(input, s1);
    getline(input, s2);
    Artist a1(s1);
    Artist a2(s2);
    if (inGraph(a1, a2, output)) {
        dfs(a1, a2, output);
    }
}

/* run_not
 *    Purpose: Runs the not command by reading in two artist names and a
 *             list of artists to exclude, and then calling the notCom
 *             function.
 * Parameters: The input stream to read in artists from, the output stream to
 *             be printed to.
 *    Returns: None.
 */
void SixDegrees::run_not(std::istream &input, std::ostream &output) {
    std::string s1, s2, excl;
    getline(input, s1);
    getline(input, s2);
    Artist a1(s1);
    Artist a2(s2);
    std::vector<Artist> excluded;
    while (getline(input, excl) and (excl != "*")) {
        Artist e(excl);
        excluded.push_back(e);
    }
    bool x = inGraph(a1, a2, output);
    bool y = checkVec(excluded, output);
    if (x and y) {
        notCom(a1, a2, excluded, output);
    }
}


/* dfs
 *    Purpose: Takes in two artists and prints any path from artistA to
 *             artistB found using a depth first search. Prints to a provided
 *             output stream.
 * Parameters: Two artists, the output stream to be printed to.
 *    Returns: None.
 */
void SixDegrees::dfs(const Artist& artistA, const Artist& artistB, 
                                            std::ostream &output)
{
    dfs_helper(artistA);
    stack<Artist> s = graph.report_path(artistA, artistB);
    print_path(artistA, artistB, s, output);
}

/* dfs_helper
 *    Purpose: Recursive helper for dfs. Uses recursion to perform a complete
 *             DFS from a provided artist.
 * Parameters: An artist in the graph to begin dfs from.
 *    Returns: None.
 */
void SixDegrees::dfs_helper(const Artist& artistA)
{
    graph.mark_vertex(artistA);
    std::vector<Artist> neighbors;
    neighbors = graph.get_vertex_neighbors(artistA);
    for (size_t i = 0; i < neighbors.size(); i++) {
        if (not graph.is_marked(neighbors.at(i))) {

            graph.set_predecessor(neighbors.at(i), artistA);
            dfs_helper(neighbors.at(i));
        }
    }
}

/* bfs
 *    Purpose: Takes in two artists and prints the shortest path from artistA
 *             to artistB found with a breadth first search.
 * Parameters: The two artists to have the shortest path between them found
 *             (artistA and artistB), an output stream to be printed to
 *    Returns: None.
 */
void SixDegrees::bfs(const Artist& artistA, const Artist& artistB, 
                                            std::ostream &output)
{

    std::queue<Artist> q;

    // mark starting vertex as visited and add to queue
    graph.mark_vertex(artistA);
    q.push(artistA);
    std::vector<Artist> neighbors;

    while (not q.empty()) {
        Artist current = q.front();
        q.pop();
        neighbors = graph.get_vertex_neighbors(current);
        for (size_t i = 0; i < neighbors.size(); i++) {
            if (not graph.is_marked(neighbors.at(i))) {
                graph.mark_vertex(neighbors.at(i));
                graph.set_predecessor(neighbors.at(i), current);
                q.push(neighbors.at(i));
            }
        }
    }
    stack<Artist> s = graph.report_path(artistA, artistB);
    print_path(artistA, artistB, s, output);
}



/* not
 *    Purpose: Takes in two artists and a vector of artists to exclude (each
 *             on a line by itself) and prints out the shortest path from
 *             artistA to artistB, excluding all artists from the list of
 *             artists to exclude.
 * Parameters: Two artists, a vector of artists to exclude, an output stream
 *             to be printed to.
 *    Returns: None.
 */
void SixDegrees::notCom(const Artist& artistA, const Artist& artistB, 
                    const std::vector<Artist>& exclude, std::ostream &output)
{
    for (size_t i = 0; i < exclude.size(); i++) {
        graph.mark_vertex(exclude.at(i));
    }
    // if the starting vertex was chosen to be excluded, there is no path
    if (graph.is_marked(artistA)) {
        stack<Artist> empty;
        print_path(artistA, artistB, empty, output);
        return;
    } 
    // use bfs as opposed to dfs because not finds shortest paths
    bfs(artistA, artistB, output);
}

/* checkVec
 *    Purpose: Checks if a given vector of artists contains only artists that
 *             are in the graph. If any artists are found to not be in the
 *             then the appropriate message is printed to the given output
 *             stream.
 * Parameters: The vector of artists, an output stream to be printed to.
 *    Returns: True if all of the artists are in the graph, false if any
 *             of the artists are not in the graph.
 */
bool SixDegrees::checkVec(const std::vector<Artist>& exclude,
                             std::ostream &output)
{
    int n = 0;
    for (size_t i = 0; i < exclude.size(); i++) {
        if (not graph.is_vertex(exclude.at(i))) {
            output << "\"" << exclude.at(i).get_name() << "\" was not found "
                   << "in the dataset :(\n";
            n++;
        }
    }
    if (n > 0) {
        return false;
    } else {
        return true;
    }
}



/* inGraph
 *    Purpose: Takes in two artists and checks if they are in the graph.
 *             Prints a message if either artist is not.
 * Parameters: The two artists to be checked if they are in the graph.
 *    Returns: Returns true if both artists are in the graph, false if at
 *             least one is not in the graph.
 */
bool SixDegrees::inGraph(const Artist& artistA, const Artist& artistB,
                                                std::ostream &output)
{
    if ((not graph.is_vertex(artistA)) or (not graph.is_vertex(artistB))) {
        if (not graph.is_vertex(artistA)) {
            output << "\"" << artistA.get_name() << "\" was not found in the "
                   << "dataset :(\n";
        }
        if (not graph.is_vertex(artistB)) {
            output << "\"" << artistB.get_name() << "\" was not found in the "
                   << "dataset :(\n";
        }
        return false;
    }
    return true;
}

/* print_path
 *    Purpose: Prints out the path between two artists found from bfs, dfs,
 *             or not.
 * Parameters: The stack created by report_path.
 *    Returns: None.
 */
void SixDegrees::print_path(const Artist& artistA, const Artist& artistB, 
                            std::stack<Artist>& s, std::ostream &output)
{
    // empty stack means no path
    if (s.empty()) {
        output << "A path does not exist between \"" << artistA.get_name() <<
                  "\" and \"" << artistB.get_name() << "\".\n";

    } else {
        int size = static_cast<int>(s.size());

        // for loops runs one less time than the size
        for (int i = 0; i < size - 1; i++) {
            Artist a = s.top();
            s.pop();
            std::string collab = graph.get_edge(a, s.top());
            
            output << "\"" << a.get_name() << "\" collaborated with \"";
            output << s.top().get_name() << "\" in " << "\"" << collab;
            output <<  "\".\n";
        }
        output << "***\n";
    }
}
