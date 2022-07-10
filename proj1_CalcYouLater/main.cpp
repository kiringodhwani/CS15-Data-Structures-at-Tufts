/*
 * main.cpp
 * 
 * CS 15 project 1, CalcYouLater
 * by Kirin Godhwani, 10/18/21
 *
 * Purpose: Handles simple driver functions mainly calling the run() function
 *          in the RPNCalc class to start the command loop and run the
 *          RPN calculator.
 *
 */

#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
#include "parser.h"

int main()
{
    RPNCalc r;
    r.run();
    return 0;
    
}
 
