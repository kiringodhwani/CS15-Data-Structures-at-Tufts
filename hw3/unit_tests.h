/* 
 * unit_tests.h
 * 
 * CS 15 homework 3
 * By Kirin Godhwani, 11/6
 * 
 * Uses Matt Russell's unit_test framework to test the the BinarySearchTree
 * class. More information on this testing framework can be found in the Lab 1
 * handout
 *
 */

#include <iostream>
#include <cassert>
#include "BinarySearchTree.h"
#include <limits>


// ---------------------------------------------------------------------------

//                           DEFAULT CONSTRUCTOR

/* default constructor test
 * Run the BinarySearchTree default constructor to make sure there are no
 * runtime errors or memory leaks.
 */
void default_constructor_test()
{
    BinarySearchTree bst;
    bst.print_tree();
}

// ---------------------------------------------------------------------------

//                              TREE_HEIGHT

/* tree_height_empty
 * Testing the tree_height function on an empty tree.
 */
void tree_height_empty()
{
    BinarySearchTree bst;
    assert(bst.tree_height() == -1);
}

/* tree_height_root
 * Testing the tree_height function on a tree that has just a root with no
 * duplicates.
 */
void tree_height_root()
{
    BinarySearchTree bst;
    bst.insert(1);
    assert(bst.tree_height() == 0);
}

/* tree_height_duplicate
 * Testing the tree_height function on a tree that has just one root with a
 * duplicate.
 */
void tree_height_duplicate()
{
    BinarySearchTree bst;
    bst.insert(1);
    bst.insert(1);
    assert(bst.tree_height() == 0);
}

/* tree_height_bulk
 * Testing the tree_height function on a gwoing tree of many Nodes and
 * duplicates.
 */
void tree_height_bulk()
{
    BinarySearchTree bst;
    bst.insert(30);
    assert(bst.tree_height() == 0);
    bst.insert(22);
    assert(bst.tree_height() == 1);
    bst.insert(25);
    assert(bst.tree_height() == 2);
    bst.insert(45);
    assert(bst.tree_height() == 2);
    bst.insert(11);
    assert(bst.tree_height() == 2);
    bst.insert(40);
    assert(bst.tree_height() == 2);
    bst.insert(40);
    assert(bst.tree_height() == 2);
    bst.insert(30);
    assert(bst.tree_height() == 2);
    bst.insert(13);
    assert(bst.tree_height() == 3);
    bst.insert(23);
    assert(bst.tree_height() == 3);
    bst.insert(-22);
    assert(bst.tree_height() == 3);
    bst.insert(26);
    assert(bst.tree_height() == 3);
    bst.insert(41);
    assert(bst.tree_height() == 3);
    bst.insert(29);
    assert(bst.tree_height() == 4);
    bst.insert(-1);
    assert(bst.tree_height() == 4);
    bst.insert(-5);
    assert(bst.tree_height() == 5);
    bst.insert(0);
    bst.insert(1);
    assert(bst.tree_height() == 6);
}

// ---------------------------------------------------------------------------

//                                   INSERT

/* insert_single
 * Tests insert with a single insertion into an empty BST.
 */
void insert_single()
{
    BinarySearchTree bst;
    bst.insert(30);
    assert(bst.tree_height() == 0);
    assert(bst.node_count() == 1);
    bst.print_tree();
}

/* insert_duplicate
 * Tests the insertion of a duplicate value.
 */
void insert_duplicate()
{
    BinarySearchTree bst;
    bst.insert(30);
    bst.insert(30);
    assert(bst.tree_height() == 0);
    assert(bst.node_count() == 1);
    bst.print_tree();
}

/* insert_large
 * Testing the functionality of insert() on general cases and edge cases.
 * These cases include inserting non-duplicate nodes, inserting duplicates,
 * inserting into an empty tree, etc. The functionality of insert() is tested
 * using assert(), node_count(), tree_height(), and print().
 */
void insert_large()
{
    BinarySearchTree bst;
    bst.insert(30);
    assert(bst.tree_height() == 0);
    assert(bst.node_count() == 1);
    bst.print_tree();

    bst.insert(22);
    bst.insert(25);
    assert(bst.tree_height() == 2);
    assert(bst.node_count() == 3);
    bst.print_tree();

    bst.insert(45);
    bst.insert(11);
    bst.insert(40);
    bst.insert(40);
    bst.insert(40);
    bst.insert(30);
    assert(bst.tree_height() == 2);
    assert(bst.node_count() == 6);
    bst.print_tree();

    bst.insert(13);
    bst.insert(23);
    bst.insert(-22);
    bst.insert(26);
    bst.insert(41);
    bst.insert(29);
    bst.insert(-1);
    bst.insert(-5);
    assert(bst.tree_height() == 5);
    assert(bst.node_count() == 14);
    bst.print_tree();

    bst.insert(0);
    bst.insert(1);
    assert(bst.tree_height() == 6);
    assert(bst.node_count() == 16);
    bst.print_tree();
}

