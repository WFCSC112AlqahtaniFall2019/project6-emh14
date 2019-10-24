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
    // The Big Three

    //1. Destructor
    LinkList();

    //2. Destructor
    ~ LinkList();

    //3. Copy constructor
    LinkList(const LinkList &list);

    //Copy Assignment Operator
    LinkList & operator=(const LinkList &rhs);

private:
    Node *head; // start of the list
};


#endif //BINARYINSERTIONSORT_LINKEDLIST_H
