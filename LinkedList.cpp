//
// Created by Ethan Harrison on 10/24/19.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

// The Big Three

//Constructor
LinkList::LinkList(){
    cout << "Constructor Called" << endl;

}

//Destructor
LinkList::~LinkList(){
    cout << "Destructor Called" << endl;

}


//Copy constructor
LinkList::LinkList(const LinkList &list){
    cout << "Copy Constructor Called" << endl;

}

//Copy Assignment Operator
LinkList &LinkList::operator=(const LinkList &rhs){
    cout << "Copy Assignment Operator Called" << endl;

}

//Add an item to the list
void LinkList::append(int item){}

//Remove an item from the list
bool LinkList::remove(int item){}