/*
 * parser.cpp
 * 
 * CS 15 project 1, CalcYouLater
 * by Kirin Godhwani, 10/16/21
 *
 * Purpose: Implements the parseRString function. This function is
 * important because when reading in an rstring as input, it allows the user
 * to read in a complete rstring, with balanced braces, thereby enabling
 * RPNCalc to handle nested rstrings.
 * 
 * Note: If parseRString gets to the end of the input stream without finding
 * the final matching "}", then the spec says we can choose what to do. I
 * chose to not address this case.
 */

#include "parser.h"
 
#include <iostream>
#include <fstream>
 
// for vector use
#include <vector>

#include <string>
 
/* parseRString
 *    Purpose: Called after an initial “{” has been read from the input stream
 *             passed as a parameter. parseRString reads input from the stream
 *             until all curly braces are matched or until it reaches the end
 *             of the input.
 * Parameters: The stream to read input from
 *    Returns: Returns an rstring (i.e, an std::string), with the
 *             specifications listed under the spec
 */
std::string parseRString(std::istream &input) 
{
    std::string s;
    std::string build = "";
    std::vector<std::string> curlyStack;
    curlyStack.push_back("{");
    
    while (not curlyStack.empty()) { 
        
        input >> s;
        
        // add opening curly braces to the front of the stack
        if (s == "{") {
            curlyStack.push_back(s);
        }
        // closing brace-> remove opener at stack top
        if (s == "}") {
            curlyStack.pop_back();
        }
        build = build + s + " "; 
    }
    build = "{ " + build;
    
    // delete the extra space at the end of the rstring
    build.pop_back();
    return build;    
}