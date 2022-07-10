/* 
 * unit_tests.h
 * 
 * CS 15 project 2
 * By Kirin Godhwani, 12/1
 * 
 * Uses Matt Russell's unit_test framework to test report_path and
 * get_vertex_neighbors (two member functions of the CollabGraph class). More
 * information on this testing framework can be found in the Lab 1 handout
 *
 */

#include <iostream>
#include <cassert>
#include <algorithm>
#include <exception>
#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include "SixDegrees.h"

using namespace std;

// --------------------------------------------------------------------

//                         report_path Tests


/* report_path_invalid_artist
 * Tests report_path on when the the source or dest artist it is given
 * is invalid.
 */
void report_path_invalid_artist()
{
    CollabGraph graph;
    Artist a1("Future");
    Artist a2("Young Thug");

    stack<Artist> s = graph.report_path(a1, a2);
    assert(s.empty());

    s = graph.report_path(a2, a1);
    assert(s.empty());

    graph.insert_vertex(a1);

    s = graph.report_path(a2, a1);
    assert(s.empty());

    s = graph.report_path(a1, a2);
    assert(s.empty());
}


/* report_path_2_vertices
 * Tests report_path on two vertices in a 2-vertex graph that have a
 * valid path between them. With this graph, report_path should return a
 * 2-element stack with "Future" being the top-most Artist on the stack and
 * "Young Thug" being the bottom-most Artist.
 */
void report_path_2_vertices()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);
    Artist a2("Young Thug");
    graph.insert_vertex(a2);
    graph.insert_edge(a1, a2, "All Da Smoke");
    
    graph.set_predecessor(a2, a1);

    stack<Artist> s = graph.report_path(a1, a2);
    std::cout << "Top of Stack (source vertex)" << std::endl;

    while (not s.empty()) {
        Artist print = s.top();
        std::cout << print.get_name() << std::endl;
        s.pop();
    }
    std::cout << "Bottom of Stack (destination vertex)" << std::endl;

}

/* report_path_2_vertices_invalid
 * Tests report_path on two vertices in a 2-vertex graph that do not have a
 * valid path between them. report_path should return an empty stack.
 */
void report_path_2_vertices_invalid()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);
    Artist a2("Young Thug");
    graph.insert_vertex(a2);

    stack<Artist> s = graph.report_path(a1, a2);
    std::cout << "Top of Stack (source vertex)" << std::endl;

    while (not s.empty()) {
        Artist print = s.top();
        std::cout << print.get_name() << std::endl;
        s.pop();
    }
    std::cout << "Bottom of Stack (destination vertex)" << std::endl;
}


/* report_path_12_vertices
 * Tests report_path on two vertices in a 12-vertex graph that have a valid
 * path between them. Should return a non-empty stack.
 * With this graph, should create a 10-element stack with "Future"
 * being the top-most Artist on the stack and "Jay-Z" being 
 * the bottom-most Artist.
 */
void report_path_12_vertices()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);
    Artist a2("Young Thug");
    graph.insert_vertex(a2);
    graph.insert_edge(a1, a2, "All Da Smoke");
    Artist a3("Drake");
    graph.insert_vertex(a3);
    graph.insert_edge(a1, a3, "Scholarships");
    graph.insert_edge(a2, a3, "Ice Melts");
    Artist a4("Meek Mill");
    graph.insert_vertex(a4);
    graph.insert_edge(a2, a4, "Offended");
    Artist a5("Tory Lanez");
    graph.insert_vertex(a5);
    graph.insert_edge(a4, a5, "Litty");
    Artist a6("Kodak Black");
    graph.insert_vertex(a6);
    graph.insert_edge(a5, a6, "Grah Tah Tah");
    Artist a7("Lil Wayne");
    graph.insert_vertex(a7);
    graph.insert_edge(a6, a7, "Codeine Dreaming");
    Artist a8("Nicki Minaj");
    graph.insert_vertex(a8);
    graph.insert_edge(a7, a8, "Seeing Green");
    Artist a9("Alicia Keys");
    graph.insert_vertex(a9);
    graph.insert_edge(a8, a9, "Girl on Fire");
    Artist a10("Jay-Z");
    graph.insert_vertex(a10);
    graph.insert_edge(a9, a10, "NY State of Mind");
    Artist a11("Lauren Hill");
    graph.insert_vertex(a11);
    Artist a12("Mary J. Blige");
    graph.insert_vertex(a12);
    graph.insert_edge(a11, a12, "I Used to Love Him");

    graph.set_predecessor(a12, a11);
    graph.set_predecessor(a10, a9);
    graph.set_predecessor(a9, a8);
    graph.set_predecessor(a8, a7);
    graph.set_predecessor(a7, a6);
    graph.set_predecessor(a6, a5);
    graph.set_predecessor(a5, a4);
    graph.set_predecessor(a4, a3);
    graph.set_predecessor(a3, a2);
    graph.set_predecessor(a2, a1);

    stack<Artist> s = graph.report_path(a1, a10);
    std::cout << "Top of Stack (source vertex)" << std::endl;

    while (not s.empty()) {
        Artist print = s.top();
        std::cout << print.get_name() << std::endl;
        s.pop();
    }
    std::cout << "Bottom of Stack (destination vertex)" << std::endl;

}

