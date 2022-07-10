/* 
 * unit_tests.h
 * 
 * CS 15 homework 1
 * by C.R. Calabrese, January 2021
 * edited by Kirin Godhwani, 9/26
 * 
 * Uses Matt Russell's unit_test framework to test the CharArrayList and
 * CharLinkedList.
 * More information on this testing framework can be found in the Lab 1
 * handout
 *
 */

#include <iostream>
#include <cassert>
#include "CharArrayList.h"
#include "CharLinkedList.h"

/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

/* default constructor test
 * Run the ArrayList default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_AL()
{
    CharArrayList testArrayList;
}

/* second constructor test 
 * Run the ArrayList second contructor to make sure there are no runtime 
 * errors or memory leaks, also use assert(), size(), elementAt(), 
 * and print() to make sure it was successful.
 */
void second_constructor_AL()
{
    CharArrayList testArrayList('A');
    
    assert(testArrayList.size() == 1);
    assert(testArrayList.elementAt(0) == 'A');
    testArrayList.print(); // [CharArrayList of size 1 <<A>>]
}
 
/* elementAt() test 
 * Create a one character CharArrayList, use the assert() function to make sure 
 * that the elementAt() function detects the correct character at index 0.
 */
void elementAt_test_AL()
{
    CharArrayList testArrayList('A');
    assert(testArrayList.elementAt(0) == 'A');
}

/* elementAt() failure test 
 * Input an invalid index and make sure the error message is correctly
 * printing for elementAt 
 */
 /*
//void FAIL_elementAt_test_AL()
{
    CharArrayList testArrayList('A');
    testArrayList.elementAt(1);
    //testArrayList.elementAt(-1);
}
*/

/* third constructor test, size() test, print() test 
 * Run the ArrayList third contructor to make sure there are no runtime 
 * errors or memory leaks, then make sure it correctly copied the given array
 * using elementAt(), size(), and the print() function.
 */
void third_constructor_AL()
{
    char example[13] = {'K', 'i', 'r', 'i', 'n', 
                        'G', 'o', 'd', 'h', 'w', 'a', 'n', 'i'};
    CharArrayList testArrayList(example, 13);
    assert(testArrayList.elementAt(3) == 'i');
    assert(testArrayList.size() == 13);
    testArrayList.print(); // should print : 
                           // "[CharArrayList of size 13 <<KirinGodhwani>>]")
}

/* first() and last() test
 * Create an ArrayList with the third constructor, use first() and last() to 
 * to get the first and last elements in the list 
 */
void first_last_test_AL()
{
    char example[6] = {'K','i','r','i','n','G'};
    CharArrayList testArrayList(example, 6);
    assert(testArrayList.first() == 'K');
    assert(testArrayList.last() == 'G');
}

/* first() failure test
 * try to use first() on an empty list to see if it prints
 * the correct error message
 */
/*
//void FAIL_first_AL()
{
    CharArrayList testArrayList;
    testArrayList.first();
}
*/

/* last() failure test
 * try to use last() on an empty list to see if it prints
 * the correct error message
 */
/*
//void FAIL_last_AL()
{
    CharArrayList testArrayList;
    testArrayList.last();
}
*/

/* clear() and isEmpty() test
 * create an array list of multiple elements using the third constructor 
 * and then use the clear() function to make the list an empty list. Test 
 * this with the print() function and the isEmpty() function.
 */
void clear_AL()
{
    // testing on a list of multiple elements
    char example[6] = {'K','i','r','i','n','G'};
    CharArrayList testArrayList(example, 6);
    assert(testArrayList.size() == 6);
    testArrayList.clear();
    assert(testArrayList.isEmpty());
    assert(testArrayList.size() == 0);
    testArrayList.print(); // should print an empty list
                           // [CharArrayList of size 0 <<>>]    
    
    // testing on an empty list
    CharArrayList testArrayList1;
    testArrayList1.clear();
    assert(testArrayList1.isEmpty());
    
    // testing on a one element list
    CharArrayList testArrayList2('A');
    testArrayList2.clear();
    assert(testArrayList2.isEmpty());
}

