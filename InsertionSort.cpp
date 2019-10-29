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

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
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

    // FINISH ME
    LinkList List; //create new object
    Node *item; //create the item to insert into the list

    // print out unsorted linked list
    List.printList();
    // insertionSort
    List.LLinsertionSort(item);
    //print out sorted linked list
    List.printList();

}