// ---------------------------------------------------------------------------

//                              NODE_COUNT

/* node_count_empty
 * Testing node_count on an empty tree.
 */
void node_count_empty()
{
    BinarySearchTree bst;
    assert(bst.node_count() == 0);
}

/* node_count_root
 * Testing node_count on a tree that has just a root with no duplicates.
 */
void node_count_root()
{
    BinarySearchTree bst;
    bst.insert(25);
    assert(bst.node_count() == 1);
}

/* node_count_duplicate
 * Testing node_count on a tree that has just one Node with a duplicate.
 */
void node_count_duplicate()
{
    BinarySearchTree bst;
    bst.insert(100);
    bst.insert(100);
    assert(bst.node_count() == 1);
}

/* node_count_bulk
 * Testing node_count on a growing tree with many Nodes and duplicates.
 */
void node_count_bulk()
{
    BinarySearchTree bst;
    assert(bst.node_count() == 0);
    bst.insert(25);
    assert(bst.node_count() == 1);
    bst.insert(25);
    assert(bst.node_count() == 1);
    bst.insert(25);
    assert(bst.node_count() == 1);
    bst.insert(-100);
    assert(bst.node_count() == 2);
    bst.insert(546);
    assert(bst.node_count() == 3);
    bst.insert(-3);
    assert(bst.node_count() == 4);
    bst.insert(-100);
    assert(bst.node_count() == 4);
    bst.insert(1);
    assert(bst.node_count() == 5);
    bst.insert(1000);
    assert(bst.node_count() == 6);
    bst.insert(9);
    assert(bst.node_count() == 7);
    bst.insert(1);
    assert(bst.node_count() == 7);
    bst.insert(5999);
    assert(bst.node_count() == 8);
    bst.insert(98);
    assert(bst.node_count() == 9);
    bst.insert(0);
    assert(bst.node_count() == 10);

}

// ---------------------------------------------------------------------------

//                              COUNT_TOTAl

/* count_total_empty
 * Testing count_total on an empty tree.
 */
void count_total_empty()
{
    BinarySearchTree bst;
    assert(bst.count_total() == 0);
}

/* count_total_root
 * Testing count_total on a tree that has just a root with no duplicates.
 */
void count_total_root()
{
    BinarySearchTree bst;
    bst.insert(25);
    assert(bst.count_total() == 25);

    BinarySearchTree zero;
    zero.insert(0);
    assert(zero.count_total() == 0);
}

/* count_total_duplicate
 * Testing count_total on a tree that has just one Node with a single
 * duplicate and a tree with just one Node with many duplicates.
 */
void count_total_duplicate()
{
    BinarySearchTree oneDup;
    oneDup.insert(100);
    oneDup.insert(100);
    assert(oneDup.count_total() == 200);

    BinarySearchTree manyDup;
    manyDup.insert(-5);
    manyDup.insert(-5);
    manyDup.insert(-5);
    manyDup.insert(-5);
    manyDup.insert(-5);
    manyDup.insert(-5);
    assert(manyDup.count_total() == -30);
}

/* count_total_bulk
 * Testing count_total on a growing tree with many Nodes and duplicates.
 */
void count_total_bulk()
{
    BinarySearchTree bst;
    assert(bst.count_total() == 0);
    bst.insert(25);
    assert(bst.count_total() == 25);
    bst.insert(25);
    bst.insert(25);
    assert(bst.count_total() == 75);
    bst.insert(-100);
    assert(bst.count_total() == -25);
    bst.insert(546);
    assert(bst.count_total() == 521);
    bst.insert(-3);
    assert(bst.count_total() == 518);
    bst.insert(-100);
    assert(bst.count_total() == 418);
    bst.insert(1);
    assert(bst.count_total() == 419);
    bst.insert(1000);
    assert(bst.count_total() == 1419);
    bst.insert(9);
    assert(bst.count_total() == 1428);
    bst.insert(1);
    assert(bst.count_total() == 1429);
    bst.insert(5999);
    assert(bst.count_total() == 7428);
    bst.insert(98);
    assert(bst.count_total() == 7526);
    bst.insert(-26);
    assert(bst.count_total() == 7500);
    bst.insert(0);
    assert(bst.count_total() == 7500);
    bst.insert(0);
    bst.insert(-3500);
    assert(bst.count_total() == 4000);
    bst.insert(-3500);
    assert(bst.count_total() == 500);
    bst.insert(-200);
    bst.insert(-200);
    assert(bst.count_total() == 100);
    bst.insert(-45);
    bst.insert(-49);
    bst.insert(-6);
    assert(bst.count_total() == 0);
}

