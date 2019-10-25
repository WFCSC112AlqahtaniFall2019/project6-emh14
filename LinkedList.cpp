//
// Created by Ethan Harrison on 10/24/19.
//

#include "LinkedList.h"
#include <iostream>

using namespace std;

// The Big Three

//Constructor
LinkList::LinkList() {
    cout << "Constructor Called" << endl;

    //Initialize list as empty
    head = nullptr;
    current = head;
}

//Destructor
LinkList::~LinkList() {
    cout << "Destructor Called" << endl;

    current = head; //start at the front of the list
    Node *next; // Create new node to  to track where you are going

    while (current != nullptr) { //while current is not the tail
        next = current->next; //starting from the first node
        delete current; //delete the node
        current = next; // then move to the next
    }
}


//Copy constructor
LinkList::LinkList(const LinkList &list) {
    cout << "Copy Constructor Called" << endl;

    // case 1: if the list is empty
    if (list.head == nullptr){
        head = nullptr;
    }

}

//Copy Assignment Operator
LinkList &LinkList::operator=(const LinkList &copyList) {
    cout << "Copy Assignment Operator Called" << endl;

}

//Add an item to the list
void LinkList::append(int item) {
    // case 1: Adding to an empty list
    if (head == nullptr) {
        head = new Node(item); //Update the head
    }
        // case 2: Adding to an existing list
    else {
        current = head; // Create a new node

        // Find end of the list
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(item); // Have last node point to the new node
    }
}

//Remove an item to the list
bool LinkList::remove(int item) {

    //Create two nodes
    current = head; //starting from the first node
    Node *previous; // Create new node to  to track where you have been


    // case 1: If the list is empty, do nothing
    if (head == nullptr) {
        return false;
    }

    // case 2: If the item is the first node, update the head
    if (head->value == item) {
        head = head->next; //Make head point to second node
        current->next = nullptr; // Disconnect the first node from the list
        delete current; //Delete the disconnected node

        return true;
    }

    // case 3: If the item is in the list but not the first node
    while (current) {
        if (current->value == item) {
            previous->next = current->next; //Make previous node point to the next node
            current->next = nullptr; //Disconnect the node (containing item) from the list
            delete current; // Delete the disconnected node
            return true;
        }
        //Move along the list
        previous = current;
        current = current->next;
    }

    // case 4: Else, if the item does not exist, do nothing
    return false;
}

//Determine if item is in the list
bool LinkList::isItem(int item) const {
    Node *cursor = head; // create a pointer to traverse the list for the constant function
    while (cursor != nullptr) { //while current is not the tail
        if (cursor->value == item) { //if the item is found, hooray
            return true;
        }
        cursor = cursor->next; //move to the next
    }
    return false; //else the item is not there
}

//Print the linked list
void LinkList::printList() const {
    Node *cursor = head; // create a pointer to traverse the list for the constant function
    if (!cursor) { //check if the list is empty
        cout << "The list is empty!" << endl;
    } else {
        while (cursor) {
            cout << cursor->value << endl; //output the node
            cursor = cursor->next; //move to the next
        }
    }
}


