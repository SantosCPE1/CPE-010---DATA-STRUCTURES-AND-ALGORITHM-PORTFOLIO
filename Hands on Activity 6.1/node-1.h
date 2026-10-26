#ifndef NODE_H
#define NODE_H
#include <iostream> //we change LinearSearchLL from "void" to "int"...

template <typename T>
class Node{
public:
    T data;
    Node *next;
};

//node creation
template <typename T>
Node <T>* new_node(T newData){
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

//EDITED FOR PROBLEM 1 & 2
template <typename T>
int LinearSearchLL(Node<T>* head, T dataFind, int &what, bool countAll = true){
    int howMany = 0; what = 0;
    
    
    while (head != nullptr){
        what++; //PROBLEM 1 = Counts how many times the target is found
        if (head->data == dataFind){
            howMany++;
            //PROBLEM 2 = Identify # of comparisons to find 18
            if (!countAll){
                return howMany;
            }
        }
        head = head->next; //MOVEMENT
    }
    return howMany;
}
#endif