// ---------------------------------------------------------------------------

//                               CONTAINS

/* contains_empty
 * Testing contains on an empty tree.
 */
void contains_empty()
{
    BinarySearchTree bst;
    assert(bst.contains(0) == false);
}

/* contains_root
 * Testing contains on a tree that has just a root with no duplicates.
 */
void contains_root()
{
    BinarySearchTree bst;
    bst.insert(25);
    assert(bst.contains(25) == true);
    assert(bst.contains(-1) == false);
}

/* contains_duplicate
 * Testing contains on a tree that has one Node with a duplicate.
 */
void contains_duplicate()
{
    BinarySearchTree bst;
    bst.insert(100);
    bst.insert(100);
    assert(bst.contains(100) == true);
    assert(bst.contains(-1) == false);
}

/* contains_bulk
 * Testing contains on a growing tree with many Nodes and duplicates.
 */
void contains_bulk()
{
    BinarySearchTree bst;
    assert(bst.contains(25) == false);
    bst.insert(25);
    assert(bst.contains(25) == true);
    bst.insert(25);
    bst.insert(25);
    assert(bst.contains(25) == true);
    assert(bst.contains(26) == false);
    bst.insert(-100);
    assert(bst.contains(-100) == true);
    assert(bst.contains(90) == false);
    bst.insert(546);
    assert(bst.contains(546) == true);
    bst.insert(-3);
    assert(bst.contains(-3) == true);
    bst.insert(-9000);
    assert(bst.contains(-9000) == true);
    assert(bst.contains(1) == false);
    bst.insert(1);
    assert(bst.contains(1) == true);
    bst.insert(1000);
    assert(bst.contains(1000) == true);
    bst.insert(98);
    assert(bst.contains(98) == true);
    bst.insert(-26);
    assert(bst.contains(-26) == true);
    bst.insert(0);
    assert(bst.contains(0) == true);
    assert(bst.contains(56789) == false);
}

//---------------------------------------------------------------------------

//                              FIND_MIN

/* find_min_empty
 * Testing find_min on an empty tree.
 */
void find_min_empty()
{
    BinarySearchTree bst;
    assert(bst.find_min() == std::numeric_limits<int>::max());
}

/* find_min_root
 * Testing find_min on a tree that has just a root with no duplicates.
 */
void find_min_root()
{
    BinarySearchTree bst;
    bst.insert(25);
    assert(bst.find_min() == 25);
}

/* find_min_duplicate
 * Testing find_min on a tree that has one Node with a duplicate.
 */
void find_min_duplicate()
{
    BinarySearchTree bst;
    bst.insert(100);
    bst.insert(100);
    assert(bst.find_min() == 100);
}

/* find_min_bulk
 * Testing find_min on a growing tree with many Nodes and duplicates.
 */
void find_min_bulk()
{
    BinarySearchTree bst;
    bst.insert(30);
    assert(bst.find_min() == 30);
    bst.insert(40);
    assert(bst.find_min() == 30);
    bst.insert(35);
    bst.insert(31);
    assert(bst.find_min() == 30);
    bst.insert(37);
    assert(bst.find_min() == 30);
    bst.insert(28);
    assert(bst.find_min() == 28);
    bst.insert(29);
    assert(bst.find_min() == 28);
    bst.insert(25);
    bst.insert(20);
    assert(bst.find_min() == 20);
    bst.insert(21);
    assert(bst.find_min() == 20);
    bst.insert(20);
    assert(bst.find_min() == 20);
    bst.insert(10);
    bst.insert(11);
    bst.insert(-5);
    bst.insert(-2);
    bst.insert(0);
    assert(bst.find_min() == -5);
}

// ---------------------------------------------------------------------------

//                               FIND_MAX

/* find_max_empty
 * Testing find_max on an empty tree.
 */
void find_max_empty()
{
    BinarySearchTree bst;
    assert(bst.find_max() == std::numeric_limits<int>::min());
}

/* find_max_root
 * Testing find_min on a tree that has just a root with no duplicates.
 */
