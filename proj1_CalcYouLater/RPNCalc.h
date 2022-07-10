/*
 * RPNCalc.h
 * 
 * CS 15 project 1, CalcYouLater
 * by Kirin Godhwani, 10/17/21
 *
 * Purpose: The interface of the RPNCalc class. Handles the logic of processing
 *          the commands that come to the run function. Implements the RPN
 *          calculator and its commands. Defines a constructor, a
 *          destructor, a commandLoop function to read in commands from an
 *          input stream and respond to them, and a run function to call
 *          commandLoop and print a thank you message. Also declares a private
 *          variable of type DatumStack to be used while performing the
 *          operations. 
 */

#ifndef __RPN_CALC_H__
#define __RPN_CALC_H__

#include "DatumStack.h"
#include "Datum.h"

#include <vector>       // std::vector
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <fstream>

class RPNCalc {
    public:
        
        // default constructor
        RPNCalc();
        
        // destructor
        ~RPNCalc();
        
        // run function
        void run();
    
    private:
        
        DatumStack stack;
        
        // determines if a string contains and int, if so, returns the int
        bool got_int(std::string s, int *resultp);
        
        // used to make sure an inputted rstring has enough closing braces
        std::string parseRString(std::istream &input);
        
        // reads in commands from an input stream and performs operations
        // based on the commands
        void commandLoop(std::istream &input);

};

#endif