/* report_path_12_vertices_invalid
 * Tests report_path on two vertices in a 12-vertex graph that do not have a
 * valid path between them. Should return an empty stack.
 */
void report_path_12_vertices_invalid()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);
    Artist a2("Young Thug");
    graph.insert_vertex(a2);
    graph.insert_edge(a1, a2, "All Da Smoke");
    Artist a3("Drake");
    graph.insert_vertex(a3);
    graph.insert_edge(a1, a3, "Scholarships");
    graph.insert_edge(a2, a3, "Ice Melts");
    Artist a4("Meek Mill");
    graph.insert_vertex(a4);
    graph.insert_edge(a2, a4, "Offended");
    Artist a5("Tory Lanez");
    graph.insert_vertex(a5);
    graph.insert_edge(a4, a5, "Litty");
    Artist a6("Kodak Black");
    graph.insert_vertex(a6);
    graph.insert_edge(a5, a6, "Grah Tah Tah");
    Artist a7("Lil Wayne");
    graph.insert_vertex(a7);
    graph.insert_edge(a6, a7, "Codeine Dreaming");
    Artist a8("Nicki Minaj");
    graph.insert_vertex(a8);
    graph.insert_edge(a7, a8, "Seeing Green");
    Artist a9("Alicia Keys");
    graph.insert_vertex(a9);
    graph.insert_edge(a8, a9, "Girl on Fire");
    Artist a10("Jay-Z");
    graph.insert_vertex(a10);
    graph.insert_edge(a9, a10, "NY State of Mind");
    Artist a11("Lauren Hill");
    graph.insert_vertex(a11);
    Artist a12("Mary J. Blige");
    graph.insert_vertex(a12);
    graph.insert_edge(a11, a12, "I Used to Love Him");

    graph.set_predecessor(a10, a9);
    graph.set_predecessor(a9, a8);
    graph.set_predecessor(a8, a7);
    graph.set_predecessor(a7, a6);
    graph.set_predecessor(a6, a5);
    graph.set_predecessor(a5, a4);
    graph.set_predecessor(a4, a3);
    graph.set_predecessor(a3, a2);
    graph.set_predecessor(a2, a1);

    stack<Artist> s = graph.report_path(a1, a12);
    std::cout << "Top of Stack (source vertex)" << std::endl;

    while (not s.empty()) {
        Artist print = s.top();
        std::cout << print.get_name() << std::endl;
        s.pop();
    }
    std::cout << "Bottom of Stack (destination vertex)" << std::endl;

}

/* report_path_dest_equals_source
 * Testing report_path when the source vertex it is given is the same
 * as the destination vertex it is given. The result is that report_path
 * should return an empty stack.
 */
void report_path_dest_equals_source()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);
    Artist a2("Young Thug");
    graph.insert_vertex(a2);
    Artist a3("Drake");
    graph.insert_vertex(a3);
    Artist a4("Meek Mill");
    graph.insert_vertex(a4);

    stack<Artist> s = graph.report_path(a2, a2);
    std::cout << "Top of Stack (source vertex)" << std::endl;

    while (not s.empty()) {
        Artist print = s.top();
        std::cout << print.get_name() << std::endl;
        s.pop();
    }
    std::cout << "Bottom of Stack (destination vertex)" << std::endl;

}

/* report_path_one_vertex
 * Testing report_path when there is only one vertex in the graph
 * and the source vertex is thus the same as the destination
 * vertex. report_path should return an empty stack.
 */
