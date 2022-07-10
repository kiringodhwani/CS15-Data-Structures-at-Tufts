/* 
 * unit_tests.h
 * 
 * CS 15 project 1, CalcYouLater
 * by Kirin Godhwani, 10/14/21
 * 
 * Uses Matt Russell's unit_test framework to test the the CalcYouLater
 * interface and the classes it is made up of (i.e. DatumStack).
 * More information on this testing framework can be found in the Lab 1
 * handout
 *
 */

#include <iostream>
#include <cassert>
#include "Datum.h"
#include "DatumStack.h"
#include "parser.h"

/* default constructor test
 * Run the DatumStack default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_test()
{
    DatumStack testDatumStack;
    std::cout << "Should be an empty list: " << std::endl;
    testDatumStack.debug_print();
}

/* push test
 * Initialize a DatumStack, add Datum elements to the stack, check to make
 * sure elements were correctly pushed with assert(), top(), and size(). 
 */
void push_test()
{
    DatumStack testDatumStack;
    std::cout << "Before push: " << std::endl;
    testDatumStack.debug_print();
    
    // element 1,2 3
    Datum d1(5);
    testDatumStack.push(d1);
    assert(testDatumStack.top() == d1);
    assert(testDatumStack.size() == 1);  
    Datum d2(true);
    Datum d3("Kirin");
    testDatumStack.push(Datum(d2));
    testDatumStack.push(Datum(d3));
    assert(testDatumStack.top() == d3);
    assert(testDatumStack.size() == 3);
    std::cout << "After 3 push, 3 elements, Kirin at the top: " << std::endl;
    testDatumStack.debug_print();
    
    Datum d4(8);
    Datum d5(false);
    Datum d6("Godhwani");
    Datum d7(11);
    testDatumStack.push(Datum(d4));
    testDatumStack.push(Datum(d5));
    testDatumStack.push(Datum(d6));
    testDatumStack.push(Datum(d7));
    std::cout << "After 7 push, 7 elements with 11 at the top: " << std::endl;
    testDatumStack.debug_print();
}

/* second constructor test
 * Run the DatumStack second constructor to make sure there are no runtime
 * errors or memory leaks. Make sure the constructor was correctly initialized
 * with the given array using assert(), size(), and front().
 */
void second_constructor_test()
{
    Datum d1(5);
    Datum d2(true);
    Datum d3("Kirin");
    Datum data[3] = {d1, d2, d3};
    DatumStack testDatumStack(data , 3) ;
    
    assert(testDatumStack.top() == d3);
    assert(testDatumStack.size() == 3);
    
    std::cout << "Should be 3 elements with Kirin at the top: " << std::endl;
    testDatumStack.debug_print();
}

/* size_test
 * Define DatumStack stacks of different sizes and make sure size() correctly
 * returns their sizes with assert().
 */
void size_test()
{
    Datum d1(5);
    Datum d2(true);
    Datum d3("Kirin");
    Datum d4(8);
    Datum d5(false);
    Datum d6("Godhwani");
    Datum d7(11);
    Datum d8(12);
    Datum d9(0);
    Datum d10(3);
    
    // empty stack
    DatumStack empty;
    assert(empty.size() == 0);
    
    // 1 element stack
    Datum data1[1] = {d1};
    DatumStack one(data1, 1);
    assert(one.size() == 1);
    
    // multiple element stack
    Datum data2[10] = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10};
    DatumStack multiple(data2, 10);
    assert(multiple.size() == 10);
}

/* top_test
 * Tests top() on various different stacks. Also tests that top() changes
 * after push(element) is called on a stack.
 */
