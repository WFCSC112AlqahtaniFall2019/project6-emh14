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
    LinkList & operator=(const LinkList &rhs);

    //Add an item to to the list
    void append(int item);

    //Remove an item from the list
    bool remove(int item);

private:
    Node *head; // start of the list
};


#endif //BINARYINSERTIONSORT_LINKEDLIST_H