void find_max_root()
{
    BinarySearchTree bst;
    bst.insert(25);
    assert(bst.find_max() == 25);
}

/* find_max_duplicate
 * Testing find_max on a tree that has one Node with a duplicate.
 */
void find_max_duplicate()
{
    BinarySearchTree bst;
    bst.insert(100);
    bst.insert(100);
    assert(bst.find_max() == 100);
}

/* find_max_bulk
 * Testing find_max on a growing tree with many Nodes and duplicates.
 */
void find_max_bulk()
{
    BinarySearchTree bst;
    bst.insert(30);
    assert(bst.find_max() == 30);
    bst.insert(20);
    assert(bst.find_max() == 30);
    bst.insert(25);
    bst.insert(29);
    assert(bst.find_max() == 30);
    bst.insert(32);
    assert(bst.find_max() == 32);
    bst.insert(31);
    assert(bst.find_max() == 32);
    bst.insert(35);
    bst.insert(40);
    assert(bst.find_max() == 40);
    bst.insert(39);
    assert(bst.find_max() == 40);
    bst.insert(31);
    bst.insert(39);
    assert(bst.find_max() == 40);
    bst.insert(50);
    bst.insert(90);
    bst.insert(0);
    bst.insert(70);
    bst.insert(-99);
    bst.insert(98);
    assert(bst.find_max() == 98);

}


// ---------------------------------------------------------------------------

//                            COPY CONSTRUCTOR

/* copy_empty
 * Using the copy constructor to copy an empty BST.
 */
void copy_empty()
{
    BinarySearchTree bst;

    BinarySearchTree copy(bst);

    assert(copy.count_total() == 0);
    assert(copy.node_count() == 0);
    assert(copy.tree_height() == -1);
    copy.print_tree();
}

/* copy_root
 * Using the copy constructor to copy a BST with a single Node with no
 * duplicates.
 */
void copy_root()
{
    BinarySearchTree bst;
    bst.insert(25);

    BinarySearchTree copy(bst);

    assert(copy.count_total() == 25);
    assert(copy.node_count() == 1);
    assert(copy.tree_height() == 0);
    copy.print_tree();
}

/* copy_duplicate
 * Using the copy constructor to copy a BST with a single Node that has
 * duplicates.
 */
void copy_duplicate()
{
    BinarySearchTree bst;
    bst.insert(100);
    bst.insert(100);

    BinarySearchTree copy(bst);

    assert(copy.count_total() == 200);
    assert(copy.node_count() == 1);
    assert(copy.tree_height() == 0);
    copy.print_tree();
}

/* copy_bulk
 * Using the copy constructor to copy a BST with many Nodes and duplicates.
 */
void copy_bulk()
{
    BinarySearchTree bst;
    bst.insert(25);
    bst.insert(25);
    bst.insert(25);
    bst.insert(-100);
    bst.insert(546);
    bst.insert(-3);
    bst.insert(-9000);
    bst.insert(1);
    bst.insert(1000);
    bst.insert(98);
    bst.insert(-26);
    bst.insert(5999);
    bst.insert(98);
    bst.insert(-26);
    bst.insert(0);
    bst.insert(0);
    bst.insert(-3500);
    bst.insert(-3500);
    bst.insert(-45);
    bst.insert(-49);
    bst.insert(-6);
    bst.insert(9000);

    BinarySearchTree copy(bst);

    assert(copy.count_total() == 562);
    assert(copy.node_count() == 16);
    assert(copy.tree_height() == 5);
    copy.print_tree();
}

// ---------------------------------------------------------------------------

//                          ASSIGNMENT OPERATOR

/* assignment_nullptr_to_nullptr
 * Testing the assignment operator when two empty trees are assigned to each
 * other.
 */
void assignment_nullptr_to_nullptr()
{
    BinarySearchTree bst1;
    BinarySearchTree assign1;
    assign1 = bst1;
    assert(assign1.count_total() == 0);
    assert(assign1.node_count() == 0);
    assert(assign1.tree_height() == -1);
}


/* assignment_one_to_one
 * Testing the assignment operator when two trees of one Node are assigned to
 * each other.
 */
void assignment_one_to_one()
{
    BinarySearchTree bst2;
    bst2.insert(2);
    BinarySearchTree assign2;
    assign2.insert(2);
    assign2 = bst2;
    assert(assign2.count_total() == 2);
    assert(assign2.node_count() == 1);
    assert(assign2.tree_height() == 0);
}

