#include "node.h"

#ifndef SEARCHALGO_H
#define SEARCHALGO_H

#include <iostream> 
#include "node.h"


template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){
    //Step 1: I := 0
    int i = 0;

    //Repeat while I <= n
    while( i < arrSize){
        if(dataFind == data[i]){
            std::cout<<"the search is success\n";
            return;
        }
        //increment  i to move to the next element
        i++;
    }
    std::cout<< "the element is not found \n";

    return;

}


template <typename T>
void linearSearchLL(Node<T>* node, T dataFind){
    //repeat the loop unting the current node is not null
    while(node != nullptr){

        // if item = current node's data then display searching is successful
        if(dataFind == node->data){
            std::cout<< "the search was a success\n";
            return;
        }

        //if not, move to the next node
        node = node->next;
    }

    //the searching reached nullptr, -> search is unsuccessful
    std::cout<<"the search was unsuccessful\n";
}

template <typename T>
void binarySearchArr(const T arr[], int n, const T& no) {
    // Step 1: low := 0, up = n - 1
    int low = 0;
    int up = n - 1;

    // Step 2: Repeat while low <= up
    while (low <= up) {
        int mid = (low + up) / 2;

        if (no == arr[mid]) {
            std::cout << "Search element is found!\n";
            return; // exit function
        }
        else if (no < arr[mid]) {
            up = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    // Step 3 & 4: Print not found and Exit
    std::cout << "Search element is not found\n";
}

template <typename T>
Node<T>* getMiddle(Node<T>* start , Node<T>* last){
    //use two pointers: 1. slow moves one node at a time, fast moves two at a time
    Node<T>* slow = start;
    Node<T>* fast = start;

    //get middle:
    while(fast != last && fast->next != last){
        //move slow (one step)
        slow = slow->next;
        //move sat (two steps)
        fast = fast->next->next;
    }

    //when fast reaches the end
    // slow poitns to the middle node
    return slow;
}

template <typename T>
Node<T>* binarySearchLL(Node<T>* head, T key) {
    // 1. Start node is set to head of the list and the last node is set to NULL.
    Node<T>* start = head;
    Node<T>* last = nullptr;

    do {
        // 2. Middle element is calculated using the two pointers approach discussed above.
        Node<T>* mid = getMiddle(start, last);

        // If list is empty or segment is invalid
        if (mid == nullptr) {
            return nullptr;
        }

        // 3. If the middle element is same as the key to be searched, we return it.
        if (mid->data == key) {
            return mid;
        }

        // 4. Else if middle element is greater than the key to be searched, we have to search is the
        // right side of the singly linked list. So, we set start pointer to the next of middle element.
        else if (mid->data < key) {
            start = mid->next;
        }

        // 5. Else if middle element is less than the key to be searched, we have to search is the left
        // side of the singly linked list. So, we set last pointer to the middle element.
        else {
            last = mid;
        }
    // 6. If the key is found or the entire linked list gets traversed, we break the loop.
    } while (last == nullptr || last != start);
    return nullptr; // Key not found
}
#endif