void report_path_one_vertex()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);

    stack<Artist> s = graph.report_path(a1, a1);
    std::cout << "Top of Stack (source vertex)" << std::endl;

    while (not s.empty()) {
        Artist print = s.top();
        std::cout << print.get_name() << std::endl;
        s.pop();
    }
    std::cout << "Bottom of Stack (destination vertex)" << std::endl;

}

/* report_path_12_vertices_diff
 * Testing report_path on a graph of 12 vertices with a different path
 * from the earlier test. With this path, report_path should return a
 * 4-element stack with "Future" being the top-most Artist on the stack
 * and "Jay-Z" being the bottom-most Artist. The artists on the stack
 * should be different from with the previous test.
 */
void report_path_12_vertices_diff()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);
    Artist a2("Young Thug");
    graph.insert_vertex(a2);
    graph.insert_edge(a1, a2, "All Da Smoke");
    Artist a3("Drake");
    graph.insert_vertex(a3);
    graph.insert_edge(a1, a3, "Scholarships");
    graph.insert_edge(a2, a3, "Ice Melts");
    Artist a4("Meek Mill");
    graph.insert_vertex(a4);
    graph.insert_edge(a2, a4, "Offended");
    Artist a5("Tory Lanez");
    graph.insert_vertex(a5);
    graph.insert_edge(a4, a5, "Litty");
    Artist a6("Kodak Black");
    graph.insert_vertex(a6);
    graph.insert_edge(a5, a6, "Grah Tah Tah");
    Artist a7("Lil Wayne");
    graph.insert_vertex(a7);
    graph.insert_edge(a6, a7, "Codeine Dreaming");
    Artist a8("Nicki Minaj");
    graph.insert_vertex(a8);
    graph.insert_edge(a7, a8, "Seeing Green");
    Artist a9("Alicia Keys");
    graph.insert_vertex(a9);
    graph.insert_edge(a8, a9, "Girl on Fire");
    Artist a10("Jay-Z");
    graph.insert_vertex(a10);
    graph.insert_edge(a9, a10, "NY State of Mind");
    Artist a11("Lauren Hill");
    graph.insert_vertex(a11);
    Artist a12("Mary J. Blige");
    graph.insert_vertex(a12);
    graph.insert_edge(a11, a12, "I Used to Love Him");
    graph.insert_edge(a4, a8, "All Eyes on You");
    graph.insert_edge(a8, a10, "Monster");

    graph.set_predecessor(a10, a8);
    graph.set_predecessor(a8, a4);
    graph.set_predecessor(a4, a2);
    graph.set_predecessor(a2, a1);

    stack<Artist> s = graph.report_path(a1, a10);
    std::cout << "Top of Stack (source vertex)" << std::endl;

    while (not s.empty()) {
        Artist print = s.top();
        std::cout << print.get_name() << std::endl;
        s.pop();
    }
    std::cout << "Bottom of Stack (destination vertex)" << std::endl;

}

// --------------------------------------------------------------------

//                         get_vertex_neighbors Tests

/* neighbors_lone
 * Testing get_vertex_neighbors on the lone vertex in a one-vertex graph.
 * Should return an empty vector.
 */
void neighbors_lone()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);

    vector<Artist> v = graph.get_vertex_neighbors(a1);
    assert(v.empty() == true);
}

/* neighbors_no_neighbors
 * Testing get_vertex_neighbors on a vertex in a 14-vertex graph that has
 * no neighbors. Should return an empty vector.
 */
void neighbors_no_neighbors()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);
    Artist a2("Young Thug");
    graph.insert_vertex(a2);
    graph.insert_edge(a1, a2, "All Da Smoke");
    Artist a3("Drake");
    graph.insert_vertex(a3);
    graph.insert_edge(a1, a3, "Scholarships");
    graph.insert_edge(a2, a3, "Ice Melts");
    Artist a4("Meek Mill");
    graph.insert_vertex(a4);
    graph.insert_edge(a3, a4, "Going Bad");
    graph.insert_edge(a2, a4, "Offended");
    Artist a5("Tory Lanez");
    graph.insert_vertex(a5);
    graph.insert_edge(a4, a5, "Litty");
    Artist a6("Kodak Black");
    graph.insert_vertex(a6);
    graph.insert_edge(a5, a6, "Grah Tah Tah");
    Artist a7("Lil Wayne");
    graph.insert_vertex(a7);
    graph.insert_edge(a6, a7, "Codeine Dreaming");
    Artist a8("Nicki Minaj");
    graph.insert_vertex(a8);
    graph.insert_edge(a7, a8, "Seeing Green");
    Artist a9("Alicia Keys");
    graph.insert_vertex(a9);
    graph.insert_edge(a8, a9, "Girl on Fire");
    Artist a10("Jay-Z");
    graph.insert_vertex(a10);
    graph.insert_edge(a9, a10, "NY State of Mind");
    Artist a11("Lauren Hill");
    graph.insert_vertex(a11);
    Artist a12("Mary J. Blige");
    graph.insert_vertex(a12);
    graph.insert_edge(a11, a12, "I Used to Love Him");
    graph.insert_edge(a4, a8, "All Eyes on You");
    graph.insert_edge(a8, a10, "Monster");
    Artist a13("Lil Baby");
    graph.insert_vertex(a13);
    graph.insert_edge(a3, a13, "Wants and Needs");
    Artist a14("Adele");
    graph.insert_vertex(a14);

    vector<Artist> v = graph.get_vertex_neighbors(a14);
    assert(v.empty() == true);
}