/* pushAtBack and expand() test
 * Create an array list of multiple elements using the third constructor.
 * Run the pushAtBack function to add a character to the end of the list.
 * Because the list is full, the expand() function will be called
 * to expand the array list. Check that this expansion and addition worked
 * using the assert() function, the size() function, the last() function,
 * and the print() function.
 */
void pushAtBack_AL()
{
    // testing on a larger list
    char example[10] = {'A','A','A','A','A','A','A','A','A','A'};
    CharArrayList testArrayList(example, 10);
    assert(testArrayList.size() == 10);
    testArrayList.pushAtBack('B');
    assert(testArrayList.size() == 11);
    assert(testArrayList.last() == 'B');
    testArrayList.print(); // [CharArrayList of size 11 <<AAAAAAAAAAB>>]
    
    // testing pushAtBack() on an empty list
    CharArrayList testArrayList2;
    testArrayList2.pushAtBack('A');
    assert(testArrayList2.size() == 1);
    assert(testArrayList2.first() == 'A');
    assert(testArrayList2.last() == 'A');
    //testArrayList2.print();
    
    // testing on a list with one element 
    CharArrayList firstConstruct('A');
    firstConstruct.pushAtBack('B');
    assert(firstConstruct.size() == 2);
    assert(firstConstruct.first() == 'A');
    assert(firstConstruct.last() == 'B');
       
}

/* pushAtFront test
 * Create an array list of multiple elements using the third constructor.
 * Run the pushAtFront function to add a character to the front of the list.
 * Because the list is full, the expand() function will be called
 * to expand the array list. Check that this expansion and addition worked
 * using the assert() function, the size() function, the first() function,
 * the elementAt() function, and the print() function.
 */
void pushAtFront_AL()
{
    // testing on a larger list
    char example[10] = {'A','A','A','A','A','A','A','A','A','A'};
    CharArrayList testArrayList(example, 10);
    assert(testArrayList.size() == 10);
    
    testArrayList.pushAtFront('B');
    assert(testArrayList.size() == 11);
    assert(testArrayList.first() == 'B');
    testArrayList.print(); // [CharArrayList of size 11 <<BAAAAAAAAAA>>]
    
    // testing pushAtFront() on an empty list
    CharArrayList testArrayList1;
    testArrayList1.pushAtFront('A');
    assert(testArrayList1.size() == 1);
    assert(testArrayList1.first() == 'A');
    assert(testArrayList1.last() == 'A');
    // testArrayList1.print();

    // testing on a list with one element 
    CharArrayList testArrayList2('B');
    testArrayList2.pushAtFront('A');
    assert(testArrayList2.size() == 2);
    assert(testArrayList2.first() == 'A');
    assert(testArrayList2.last() == 'B');
    
}

/* insertAt test
 * Create three array lists each with one of the three constructors (one 
 * empty list, one list with one character, and one list with enough
 * characters that it will need to expand(). Run the insertAt() function to 
 * add characters to the lists. Check that the addition is successful using
 * the assert() function, the size() function, and the print() function. 
 */