/* assignment_dup_to_dup
 * Testing the assignment operator when two trees of one Node with duplicates
 * are assigned to each other
 */
void assignment_dup_to_dup()
{
    BinarySearchTree bst3;
    bst3.insert(2);
    bst3.insert(2);
    BinarySearchTree assign3;
    assign3.insert(2);
    assign3.insert(2);
    assign3 = bst3;
    assert(assign3.count_total() == 4);
    assert(assign3.node_count() == 1);
    assert(assign3.tree_height() == 0);
}

/* assignment_manysame_to_manysame
 * Testing the assignment operator when two equal trees with many Nodes and
 * duplicates are assigned to each other.
 */
void assignment_manysame_to_manysame()
{
    BinarySearchTree bst4;
    bst4.insert(25);
    bst4.insert(25);
    bst4.insert(25);
    bst4.insert(-100);
    bst4.insert(546);
    bst4.insert(-3);
    bst4.insert(-9000);
    bst4.insert(1);
    BinarySearchTree assign4(bst4);
    assign4 = bst4;
    assert(assign4.count_total() == -8481);
    assert(assign4.node_count() == 6);
    assert(assign4.tree_height() == 3); 
}

/* assignment_nullptr_to_one
 * Tests the assignment operator when the current list is equal to nullptr 
 * and the list it is being assigned to has one Node.
 */
void assignment_nullptr_to_one()
{
    BinarySearchTree root;
    root.insert(19);
    BinarySearchTree curr1;
    curr1 = root;
    assert(curr1.count_total() == 19);
    assert(curr1.node_count() == 1);
    assert(curr1.tree_height() == 0); 
    curr1.print_tree();
}

/* assignment_nullptr_to_many
 * Assigning an empty tree to a tree that has many Nodes and duplicates
 */
void assignment_nullptr_to_many()
{
    // assigning to a tree that has many Nodes and duplicates
    BinarySearchTree many;
    many.insert(19);
    many.insert(26);
    many.insert(26);
    many.insert(0);
    many.insert(10);
    many.insert(-5);
    many.insert(22);
    many.insert(153);
    many.insert(15);
    many.insert(-300);
    many.insert(-2);
    many.insert(101);
    many.insert(123);
    many.insert(153);
    BinarySearchTree curr2;
    curr2 = many;
    assert(curr2.count_total() == 341);
    assert(curr2.node_count() == 12);
    assert(curr2.tree_height() == 4); 
    curr2.print_tree();
}

/* assignment_one_to_nullptr
 * Tests the assignment operator when the current list has one Node and the
 * list it is being assigned to is empty.
 */
void assignment_one_to_nullptr()
{
    BinarySearchTree curr1;
    curr1.insert(19);
    BinarySearchTree empty;
    curr1 = empty;
    assert(curr1.count_total() == 0);
    assert(curr1.node_count() == 0);
    assert(curr1.tree_height() == -1); 
}

/* assignment_many_to_nullptr
 * Tests the assignment operator when the current list has many Nodes and the
 * list it is being assigned to is empty.
 */
void assignment_many_to_nullptr()
{
    // assigning a tree of many Nodes and duplicates to an empty tree
    BinarySearchTree curr1;
    curr1.insert(19);
    curr1.insert(26);
    curr1.insert(26);
    curr1.insert(26);
    curr1.insert(0);
    curr1.insert(10);
    curr1.insert(-5);
    curr1.insert(22);
    curr1.insert(153);
    curr1.insert(15);
    curr1.insert(-300);
    curr1.insert(19);
    BinarySearchTree empty;
    curr1 = empty;
    assert(curr1.count_total() == 0);
    assert(curr1.node_count() == 0);
    assert(curr1.tree_height() == -1); 
}

/* assignment_many_to_one
 * Assigning a tree of many Nodes and duplicates to a tree with a single Node
 */
void assignment_many_to_one()
{
    BinarySearchTree curr2;
    curr2.insert(19);
    curr2.insert(26);
    curr2.insert(26);
    curr2.insert(26);
    curr2.insert(0);
    curr2.insert(10);
    curr2.insert(-5);
    curr2.insert(22);
    curr2.insert(153);
    curr2.insert(15);
    curr2.insert(-300);
    curr2.insert(19);
    BinarySearchTree single;
    single.insert(6);
    curr2 = single;
    assert(curr2.count_total() == 6);
    assert(curr2.node_count() == 1);
    assert(curr2.tree_height() == 0);
    curr2.print_tree();  
}

/* assignment_manydiff_to_manydiff
 * Assigning a tree of many Nodes and duplicates to a different tree with
 * many Nodes and duplicates
 */
