//
// Created by Ethan Harrison on 10/24/19.
//

#include "LinkedList.h"
#include <iostream>

using namespace std;

// The Big Three

//Constructor
LinkList::LinkList() {
    //cout << "Constructor Called" << endl;

    //Initialize list as empty
    head = nullptr;
}

//Destructor
LinkList::~LinkList() {
    //cout << "Destructor Called" << endl;
    Node *current; // create node for current position of the list

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
    //cout << "Copy Constructor Called" << endl;
    Node *current; // create node for current position of the list

    // case 1: if the list is empty
    if (list.head == nullptr) {
        head = nullptr;
    }
        // case 2: list contains items to copy
    else {
        head = new Node(list.head->value); //create new memory in the heap
        current = head; //start from the first node


        Node *currentList = current;  //Create new node to copy current

        //while current of the copied list has not reached the end
        while (currentList != nullptr) {
            current->next = new Node(currentList->next->value); //make deep copies
            currentList = currentList->next; // move to next in the copied list
            current = current->next; // move to next in the original list
        }
    }
}

//Copy Assignment Operator
LinkList &LinkList::operator=(const LinkList &copyList) {
    //cout << "Copy Assignment Operator Called" << endl;
    Node *current; // create node for current position of the list

    LinkList temp(copyList); //create new object

    //built-in swap for private member
    swap(temp.head, head);

    return *this;
}

//Add an item to the list
void LinkList::append(int item) {
    Node *current; // create node for current position of the list

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
    Node *current; // create node for current position of the list

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
            cout << cursor->value << "\t"; //output the node
            cursor = cursor->next; //move to the next
        }
    }
}

//Insertion Sort
void LinkList::LLinsertionSort() { //takes in head and along with it, the rest of the linked list

    Node *current; // create node for current position of the list
    Node *previous; // create node for previous position of the list
    Node *end; //create node to track end of sorted part of the list

    //case 1: Empty List- there is nothing to sort
    if (head == nullptr) {
        return;
    }

    //case 2: Linked List of one element is already sorted
    if (head->next == nullptr) {
        return;
    }

    //case 3: Linked List of multiple elements

    end = head->next; //list of one is sorted
    current = head->next; //starting from the first element beyond head
    previous = head; //previous is one before current



    while (end != nullptr) { //before the current reaches the end of the list
        while (head) {
            // create node to track the next element in list
            Node *next;
            next = current->next;

            if (current->value > next->value) { //compare two values next to each other
                current->next = next->next; //move currents pointer to one position over

                Node *temp; // create node to temporarily store data while you find correct location
                temp = next; // removing the out of place node from the list while saving its data

                next = current->next;


            } else {
                //move everything down the line in order
                previous = previous->next;
                current = current->next;
                next = next->next;
                end = end->next;
            }
        }
    }


    /*for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (previous->value > current->value) {
                swap(previous->value, current->value);
            }
            current = current->next;
        }
    }

    temp = head;
    while (temp){
        temp = temp->next;
        head->next = temp->next;
        temp->next = head;
    }*/


}

