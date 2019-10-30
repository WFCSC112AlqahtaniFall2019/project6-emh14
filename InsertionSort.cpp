#include <iostream>
#include <vector>
#include <cassert>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main() {

    int seed, length;
    cout << "Insert seed and length: " << endl;
    cin >> seed >> length;
    cout << endl;
    srand(seed);

    vector<int> v(length);
    LinkList List; //create new object
    Node *item; //create the item to insert into the list


    // generate vector and linked list of random integers
    for (int i = 0; i < v.size(); i++) {
        int randValue = rand() % 100; //keep the random value the same for the vector and list
        v[i] = randValue;
        List.append(randValue);
    }

    // print out unsorted vector
    cout << "Unsorted Vector: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;

    // binary insertion sort
    insertionSort(v, v.size());

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }

    // print out sorted vector
    cout << "Sorted Vector: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;

    // print out unsorted linked list
    cout << "Unsorted Linked List: " << endl;
    List.printList();
    cout << endl;

    // insertionSort
    List.LLinsertionSort();

    //print out sorted linked list
    cout << "Sorted Linked List: " << endl;
    List.printList();

    //cout << "Here" << endl;

}