void assignment_manydiff_to_manydiff()
{
    BinarySearchTree curr3;
    curr3.insert(19);
    curr3.insert(26);
    curr3.insert(26);
    curr3.insert(26);
    curr3.insert(0);
    curr3.insert(10);
    curr3.insert(-5);
    curr3.insert(22);
    curr3.insert(153);
    curr3.insert(15);
    curr3.insert(-300);
    curr3.insert(19);
    BinarySearchTree many;
    many.insert(150);
    many.insert(115);
    many.insert(194);
    many.insert(-200);
    many.insert(130);
    many.insert(153);
    many.insert(117);
    many.insert(-54);
    many.insert(-245);
    many.insert(312);
    many.insert(135);
    many.insert(144);
    many.insert(115);
    many.insert(-245);
    many.insert(-245);
    many.insert(194);
    curr3 = many;
    assert(curr3.count_total() == 770);
    assert(curr3.node_count() == 12);
    assert(curr3.tree_height() == 4); 
    curr3.print_tree();
}


/* assignment_same_root
 * Testing the assignment operator when the current tree and the tree it 
 * is being assigned to have the same root but different other Nodes.
 */
void assignment_same_root()
{
    BinarySearchTree assign;
    assign.insert(25);
    assign.insert(-100);
    assign.insert(546);
    assign.insert(-3);
    assign.insert(-9000);
    assign.insert(1);
    assign.insert(1000);
    assign.insert(98);
    assign.insert(-26);
    BinarySearchTree current;
    current.insert(25);
    current.insert(12);
    current.insert(0);
    current.insert(40);
    current = assign;
    assert(current.count_total() == -7459);
    assert(current.node_count() == 9);
    assert(current.tree_height() == 3);
    current.print_tree();   
}

// ---------------------------------------------------------------------------

//                              REMOVE

/* remove_empty
 * Testing remove on an empty tree.
 */
void remove_empty()
{
    BinarySearchTree bst;
    assert(bst.remove(0) == false);
    assert(bst.remove(25) == false);
}


/* remove_node_not_in_tree
 * Testing remove when the value it is given is not in the tree
 */
void remove_node_not_in_tree()
{
    BinarySearchTree bst;
    bst.insert(25);
    assert(bst.remove(2) == false);
    bst.insert(40);
    bst.insert(-5);
    bst.insert(0);
    assert(bst.remove(-90) == false);
}

/* remove_single_node
 * Uses remove to remove the single Node in a tree with one Node.
 */
void remove_single_node()
{
    BinarySearchTree bst;
    bst.insert(25);
    assert(bst.remove(25) == true);
    assert(bst.count_total() == 0);
    assert(bst.node_count() == 0);
    assert(bst.tree_height() == -1);
}

/* remove_two_nodes
 * Uses remove to remove the child of the root in a tree of two Nodes.
 */
void remove_two_nodes()
{
    // left child
    BinarySearchTree bst;
    bst.insert(30);
    bst.insert(5);
    std::cerr << "Before: " << std::endl;
    bst.print_tree();
    assert(bst.remove(5) == true);
    assert(bst.count_total() == 30);
    assert(bst.node_count() == 1);
    assert(bst.tree_height() == 0);
    std::cerr << "After: " << std::endl;
    bst.print_tree();

    // right child
    BinarySearchTree bst2;
    bst2.insert(30);
    bst2.insert(45);
    std::cerr << "Before: " << std::endl;
    bst2.print_tree();
    assert(bst2.remove(45) == true);
    assert(bst2.count_total() == 30);
    assert(bst2.node_count() == 1);
    assert(bst2.tree_height() == 0);
    std::cerr << "After: " << std::endl;
    bst2.print_tree();
}

/* remove_two_nodes_both
 * Uses remove to remove both children of the root in a tree of a root and two
 * children.
 */
void remove_two_nodes_both() {

    BinarySearchTree bst;
    bst.insert(30);
    bst.insert(45);
    bst.insert(5);
    std::cerr << "Before: " << std::endl;
    bst.print_tree();
    assert(bst.remove(5) == true);
    assert(bst.count_total() == 75);
    assert(bst.node_count() == 2);
    assert(bst.tree_height() == 1);
    bst.print_tree();
    assert(bst.remove(45) == true);
    assert(bst.count_total() == 30);
    assert(bst.node_count() == 1);
    assert(bst.tree_height() == 0);
    std::cerr << "After: " << std::endl;
    bst.print_tree();
}