void insertAt_AL()
{
    CharArrayList testArrayList2;
    testArrayList2.insertAt('A', 0);
    assert(testArrayList2.size() == 1);
    assert(testArrayList2.elementAt(0) == 'A');
    
    CharArrayList testArrayList3('B');
    testArrayList3.insertAt('A', 0);
    testArrayList3.insertAt('C', 2);
    assert(testArrayList3.size() == 3);
    assert(testArrayList3.elementAt(0) == 'A');
    assert(testArrayList3.elementAt(1) == 'B');
    assert(testArrayList3.elementAt(2) == 'C');
    
    char example[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    CharArrayList testArrayList(example, 9);
    testArrayList.insertAt('Z', 3);
    testArrayList.insertAt('W', 5);
    testArrayList.insertAt('X', 0);
    testArrayList.insertAt('Y', 2);
    testArrayList.insertAt('Q', 13);
    testArrayList.insertAt('V', 7);
    assert(testArrayList.size() == 15);
    assert(testArrayList.elementAt(5) == 'Z');
    assert(testArrayList.elementAt(8) == 'W');
    assert(testArrayList.elementAt(0) == 'X');
    assert(testArrayList.elementAt(2) == 'Y');
    assert(testArrayList.elementAt(14) == 'Q');
    assert(testArrayList.elementAt(7) == 'V');
    testArrayList.print(); // [CharArrayList of size 15 <<XAYBCZDVWEFGHIQ>>]
}

/* insertAt failure test
 * tries to use insertAt to insert an element at an invalid index
 */
/*
//void FAIL1_insertAt_AL()
{
    char example[4] = {'A','B','C','D'};
    CharArrayList testArrayList(example, 4);
    testArrayList.insertAt('Z', 5);
}
*/

 /* insertAt failure test
  * tries to use insertAt to insert an element at an invalid index
  */
/*
//void FAIL2_insertAt_AL()
{
    char example[4] = {'A','B','C','D'};
    CharArrayList testArrayList(example, 4);
    testArrayList.insertAt('Z', -1);
}
*/

/* replaceAt test
 * uses the replaceAt() function to replace the element at a given index 
 * in the list with a given character value
 */
void replaceAt_AL()
{
    char example[4] = {'A','B','C','D'};
    CharArrayList testArrayList(example, 4);
    
    testArrayList.replaceAt('Z', 2);
    testArrayList.replaceAt('W', 0);
    testArrayList.replaceAt('Y', 3);
    assert(testArrayList.elementAt(2) == 'Z');
    assert(testArrayList.elementAt(0) == 'W');
    assert(testArrayList.elementAt(3) == 'Y');
    testArrayList.print(); // [CharArrayList of size 4 <<WBZY>>]
}

/* FAIL replaceAt test
 * try to use the replaceAt() function with an invalid index to see if the  
 * correct error message prints out
 */

/*
//void FAIL_replaceAt_AL()
{
    char example[4] = {'A','B','C','D'};
    CharArrayList testArrayList(example, 4);
    
    testArrayList.replaceAt('Z', 4);
    //testArrayList.replaceAt('Z', -1);
}
*/

/* concatenate() test
 * use the concatenate test to copy a second array list to the back of the
 * first array list. Test that this is successful using assert(), print(),
 * size(), and elementAt().
 */
void concatenate_AL()
{
    // first list
    char arr1[5] = {'K','i','r','i','n'};
    CharArrayList list1(arr1, 5);
    // second list 
    char arr2[8] = {'G', 'o', 'd', 'h', 'w', 'a', 'n', 'i'};
    CharArrayList list2(arr2,8);
    // add list 2 to the back of list1
    list1.concatenate(list2);
    // check if it worked with assert(), print(), size(), elementAt()
    assert(list1.size() == 13);
    assert(list1.elementAt(4) == 'n');
    assert(list1.elementAt(5) == 'G');
    list1.print(); // [CharArrayList of size 13 <<KirinGodhwani>>]
    
    CharArrayList empty;
    CharArrayList NotEmpty(arr2, 8);
    empty.concatenate(NotEmpty);
    assert(empty.size() == 8);
    assert(empty.elementAt(0) == 'G');
    assert(empty.elementAt(7) == 'i');
    
    CharArrayList empty1;
    CharArrayList NotEmpty1(arr2, 8);
    NotEmpty1.concatenate(empty1);
    assert(NotEmpty1.size() == 8);
    assert(NotEmpty1.elementAt(0) == 'G');
    assert(NotEmpty1.elementAt(7) == 'i');
}

/* copy constructor test
 * use the copy constructor to create an array list with the same information 
 * as an array list passed into it
 */
void copy_constructor_AL()
{
    // create the list to copy
    char arr[6] = {'T','e','n','n','i','s'};
    CharArrayList toCopy(arr, 6);
    
    // copy with the copy constructor 
    CharArrayList copied(toCopy);
    
    // make sure the copy is correct
    assert(copied.size() == 6);
    assert(copied.first() == 'T');
    assert(copied.last() == 's');
    copied.print(); // should be [CharArrayList of size 6 <<Tennis>>]
    
    // copying an empty list 
    CharArrayList empty;
    CharArrayList copyEmpty(empty);
    assert(copyEmpty.isEmpty());
    
    // copying a one element list
    CharArrayList one('A');
    CharArrayList copyOne(one);
    assert(copyOne.elementAt(0) == 'A');
    assert(copyOne.size() == 1);
}

/* assignment operator test 
 * run the assignment operator to make one array list contain the same
 * information as another array list
 */
void assignment_operator_AL()
{
    // create the original list
    char arr[3] = {'A', 'B', 'C'};
    CharArrayList current(arr, 3);
    
    // create the list to transfer the information from
    char assign[17] = {'I', 'A', 'm', 'H', 'u', 'n', 'g', 'r', 'y', 'F', 'o',
                       'r', 'S', 'u', 's', 'h', 'i'};
    CharArrayList toAssign(assign, 17);
    
    // use the assignment operator
    current = toAssign;
    assert(current.size() == 17);
    assert(current.first() == 'I');
    assert(current.last() == 'i');
    assert(current.elementAt(9) == 'F');
    current.print(); // [CharArrayList of size 17 <<IAmHungryForSushi>>]
    
    CharArrayList one('A');
    CharArrayList empty;
    one = empty;
    assert(one.isEmpty());
    
    char arr2[5] = {'H', 'e', 'l', 'l', 'o'};
    CharArrayList empty1;
    CharArrayList notEmpty(arr2, 5);
    empty1 = notEmpty;
    assert(empty1.size() == 5);
    assert(empty1.first() == 'H');
    assert(empty1.last() == 'o');
}

//void shrink_AL() {
    // create a list, initial capacity is 10
//    char arr[6] = {'T','e','n','n','i','s'};
//    CharArrayList testArrayList(arr, 6);
    
    // reduce the list's length to less than 1/4 its capacity with removeAt 
    // and check to make sure shrink() shrinks the capacity
//    testArrayList.removeAt(2);
//    assert(testArrayList.return_cap() == 10);
//    testArrayList.removeAt(1);
//    assert(testArrayList.return_cap() == 10);
//    testArrayList.removeAt(1);
//    assert(testArrayList.return_cap() == 10);
//    testArrayList.removeAt(0);
//    assert(testArrayList.return_cap() == 10);
//    testArrayList.removeAt(0); // the initial capacity is 10, so shrink() 
                              // should shrink the list when the length is 1
                                // because c++ rounds down to the nearest 
                                // integer in division, so 10/4 = 2.
//    assert(testArrayList.size() == 1);
//    assert(testArrayList.return_cap() == 4); // when the capacity is shrunk,
                                             // 2 is subtracted from it and 
                                             // it is then divided by 2
//}

/*******************************************************************\
*                      CHAR LINKED LIST TESTS                       *
\*******************************************************************/

/* default constructor test
 * Run the LinkedList default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_LL()
{
    CharLinkedList testLinkedList;
}

/* second constructor, newNode() test
 * Run the linkedlist second contructor to make sure there are no runtime 
 * errors or memory leaks.
 */
void second_constructor_LL()
{
    CharLinkedList testLinkedList('A');
}

/* print() test with the second constructor
 * Create a linked list with the second constructor and print it out with 
 * the second constructor.
 */
void print_second_LL()
{
    CharLinkedList testLinkedList('A');
    testLinkedList.print(); // [CharLinkedList of size 1 <<A>>]
}

/* print() test with the default constructor
 * Create an empty linked list with the default constructor and print it out 
 * with the second constructor.
 */
void print_default_LL()
{
    CharLinkedList testLinkedList;
    testLinkedList.print(); // [CharLinkedList of size 0 <<>>]
}

/* third constructor, testing print() with a bigger list
 * Run the linked list third contructor to make sure there are no runtime 
 * errors or memory leaks, use the third constructor to create a linked list 
 * of multiple elements, print the created linked list.
 */
void third_constructor_LL()
{
    char arr1[17] = {'I', 'A', 'm', 'H', 'u', 'n', 'g', 'r', 'y', 'F', 'o',
                     'r', 'S', 'u', 's', 'h', 'i'};
    CharLinkedList testLinkedList(arr1, 17);
    testLinkedList.print(); // Should be:
                         //[CharLinkedList of size 17 <<IAmHungryForSushi>>]
}

/* size() test
 * Initialize three linked lists with the three different constructors and
 * then checks their sizes with size() and assert().
 */
void size_LL()
{
    // default constructor size test
    CharLinkedList defaultConstruct;
    assert(defaultConstruct.size() == 0);
    
    // second constructor size test
    CharLinkedList second('A');
    assert(second.size() == 1);
    
    // third constructor size test
    char arr1[17] = {'I', 'A', 'm', 'H', 'u', 'n', 'g', 'r', 'y', 'F', 'o',
                     'r', 'S', 'u', 's', 'h', 'i'};
    CharLinkedList third(arr1, 17);
    assert(third.size() == 17);
    
}

/* isEmpty() test
 * Initialize an empty linked list and a non-empty linked list and use 
 * assert() to make sure isEmpty() returns true for the empty list and false
 * for the non-empty list.
 */
void isEmpty_LL()
{
    CharLinkedList emptyList;
    assert(emptyList.isEmpty());
    
    char arr1[5] = {'H', 'e', 'l', 'l', 'o'};
    CharLinkedList notEmptyList(arr1, 5);
    assert(not notEmptyList.isEmpty());
}

/* elementAt() test
 * Initialize a linked list of characters, use assert() to make sure 
 * elementAt() is returning the correct characters at different positions in
 * the list.
 */
void elementAt_LL() 
{
    char arr1[17] = {'I', 'A', 'm', 'H', 'u', 'n', 'g', 'r', 'y', 'F', 'o',
                     'r', 'S', 'u', 's', 'h', 'i'};
    CharLinkedList testLinkedList(arr1, 17);
    
    assert(testLinkedList.elementAt(0) == 'I');
    assert(testLinkedList.elementAt(1) == 'A');
    assert(testLinkedList.elementAt(10) == 'o');
    assert(testLinkedList.elementAt(15) == 'h');
    assert(testLinkedList.elementAt(16) == 'i');
    
    CharLinkedList testLinkedList2('A');
    assert(testLinkedList2.elementAt(0) == 'A');
}

/* elementAt() fail test
 * Initialize a linked list of characters, try to use elementAt() on an
 * invalid index (not between [0, size)), view the error message.
 */
/*
//void FAIL_elementAt_LL()
{
    char arr1[17] = {'I', 'A', 'm', 'H', 'u', 'n', 'g', 'r', 'y', 'F', 'o',
                   'r', 'S', 'u', 's', 'h', 'i'};
    CharLinkedList testLinkedList(arr1, 17);
  
    // testLinkedList.elementAt(-1); // index -1 not in range [0..17)
    
    testLinkedList.elementAt(17); // index 17 not in range [0..17)

}
*/

/* first() and last()
 * Initialize linked lists of characters, use first() and last() to get the
 * first and last elements of these lists, use assert() to make sure they are
 * getting the correct elements.
 */
void first_last_LL()
{
    // testing on a list with multiple elements
    char arr1[5] = {'H', 'e', 'l', 'l', 'o'};
    CharLinkedList test1(arr1, 5);
    assert(test1.first() == 'H');
    assert(test1.last() == 'o');
    
    // testing on a list with only one element
    CharLinkedList test2('A');
    assert(test2.first() == 'A');
    assert(test2.last() == 'A');
}

/* first() failure test
 * try to use first() on an empty linked list to see if it prints
 * the correct error message
 */
/*
//void FAIL_first_LL()
{
    CharLinkedList testLinkedList;
    testLinkedList.first(); // Cannot get the first element of an empty list
}
*/

 /* last() failure test
  * try to use last() on an empty linked list to see if it prints
  * the correct error message
  */
/*
//void FAIL_last_LL()
{
    CharLinkedList testLinkedList;
    testLinkedList.last(); // Cannot get the last element of an empty list
}
*/

/* clear() test
 * use the clear() function on three different linked lists made from the
 * three different constructors and then use assert() and isEmpty() to make
 * sure the result is three empty lists.
 */
 
void clear_LL()
{
    // testing on a list of multiple elements
    char example[6] = {'K','i','r','i','n','G'};
    CharLinkedList testLinkedList(example, 6);
    assert(testLinkedList.size() == 6);
    testLinkedList.clear();
    assert(testLinkedList.isEmpty());
    assert(testLinkedList.size() == 0);
    testLinkedList.print(); // should print an empty list
                         // [CharArrayList of size 0 <<>>]    

    // testing on an empty list
    CharLinkedList testLinkedList1;
    testLinkedList1.clear();
    assert(testLinkedList1.isEmpty());

    // testing on a one element list
    CharLinkedList testLinkedList2('A');
    testLinkedList2.clear();
    assert(testLinkedList2.isEmpty());    
}

/* pushAtBack() test
 * use the pushAtBack() function on three different linked lists made from
 * the three different constructors and then use assert(), size(), first(),
 * last(), and print() to make sure pushAtBack() functions correctly.
 */
void pushAtBack_LL() 
{
    // testing on a larger list
    char example[10] = {'A','A','A','A','A','A','A','A','A','A'};
    CharLinkedList testLinkedList(example, 10);
    assert(testLinkedList.size() == 10);
    testLinkedList.pushAtBack('B');
    assert(testLinkedList.size() == 11);
    assert(testLinkedList.last() == 'B');
    testLinkedList.print(); // [CharLinkedList of size 11 <<AAAAAAAAAAB>>]
  
    // testing pushAtBack() on an empty list
    CharLinkedList testLinkedList2;
    testLinkedList2.pushAtBack('A');
    assert(testLinkedList2.size() == 1);
    assert(testLinkedList2.first() == 'A');
    assert(testLinkedList2.last() == 'A');
  
    // testing on a list with one element 
    CharLinkedList testLinkedList3('A');
    testLinkedList3.pushAtBack('B');
    assert(testLinkedList3.size() == 2);
    assert(testLinkedList3.first() == 'A');
    assert(testLinkedList3.last() == 'B');
}

/* pushAtFront() test
 * use the pushAtFront() function on three different linked lists made from
 * the three different constructors and then use assert(), size(), first(),
 * last(), and print() to make sure pushAtBack() functions correctly.
 */
void pushAtFront_LL() 
{
    // testing on a larger list
    char example[10] = {'A','A','A','A','A','A','A','A','A','A'};
    CharLinkedList testLinkedList(example, 10);
    assert(testLinkedList.size() == 10);
    testLinkedList.pushAtFront('B');
    assert(testLinkedList.size() == 11);
    assert(testLinkedList.first() == 'B');
    testLinkedList.print(); // [CharLinkedList of size 11 <<BAAAAAAAAAA>>]

    // testing pushAtBack() on an empty list
    CharLinkedList testLinkedList2;
    testLinkedList2.pushAtFront('A');
    assert(testLinkedList2.size() == 1);
    assert(testLinkedList2.first() == 'A');
    assert(testLinkedList2.last() == 'A');

    // testing on a list with one element 
    CharLinkedList testLinkedList3('B');
    testLinkedList3.pushAtFront('A');
    assert(testLinkedList3.size() == 2);
    assert(testLinkedList3.first() == 'A');
    assert(testLinkedList3.last() == 'B');
}

/* insertAt test
 * Create three linked lists each with one of the three constructors (one)
 * empty list, one list with one character, and one with multiple characters).
 * Run the insertAt() function to add characters to the lists. Check that the
 * addition is successful using the assert() function, the size() function,
 * and the print() function. 
 */
void insertAt_LL()
{
    CharLinkedList testLinkedList2;
    testLinkedList2.insertAt('A', 0);
    assert(testLinkedList2.size() == 1);
    assert(testLinkedList2.elementAt(0) == 'A');
  
    CharLinkedList testLinkedList3('B');
    testLinkedList3.insertAt('A', 0);
    testLinkedList3.insertAt('C', 2);
    assert(testLinkedList3.size() == 3);
    assert(testLinkedList3.elementAt(0) == 'A');
    assert(testLinkedList3.elementAt(1) == 'B');
    assert(testLinkedList3.elementAt(2) == 'C');
  
    char example[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    CharLinkedList testLinkedList(example, 9);
    testLinkedList.insertAt('Z', 3);
    testLinkedList.insertAt('W', 5);
    testLinkedList.insertAt('X', 0);
    testLinkedList.insertAt('Y', 12);
    testLinkedList.insertAt('Q', 13);
    testLinkedList.insertAt('V', 7);
    assert(testLinkedList.size() == 15);
    assert(testLinkedList.elementAt(4) == 'Z');
    assert(testLinkedList.elementAt(6) == 'W');
    assert(testLinkedList.elementAt(0) == 'X');
    assert(testLinkedList.elementAt(13) == 'Y');
    assert(testLinkedList.elementAt(14) == 'Q');
    assert(testLinkedList.elementAt(7) == 'V');
    testLinkedList.print(); //[CharLinkedList of size 15 <<XAYBCZDVWEFGHIQ>>]
}

/* insertAt failure test
 * try to use insertAt to insert an element at an invalid index in the 
 * linked list
 */
/*
//void FAIL1_insertAt_LL()
{
    char example[4] = {'A','B','C','D'};
    CharLinkedList testLinkedList(example, 4);
    testLinkedList.insertAt('Z', 5);
}
*/

 /* insertAt failure test
  * try to use insertAt to insert an element at an invalid index in the
  * linked list
  */
/*
//void FAIL2_insertAt_LL()
{
    char example[4] = {'A','B','C','D'};
    CharLinkedList testLinkedList(example, 4);
    testLinkedList.insertAt('Z', -1);
}
*/

/* copy constructor test
 * use the copy constructor to create a list with the same information 
 * as a list passed into it
 */
void copy_constructor_LL()
{
    // create the list to copy
    char arr[6] = {'T','e','n','n','i','s'};
    CharLinkedList toCopy(arr, 6);
  
    // copy with the copy constructor 
    CharLinkedList copied(toCopy);
  
    // make sure the copy is correct
    assert(copied.size() == 6);
    assert(copied.first() == 'T');
    assert(copied.last() == 's');
    copied.print(); // should be [CharLinkedList of size 6 <<Tennis>>]
    
    // copying an empty list 
    CharLinkedList empty;
    CharLinkedList copyEmpty(empty);
    assert(copyEmpty.isEmpty());
    
    // copying a one element list
    CharLinkedList one('A');
    CharLinkedList copyOne(one);
    assert(copyOne.elementAt(0) == 'A');
    assert(copyOne.size() == 1);
}

/* assignment operator test 
 * run the assignment operator to make one linked list contain the same
 * information as another linked list
 */
void assignment_operator_LL()
{
    // create the original list
    char arr[3] = {'A', 'B', 'C'};
    CharLinkedList current(arr, 3);
    
    // create the list to transfer the information from
    char assign[17] = {'I', 'A', 'm', 'H', 'u', 'n', 'g', 'r', 'y', 'F', 'o',
                       'r', 'S', 'u', 's', 'h', 'i'};
    CharLinkedList toAssign(assign, 17);
    
    // use the assignment operator
    current = toAssign;
    assert(current.size() == 17);
    assert(current.first() == 'I');
    assert(current.last() == 'i');
    assert(current.elementAt(9) == 'F');
    current.print(); // [CharLinkedList of size 17 <<IAmHungryForSushi>>]
    
    CharLinkedList one('A');
    CharLinkedList empty;
    one = empty;
    assert(one.isEmpty());
    
    char arr2[5] = {'H', 'e', 'l', 'l', 'o'};
    CharLinkedList empty1;
    CharLinkedList notEmpty(arr2, 5);
    empty1 = notEmpty;
    assert(empty1.size() == 5);
    assert(empty1.first() == 'H');
    assert(empty1.last() == 'o');
}

/* removeAt_LL(), popFromBack(), popFromFront()
* Create three linked lists each with one of the three constructors (one 
* empty list, one list with one character, and one list with multiple
* characters. Run the removeAt() function to remove characters from the 
* lists. Check that the removals are successful using the assert() function,
* the size() function, the isEmpty() function, the elementAt() function, 
* and the print() function. Because popFromBack() and popFromFront() are
* used in removeAt() to remove first and last elements of lists, this test 
* also tests them, because they are called whenever removeAt() is asked 
* to remove the first or last element of a list.
*/
void removeAt_LL()
{
    // Testing popFromFront by calling removeAt() on a one element list
    // (called to remove the first element)
    CharLinkedList test1('A');
    test1.removeAt(0);
    assert(test1.isEmpty());
    
    char arr1[24] = {'Z', 'I', 'A', 'Z', 'm', 'H', 'u', 'Z', 'n', 'g', 'r', 
                     'y', 'Z', 'F', 'o', 'r', 'S', 'Z', 'u', 's', 'h', 'i', 
                     'Z', 'W'};
    CharLinkedList test2(arr1, 24);
    test2.removeAt(0);
    test2.removeAt(2);
    test2.removeAt(5);
    test2.removeAt(9);
    test2.removeAt(13);
    test2.removeAt(17); // this is a test of popFromBack() as well
    test2.popFromBack();
    test2.print();
    assert(test2.size() == 17);
    assert(test2.elementAt(0) == 'I');
    assert(test2.elementAt(3) == 'H');
    assert(test2.elementAt(7) == 'r');
    assert(test2.elementAt(12) == 'S');
    assert(test2.elementAt(16) == 'i');
    
}

/* FAIL removeAt test
 * Try to use removeAt with an invalid index to see if the correct error 
 * message prints out
 */
/*
//void FAIL_removeAt_LL()
{
    CharLinkedList empty;
    empty.removeAt(0);
    
    //char arr1[5] = {'H', 'e', 'l', 'l', 'o'};
    //CharLinkedList notEmpty(arr1, 5);
    //notEmpty.removeAt(-1);
    //notEmpty.removeAt(5);
}
*/

/* FAIL popFromBack() test
 * Try to use popFromBack() on an empty list to make sure the correct 
 * error message prints out
 */
/*
//void FAIL_popFromBack_LL()
{
    CharLinkedList empty;
    empty.popFromBack();
}
/*

/* FAIL popFromFront() test
 * Try to use popFromFront() on an empty list to make sure the correct 
 * error message prints out
 */
 /*
//void FAIL_popFromFront_LL()
{
    CharLinkedList empty;
    empty.popFromFront();
}
*/

/* concatenate() test
 * use the concatenate test to copy a second linked list to the back of the
 * first linked list. Test that this is successful using assert(), print(),
 * size(), and elementAt().
 */
void concatenate_LL()
{
    // first list
    char arr1[5] = {'K','i','r','i','n'};
    CharLinkedList list1(arr1, 5);
    // second list 
    char arr2[8] = {'G', 'o', 'd', 'h', 'w', 'a', 'n', 'i'};
    CharLinkedList list2(arr2,8);
    // add list 2 to the back of list1
    list1.concatenate(list2);
    // check if it worked with assert(), print(), size(), elementAt()
    assert(list1.size() == 13);
    assert(list1.elementAt(4) == 'n');
    assert(list1.elementAt(5) == 'G');
    list1.print(); // [CharArrayList of size 13 <<KirinGodhwani>>]
    
    CharLinkedList empty;
    CharLinkedList NotEmpty(arr2, 8);
    empty.concatenate(NotEmpty);
    assert(empty.size() == 8);
    assert(empty.elementAt(0) == 'G');
    assert(empty.elementAt(7) == 'i');
    
    CharLinkedList empty1;
    CharLinkedList NotEmpty1(arr2, 8);
    NotEmpty1.concatenate(empty1);
    assert(NotEmpty1.size() == 8);
    assert(NotEmpty1.elementAt(0) == 'G');
    assert(NotEmpty1.elementAt(7) == 'i');
}

/* replaceAt test
 * uses the replaceAt() function to replace the element at a given index 
 * in the list with a given character value
 */
void replaceAt_LL()
{
    char example[4] = {'A','B','C','D'};
    CharLinkedList testLinkedList(example, 4);
    
    testLinkedList.replaceAt('Z', 2);
    testLinkedList.replaceAt('W', 0);
    testLinkedList.replaceAt('Y', 3);
    assert(testLinkedList.elementAt(2) == 'Z');
    assert(testLinkedList.elementAt(0) == 'W');
    assert(testLinkedList.elementAt(3) == 'Y');
    testLinkedList.print(); // [CharLinkedList of size 4 <<WBZY>>]
}


/* FAIL replaceAt test
 * Try to use replaceAt with an invalid index to see if the error message is
 * correct
 */
/* 
//void FAIL_replaceAt_LL()
{
    char example[4] = {'A','B','C','D'};
    CharLinkedList testLinkedList(example, 4);
    
    testLinkedList.replaceAt('Z', 4);
    //testLinkedList.replaceAt('Z', -1);
}
*/

