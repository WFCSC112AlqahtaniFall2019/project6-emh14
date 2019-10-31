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

    //for (int j = 0; j < 10000; j = j + 100) {

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
            assert(v[i - 1] <= v[i]);
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

        //cout << endl << endl;

        /*//measure vector sorting
        clock_t start_vectorSort = clock(); //start clock
        insertionSort(v, v.size()); // sort vector using Binary Insertion
        clock_t end_vectorSort = clock(); //end clock
        double elapsed_vectorSort =
                double(end_vectorSort - start_vectorSort) / CLOCKS_PER_SEC; //calculate seconds passed

        clock_t start_linkListSort = clock(); //start clock
        //sort vector using LLinsertionSort
        List.LLinsertionSort(); //measure linked list sorting
        clock_t end_linkListSort = clock(); //end clock
        double elapsed_linkListSort =
                double(end_linkListSort - start_linkListSort) / CLOCKS_PER_SEC; //calculate seconds passed

        cout << j << "\t" << elapsed_linkListSort << "\t" << elapsed_vectorSort << endl;*/
    }

//}