/* remove_parent_of_one
 * In a tree of two Nodes (root and child), remove the parent.
 */
void remove_parent_of_one()
{
    // right subtree
    BinarySearchTree bst;
    bst.insert(30);
    bst.insert(45);
    std::cerr << "Before: " << std::endl;
    bst.print_tree();
    assert(bst.remove(30) == true);
    assert(bst.count_total() == 45);
    assert(bst.node_count() == 1);
    assert(bst.tree_height() == 0);
    std::cerr << "After: " << std::endl;
    bst.print_tree();

    // left subtree 
    BinarySearchTree bst2;
    bst2.insert(30);
    bst2.insert(5);
    std::cerr << "Before: " << std::endl;
    bst2.print_tree();
    assert(bst2.remove(30) == true);
    assert(bst2.count_total() == 5);
    assert(bst2.node_count() == 1);
    assert(bst2.tree_height() == 0);
    std::cerr << "After: " << std::endl;
    bst2.print_tree();
}

/* remove_parent_of_two
 * In a tree of three Nodes(root with two children), remove the root.
 */
void remove_parent_of_two()
{
    BinarySearchTree bst;
    bst.insert(30);
    bst.insert(45);
    bst.insert(5);
    std::cerr << "Before: " << std::endl;
    bst.print_tree();
    assert(bst.remove(30) == true);
    std::cerr << "After: " << std::endl;
    bst.print_tree();
    assert(bst.count_total() == 50);
    assert(bst.node_count() == 2);
    assert(bst.tree_height() == 1);
}

/* remove_dup
 * Uses remove to remove a Node with a count greater than 1.
 */ 
void remove_dup()
{
    BinarySearchTree bst;
    bst.insert(-9);
    bst.insert(-9);
    bst.insert(-9);
    bst.insert(-9);
    std::cerr << "Before: " << std::endl;
    bst.print_tree();
    assert(bst.remove(-9) == true);
    assert(bst.remove(-9) == true);
    assert(bst.remove(-9) == true);
    std::cerr << "After: " << std::endl;
    bst.print_tree();
    assert(bst.count_total() == -9);
    assert(bst.node_count() == 1);
    assert(bst.tree_height() == 0);
}

/* leaf_deletion
 * Uses remove to remove the leaves of a tree with a height greater than 1.
 * Tests the leaf condition of remove.
 */ 
void leaf_deletion()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(20);
    bst.insert(90);
    bst.insert(-10);
    bst.insert(115);
    bst.insert(77);
    bst.insert(34);
    std::cerr << "Before: " << std::endl;
    bst.print_tree();
    assert(bst.remove(-10) == true);
    assert(bst.remove(34) == true);
    assert(bst.remove(77) == true);
    assert(bst.remove(115) == true);
    assert(bst.remove(199) == false);
    std::cerr << "After: " << std::endl;
    bst.print_tree();
    assert(bst.count_total() == 160);
    assert(bst.node_count() == 3);
    assert(bst.tree_height() == 1);
}

/* internal_node_deletion
 * Uses remove to remove the internal Nodes of a tree with a height greater
 * than 1. Tests the 2 child condition of remove.
 */ 
void internal_node_deletion()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(20);
    bst.insert(90);
    bst.insert(-10);
    bst.insert(115);
    bst.insert(77);
    bst.insert(34);
    std::cerr << "Before: " << std::endl;
    bst.print_tree();
    assert(bst.remove(20) == true);
    assert(bst.remove(90) == true);
    assert(bst.remove(209) == false);
    std::cerr << "After: " << std::endl;
    bst.print_tree();
    assert(bst.count_total() == 266);
    assert(bst.node_count() == 5);
    assert(bst.tree_height() == 2);
}

/* root_deletion
 * Uses remove to remove the root of a tree with a height greater than 1.
 * Tests the 2 child condition of remove.
 */ 
void root_deletion()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(20);
    bst.insert(90);
    bst.insert(-10);
    bst.insert(115);
    bst.insert(77);
    bst.insert(34);
    std::cerr << "Before: " << std::endl;
    bst.print_tree();
    assert(bst.remove(50) == true);
    std::cerr << "After: " << std::endl;
    bst.print_tree();
    assert(bst.count_total() == 326);
    assert(bst.node_count() == 6);
    assert(bst.tree_height() == 2);
}


/* node_has_one_child
 * Removal from a height 2 tree where the children of the root each only have
 * one child. Purpose is to test the case when the Node to be removed has one
 * one child.
 */
