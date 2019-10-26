//
// Created by Ethan Harrison on 10/24/19.
//

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

class LinkList {

public:
    //Constructor
    LinkList();

    // The Big Three

    //1. Destructor
    ~ LinkList();

    //2. Copy constructor
    LinkList(const LinkList &list);

    //3. Copy Assignment Operator
    LinkList & operator=(const LinkList &copyList);

    //Add an item to the list
    void append(int item);

    //Remove an item from the list
    bool remove(int item);

    //Determine if item is in the list
    bool isItem(int item) const;

    //Print the linked list
    void printList() const;


    //Insertion Sort


private:
    Node *head; // start of the list
    //Node *current; // create node for current position of the list
};


#endif //BINARYINSERTIONSORT_LINKEDLIST_H