/* neighbors_one_neighbor
 * Testing get_vertex_neighbors on three vertices in a 14-vertex graph that
 * all only have one neighbor. get_vertex_neighbors should return vectors of
 * size 1 for each of the three vertices that contain their lone neighbor.
 */
void neighbors_one_neighbor()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);
    Artist a2("Young Thug");
    graph.insert_vertex(a2);
    graph.insert_edge(a1, a2, "All Da Smoke");
    Artist a3("Drake");
    graph.insert_vertex(a3);
    graph.insert_edge(a1, a3, "Scholarships");
    graph.insert_edge(a2, a3, "Ice Melts");
    Artist a4("Meek Mill");
    graph.insert_vertex(a4);
    graph.insert_edge(a3, a4, "Going Bad");
    graph.insert_edge(a2, a4, "Offended");
    Artist a5("Tory Lanez");
    graph.insert_vertex(a5);
    graph.insert_edge(a4, a5, "Litty");
    Artist a6("Kodak Black");
    graph.insert_vertex(a6);
    graph.insert_edge(a5, a6, "Grah Tah Tah");
    Artist a7("Lil Wayne");
    graph.insert_vertex(a7);
    graph.insert_edge(a6, a7, "Codeine Dreaming");
    Artist a8("Nicki Minaj");
    graph.insert_vertex(a8);
    graph.insert_edge(a7, a8, "Seeing Green");
    Artist a9("Alicia Keys");
    graph.insert_vertex(a9);
    graph.insert_edge(a8, a9, "Girl on Fire");
    Artist a10("Jay-Z");
    graph.insert_vertex(a10);
    graph.insert_edge(a9, a10, "NY State of Mind");
    Artist a11("Lauren Hill");
    graph.insert_vertex(a11);
    Artist a12("Mary J. Blige");
    graph.insert_vertex(a12);
    graph.insert_edge(a11, a12, "I Used to Love Him");
    graph.insert_edge(a4, a8, "All Eyes on You");
    graph.insert_edge(a8, a10, "Monster");
    Artist a13("Lil Baby");
    graph.insert_vertex(a13);
    graph.insert_edge(a3, a13, "Wants and Needs");
    Artist a14("Adele");
    graph.insert_vertex(a14);

    vector<Artist> v = graph.get_vertex_neighbors(a13);
    int size = static_cast<int>(v.size());
    assert(size == 1);
    assert(v.at(0) == a3);
    std::cout << a13.get_name() << "'s " << size << " neighbors: ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << "'" << v.at(i).get_name() << "' ";
    }
    std::cout << std::endl;

    vector<Artist> v2 = graph.get_vertex_neighbors(a11);
    int size2 = static_cast<int>(v2.size());
    assert(size2 == 1);
    assert(v2.at(0) == a12);
    std::cout << a11.get_name() << "'s " << size2 << " neighbors: ";
    for (size_t i = 0; i < v2.size(); i++) {
        std::cout << "'" << v2.at(i).get_name() << "' ";
    }
    std::cout << std::endl;

    vector<Artist> v3 = graph.get_vertex_neighbors(a12);
    int size3 = static_cast<int>(v3.size());
    assert(size3 == 1);
    assert(v3.at(0) == a11);
    std::cout << a12.get_name() << "'s " << size3 << " neighbors: ";
    for (size_t i = 0; i < v3.size(); i++) {
        std::cout << "'" << v3.at(i).get_name() << "' ";
    }
    std::cout << std::endl;
}

