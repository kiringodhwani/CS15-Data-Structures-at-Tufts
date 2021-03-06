# CS15
**Projects from CS15: Data Structures at Tufts University. All projects in C++.**
- **HW1:** This program offers two different lists that store characters (a linked list and an array list). They maintain the stored characters in their given order, with some extra features, such as the ability to concatenate lists. See CharArrayList.h and CharLinkedList.h to view the functions included in each the array list implementation and linked list implementation respectively.
- **HW2 (MetroSim):** Implements a program to simulate a running train that can accommodate Passengers arriving/departing the metro to and from a series of stations based on a set of given commands. Implemented using a modified version of a queue.
- **HW3:** The purpose of this program was to implement a binary search tree (BST) that supports a multiset (also known as a bag), which is a set that can contain duplicate values. The BST stores integer keys and tracks how many times each key has been inserted into the BST (a key that has not been inserted appears 0 times). Because this class handles multiplicity, if you insert a number twice and then remove it once, it will still be in the data structure. See BinarySearchTree.h for the functions included in the implementation.
- **Project 1 (RPN Calc):** Implements a working Reverse Polish Notation (RPN) calculator. RPN is also known as “postfix” notation. The calculator can handle various commands and operations such as arithmetic operations like addition and division, boolean operations with operators like ==, >, and <=, as well as commands that allow the user to operate the calculator and create different operations (e.g. adding integers, duplicating, swapping, dropping, clearing the calculator, etc.). The calculator can also execute inputted rstrings and read in input from a commands file. Implemented using a modified version of a stack.
-  **Project 2 (Six Degrees of Kevin Bacon):** Simulates the game Six Degrees of Kevin Bacon; however, instead of actors, the program uses musical artists and songs they have collaborated on with other artists. The program interactively accepts queries in the form of an input command and the names of artists. It then outputs a path to get from the first artist to the second via musical collaborations (with some restrictions depending on the input command). Implemented using a graph data structure and BFS and DFS.


**Topics include:**
- Array Lists
- Linked Lists
- Trees (specifically binary search trees)
- Graphs (BFS and DFS)
- Stacks and Queues
- Hash Tables (though no project on hash tables was assigned in the course)
