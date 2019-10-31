/* Ethan Harrison
 * CSC 112
 * Project 6
 * Insertion Sort
 * */


#ifndef NODE_H
#define NODE_H

class Node {
public:
    // Node constructor
    Node(int v = 0, Node* n = nullptr) {
        value = v;
        next = n;
    }

    friend class LinkList;

private:

    int value;
    Node* next;

};

#endif //NODE_H