/* neighbors_many_neighbors
 * Testing get_vertex_neighbors on different vertices in a 14-vertex graph
 * that all have multiple neighbors. get_vertex_neighbors should return
 * vectors of sizes > 1 for all of the vertices that contain their neighbors.
 */
void neighbors_many_neighbors()
{
    CollabGraph graph;
    Artist a1("Future");
    graph.insert_vertex(a1);
    Artist a2("Young Thug");
    graph.insert_vertex(a2);
    graph.insert_edge(a1, a2, "All Da Smoke");
    Artist a3("Drake");
    graph.insert_vertex(a3);
    graph.insert_edge(a1, a3, "Scholarships");
    graph.insert_edge(a2, a3, "Ice Melts");
    Artist a4("Meek Mill");
    graph.insert_vertex(a4);
    graph.insert_edge(a3, a4, "Going Bad");
    graph.insert_edge(a2, a4, "Offended");
    Artist a5("Tory Lanez");
    graph.insert_vertex(a5);
    graph.insert_edge(a4, a5, "Litty");
    Artist a6("Kodak Black");
    graph.insert_vertex(a6);
    graph.insert_edge(a5, a6, "Grah Tah Tah");
    Artist a7("Lil Wayne");
    graph.insert_vertex(a7);
    graph.insert_edge(a6, a7, "Codeine Dreaming");
    Artist a8("Nicki Minaj");
    graph.insert_vertex(a8);
    graph.insert_edge(a7, a8, "Seeing Green");
    Artist a9("Alicia Keys");
    graph.insert_vertex(a9);
    graph.insert_edge(a8, a9, "Girl on Fire");
    Artist a10("Jay-Z");
    graph.insert_vertex(a10);
    graph.insert_edge(a9, a10, "NY State of Mind");
    Artist a11("Lauren Hill");
    graph.insert_vertex(a11);
    Artist a12("Mary J. Blige");
    graph.insert_vertex(a12);
    graph.insert_edge(a11, a12, "I Used to Love Him");
    graph.insert_edge(a4, a8, "All Eyes on You");
    graph.insert_edge(a8, a10, "Monster");
    Artist a13("Lil Baby");
    graph.insert_vertex(a13);
    graph.insert_edge(a3, a13, "Wants and Needs");
    Artist a14("Adele");
    graph.insert_vertex(a14);
    graph.insert_edge(a2, a8, "Anybody");
    graph.insert_edge(a3, a8, "No Frauds");
    graph.insert_edge(a5, a8, "Medusa");
    graph.insert_edge(a13, a8, "Drip Too Hard");
    graph.insert_edge(a6, a8, "ZEZE");

    vector<Artist> v = graph.get_vertex_neighbors(a1);
    int size = static_cast<int>(v.size());
    assert(size == 2);
    assert(v.at(0) == a2);
    assert(v.at(1) == a3);
    std::cout << a1.get_name() << "'s " << size << " neighbors: ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << "'" << v.at(i).get_name() << "' ";
    }
    std::cout << std::endl;

    vector<Artist> v2 = graph.get_vertex_neighbors(a8);
    int size2 = static_cast<int>(v2.size());
    assert(size2 == 9);
    assert(v2.at(0) == a7);
    assert(v2.at(1) == a9);
    assert(v2.at(2) == a4);
    assert(v2.at(3) == a10);
    assert(v2.at(4) == a2);
    assert(v2.at(5) == a3);
    assert(v2.at(6) == a5);
    assert(v2.at(7) == a13);
    assert(v2.at(8) == a6);
    std::cout << a8.get_name() << "'s " << size2 << " neighbors: ";
    for (size_t i = 0; i < v2.size(); i++) {
        std::cout << "'" << v2.at(i).get_name() << "' ";
    }
    std::cout << std::endl;

    vector<Artist> v3 = graph.get_vertex_neighbors(a4);
    int size3 = static_cast<int>(v3.size());
    assert(size3 == 4);
    assert(v3.at(0) == a3);
    assert(v3.at(1) == a2);
    assert(v3.at(2) == a5);
    assert(v3.at(3) == a8);
    std::cout << a4.get_name() << "'s " << size3 << " neighbors: ";
    for (size_t i = 0; i < v3.size(); i++) {
        std::cout << "'" << v3.at(i).get_name() << "' ";
    }
    std::cout << std::endl;

}
