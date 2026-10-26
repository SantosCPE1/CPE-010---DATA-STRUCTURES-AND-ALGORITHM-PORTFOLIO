#include <iostream>
#include <cstdlib>   // for generating random integers
#include <ctime>     // for seeding rand()
#include <algorithm> // for std::sort
#include "node.h"
#include "searchAlgo.h"

const int max_size = 50;

int main() {
    srand(time(0));


    int dataset[max_size];
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
    }

    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    int toFind;
    std::cout << " \n\n============================\n";
    std::cout << "Linear Search Array:\n";
    std::cout << "what value you want to search? ";
    std::cin >> toFind;

    linearSearchArr(dataset, max_size, toFind);

    std::cout << "\nString\n";
    std::cout << "JIMLORD";

    Node<char>* name1 = new_node('J');
    Node<char>* name2 = new_node('I');
    Node<char>* name3 = new_node('M');
    Node<char>* name4 = new_node('L');
    Node<char>* name5 = new_node('O');
    Node<char>* name6 = new_node('R');
    Node<char>* name7 = new_node('D');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;

    std::cout << "\nLinear Search Linked list\n";
    std::cout << "Linear Search for Linked List result (D): ";
    linearSearchLL(name1, 'D');
    std::cout << "Linear Search for Linked List result (X): ";
    linearSearchLL(name1, 'X');

    
    std::cout << " \n\n============================";
    std::cout << " \nBinary Search\n";

    int sortedData[max_size];
    for (int i = 0; i < max_size; i++) {
        sortedData[i] = rand() % 100; 
    }

   
    std::sort(sortedData, sortedData + max_size);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < max_size; i++) {
        std::cout << sortedData[i] << " ";
    }
    std::cout << std::endl;

    int toFindSorted;
    std::cout << "what value you want to search for (binary search)? ";
    std::cin >> toFindSorted;

    binarySearchArr(sortedData, max_size, toFindSorted);

  
    Node<char>* n1 = new_node('D');
    Node<char>* n2 = new_node('I');
    Node<char>* n3 = new_node('J');
    Node<char>* n4 = new_node('L');
    Node<char>* n5 = new_node('M');
    Node<char>* n6 = new_node('O');
    Node<char>* n7 = new_node('R');

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    std::cout << "\nSorted Linked List: D I J L M O R\n";

    Node<char>* midNode = getMiddle(n1, n7);
    if (midNode != nullptr) {
        std::cout << "Middle element of full Linked List: " << midNode->data << std::endl;
    }

    std::cout << "\nBinary Search LL ('D'): ";
    Node<char>* resultFound = binarySearchLL(n1, 'D');
    if (resultFound != nullptr) {
        std::cout << "Search success\n";
    } else {
        std::cout << "Search failed.\n";
    }

    std::cout << "Binary Search LL ('X'): ";
    Node<char>* resultNotFound = binarySearchLL(n1, 'X');
    if (resultNotFound != nullptr) {
        std::cout << "Search success\n";
    } else {
        std::cout << "Search failed.\n";
    }

  
    Node<char>* current = name1;
    while (current != nullptr) {
        Node<char>* temp = current;
        current = current->next;
        delete temp;
    }

    current = n1;
    while (current != nullptr) {
        Node<char>* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}