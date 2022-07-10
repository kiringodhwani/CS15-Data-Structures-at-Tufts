/*
 * testParser.cpp
 * 
 * CS 15 project 1, CalcYouLater
 * by Kirin Godhwani, 10/16/21
 *
 * Purpose: Contains a main to test the parseRString function with std::cin. 
 *          Reads in input from std::cin, calls parseRString after the first
 *          curly brace, prints the parsed rstring to std::cout.
 *
 */
 
#include "parser.h"

#include <iostream>
#include <fstream>
#include <string>
 
int main()
{
    std::string parse = "";
    std::string end = "go";
    std::string s;
    std::cout << "Enter the string to be parsed: ";
    while (end != "end") {
        
        std::cin >> s;
        
        if (s == "{") {
            parse = parseRString(std::cin);
            end = "end";
        }
    }
    std::cout << "Parsed String: " << parse << std::endl;
    
    return 0;
}