void node_has_one_child()
{
    BinarySearchTree bst1;
    bst1.insert(50);
    bst1.insert(20);
    bst1.insert(90);
    bst1.insert(32);
    bst1.insert(74);
    std::cerr << "Before: " << std::endl;
    bst1.print_tree();
    assert(bst1.remove(20) == true);
    assert(bst1.remove(90) == true);
    std::cerr << "After: " << std::endl;
    bst1.print_tree();
    assert(bst1.count_total() == 156);
    assert(bst1.node_count() == 3);
    assert(bst1.tree_height() == 1);

    BinarySearchTree bst2;
    bst2.insert(50);
    bst2.insert(20);
    bst2.insert(90);
    bst2.insert(-15);
    bst2.insert(117);
    std::cerr << "Before: " << std::endl;
    bst2.print_tree();
    assert(bst2.remove(20) == true);
    assert(bst2.remove(90) == true);
    std::cerr << "After: " << std::endl;
    bst2.print_tree();
    assert(bst2.count_total() == 152);
    assert(bst2.node_count() == 3);
    assert(bst2.tree_height() == 1);
}

/* remove_bulk
 * Bulk test to test all cases of remove. Creating a large BST of many Nodes
 * and duplicates and using remove on different values in the BST.
 */
void remove_bulk()
{
    BinarySearchTree many;
    many.insert(19);
    many.insert(26);
    many.insert(26);
    many.insert(26);
    many.insert(0);
    many.insert(10);
    many.insert(-5);
    many.insert(22);
    many.insert(153);
    many.insert(15);
    many.insert(15);
    many.insert(-300);
    many.insert(19);
    many.insert(150);
    many.insert(115);
    many.insert(194);
    many.insert(-200);
    many.insert(130);
    many.insert(153);
    many.insert(117);
    many.insert(-54);
    many.insert(-245);
    many.insert(312);
    many.insert(135);
    many.insert(144);
    many.insert(115);
    many.insert(-245);
    many.insert(-245);
    many.insert(194);
    many.insert(7);
    many.insert(-3);
    many.insert(-4);
    many.insert(-1);
    many.insert(23);
    many.insert(20);
    many.insert(160);
    many.insert(12);
    many.insert(17);
    std::cerr << "Before: " << std::endl;
    many.print_tree();
    assert(many.remove(19) == true);
    assert(many.remove(19) == true);
    assert(many.remove(26) == true);
    assert(many.remove(26) == true);
    assert(many.remove(26) == true);
    assert(many.remove(135) == true);
    assert(many.remove(117) == true);
    assert(many.remove(150) == true);
    assert(many.remove(194) == true);
    assert(many.remove(194) == true);
    assert(many.remove(0) == true);
    assert(many.remove(15) == true);
    assert(many.remove(10) == true);
    assert(many.remove(-5) == true);
    assert(many.remove(-1) == true);
    assert(many.remove(-200) == true);
    assert(many.remove(-300) == true);
    assert(many.remove(-245) == true);
    assert(many.remove(15) == true);
    assert(many.remove(153) == true);

    std::cerr << "After: " << std::endl;
    many.print_tree();
    assert(many.count_total() == 679);
    assert(many.node_count() == 16);
    assert(many.tree_height() == 4);
}

/* two_children_dup
 * I noticed while bulk testing that my program failed when deleting a Node
 * with 2 children where the replacement had a count of more than 1. This test
 * is made specifically to test this case.
 */
void two_children_dup() {
    BinarySearchTree bst;
    bst.insert(20);
    bst.insert(34);
    bst.insert(34);
    bst.insert(34);
    bst.insert(34);
    bst.insert(11);
    std::cerr << "Before: " << std::endl;
    bst.print_tree();
    assert(bst.remove(20) == true);
    std::cerr << "After: " << std::endl;
    bst.print_tree();
    assert(bst.count_total() == 147);
    assert(bst.node_count() == 2);
    assert(bst.tree_height() == 1);

    BinarySearchTree bst2;
    bst2.insert(34);
    bst2.insert(11);
    bst2.insert(60);
    bst2.insert(4);
    bst2.insert(20);
    bst2.insert(41);
    bst2.insert(70);
    bst2.insert(41);
    bst2.insert(41);
    bst2.insert(41);
    std::cerr << "Before: " << std::endl;
    bst2.print_tree();
    assert(bst2.remove(34) == true);
    std::cerr << "After: " << std::endl;
    bst2.print_tree();
    assert(bst2.count_total() == 329);
    assert(bst2.node_count() == 6);
    assert(bst2.tree_height() == 2);
}

// ---------------------------------------------------------------------------