void top_test()
{
    Datum d1(5);
    Datum d2(true);
    Datum d3("Kirin");
    Datum d4(8);
    Datum d5(false);
    Datum d6("Godhwani");
    Datum d7(11);
    Datum d8(12);
    Datum d9(0);
  
    // 1 element stack
    Datum data1[1] = {d1};
    DatumStack one(data1, 1);
    assert(one.top() == d1);
  
    // multiple element stack
    Datum data2[5] = {d1, d2, d3, d4, d5};
    DatumStack multiple(data2, 5);
    assert(multiple.top() == d5);
    multiple.push(d6);
    assert(multiple.top() == d6);
    multiple.push(d7);
    multiple.push(d8);
    multiple.push(d9);
    assert(multiple.top() == d9);
    multiple.pop();
    assert(multiple.top() == d8);
}

/* top_exception_test
 * Tests that top() correctly throws the exception when called on an empty
 * stack.
 
//void top_exception_test()
{
    DatumStack empty;
    empty.top();
}
*/

/* isEmpty_test
 * Initialize an empty stack and two non-Empty stacks and then test that
 * isEmpty() returns the correct value for each of the three stacks with
 * assert().
 */
void isEmpty_test()
{
    // empty stack
    DatumStack empty;
    assert(empty.isEmpty());
    
    Datum d1(5);
    Datum d2(true);
    Datum d3("Kirin");
    Datum d4(8);
    Datum d5(false);

    // 1 element stack
    Datum data1[1] = {d1};
    DatumStack one(data1, 1);
    assert(not one.isEmpty());
    
    // multiple element stack
    Datum data2[5] = {d1, d2, d3, d4, d5};
    DatumStack multiple(data2, 5);
    assert(not multiple.isEmpty());
}
 
/* clear_test
 * initialize different stacks, call clear on the stacks, make sure the stacks
 * are empty using isEmpty() and assert().
 */
void clear_test()
{
    // clear on an empty stack
    DatumStack empty;
    empty.clear();
    assert(empty.isEmpty());
    
    Datum d1(5);
    Datum d2(true);
    Datum d3("Kirin");
    Datum d4(8);
    Datum d5(false);
    Datum d6("Godhwani");
    Datum d7(11);
    Datum d8(12);
    Datum d9(0);
    
    // clear on a 1 element stack
    Datum data1[1] = {d1};
    DatumStack one(data1, 1);
    one.clear();
    assert(one.isEmpty());
    // clear on a multiple element stack
    Datum data2[9] = {d1, d2, d3, d4, d5, d6, d7, d8, d9};
    DatumStack multiple(data2, 9);
    std::cout << "Before clear, should be multi-element stack: ";
    multiple.debug_print();
    multiple.clear();
    assert(multiple.isEmpty());
    std::cout << "After clear should be empty: " << std::endl;
    multiple.debug_print();
}
 
/* pop_test
 * Initialize different stacks, call pop() on the stacks, test that the new
 * top() values are correct with top() and assert() and that the size()
 * correctly changes. This will ensure the pops were successful.
 */
void pop_test()
{
    Datum d1(5);
    Datum d2(true);
    Datum d3("Kirin");
    Datum d4(8);
    Datum d5(false);
    Datum d6("Godhwani");
    // 1 element stack
    Datum data1[1] = {d1};
    DatumStack one(data1, 1);
    one.pop();
    assert(one.isEmpty());
    // multiple element stack
    Datum data2[6] = {d1, d2, d3, d4, d5, d6};
    DatumStack multiple(data2, 6);
    std::cout << "Before pop: " << std::endl;
    multiple.debug_print();
    multiple.pop();
    assert(multiple.top() == d5);
    assert(multiple.size() == 5);
    multiple.pop();
    multiple.pop();
    multiple.pop();
    std::cout << "After 4 pop, 2 element with true on top: " << std::endl;
    multiple.debug_print();
    multiple.pop();
    assert(multiple.top() == d1);
    assert(multiple.size() == 1);
    multiple.pop();
    assert(multiple.isEmpty());
    std::cout << "After 6 pop, should be empty: " << std::endl;
    multiple.debug_print();
}

/* pop_exception_test
 * Tests that pop() correctly throws the exception when called on an empty
 * stack.
 
//void pop_exception_test()
{
    DatumStack empty;
    empty.pop();
}
*/


