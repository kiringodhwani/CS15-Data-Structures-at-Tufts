/*
 * DatumStack.h
 * 
 * CS 15 project 1, CalcYouLater
 * by Kirin Godhwani, 10/14/21
 *
 * Purpose: The interface of the DatumStack class. Defines a stack
 * of Datum elements. Member functions defined to construct instances of the 
 * DatumStack stack, clear the stack, return the size of the stack, return the
 * top element of the stack, remove the top element of the stack, and add an
 * element to the top of the stack.
 *
 * Note: The stack is implemented using a dynamic array (vector).
 *
 */

#ifndef __DATUM_STACK_H__
#define __DATUM_STACK_H__

#include "Datum.h"

// for vector use
#include <vector>

class DatumStack {
    public:
        // default constructor
        DatumStack();
        
        // constructor when given an array of Datum
        DatumStack(Datum *arr, int size);
        
        // turns the current stack into an empty stack
        void clear();
        
        // returns the number of elements in the stack
        int size();
        
        // returns the top Datum element on the stack
        Datum top();
        
        // removes the top element on the stack
        void pop();
        
        // takes a Datum element and puts it on the top of the stack
        void push(const Datum &datum);
        
        // checks if the stack is empty
        bool isEmpty();
        
        // a print function for debugging 
        void debug_print();

    private:
        
        std::vector<Datum> stack;
      
};

#endif