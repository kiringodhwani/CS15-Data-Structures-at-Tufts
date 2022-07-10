/* 
 * CharLinkedList.h
 * 
 * CS 15 homework 1
 * by C.R. Calabrese, January 2021
 * edited by Kirin Godhwani, 9/26
 * 
 * One implementation of the CharList interface. Stores characters,
 * preserving their order and imitating some functionalities of the C++ 
 * std::string.
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

class CharLinkedList {
    public:
        // constructors
        // initial capacity will be zero for default constructor
        CharLinkedList();
        // start with a single character
        CharLinkedList(char c);
        // start with a list of characters
        CharLinkedList(char *arr, int size); 
        // start with another CharList
        CharLinkedList(const CharLinkedList &other); 
        // destructor
        ~CharLinkedList();
        // assignment operator overload
        CharLinkedList &operator =(const CharLinkedList &rhs);


        // CharList functions
        // get information about the list -- these won't modify the list
        bool isEmpty() const;
        int  size() const;
        char first() const;
        char last() const;
        char elementAt(int idx) const;
        void print() const;
        // insert into the list
        void pushAtBack(char c);
        void pushAtFront(char c);
        void insertAt(char c, int idx);
        // remove from the list
        void clear();
        void popFromFront();
        void popFromBack();
        void removeAt(int idx);
        // other ways to edit the list
        void replaceAt(char c, int idx);
        void concatenate(const CharLinkedList &other);

    private:
        struct Node {
            char c;
            Node *next;
            Node *prev;
        };

        Node *front;          // pointer to first node in list or nullptr
        int   numElements;    // number of elements currently stored in list
        
        // private member functions 
        Node *newNode(char c, Node *next, Node *prev);
        
        // recursive functions called in wrapper functions
        void recycleRecursive(Node *curr); // used with the destructor
        void printRecHelper(Node *curr) const; // used with print() 
};

#endif