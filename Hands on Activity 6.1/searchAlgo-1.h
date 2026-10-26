#include "node.h"

#ifndef SEARCHALGO_H
#define SEARCHALGO_H

#include <iostream> //no more "void" method data types
#include "node.h"

//ARRAY = SEQUENTIAL SEARCH
template <typename T>
int linearSearchArr(int arrSize,T dataFind ,T list[], int &what, bool countAll = true){
    int manyHow = 0; what = 0;
    //for loop
    for (int i = 0; i < arrSize; i++){
        what++;
        if (dataFind == list[i]){
            manyHow++;
            if(!countAll){
                return manyHow;
            }
        }
    }
    return manyHow;
}

//BINARY SEARCHING
//GET MIDDLE=-=-=-=-=-=-=-=-=-=
template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;
    
    while (fast != last && fast->next != last){
        //slow = 1 step
        slow = slow->next;

        //fast = 2 steps
        fast = fast->next->next;
    }
    return slow;
}
//=--=--=-=--=-=-=-=-=-=-=-=-=

//LINKED LIST = BINARY SEARCH
template <typename T>
bool binarySearchLL(Node<T>* start, T dataFind){
    //Set last to null, start to head
    Node<T>* last = nullptr;
    Node<T>* current = start;

    //usage of getMiddle
    while (start != last){
        Node<T>* mid = getMiddle(start, last);
        //if middle == dataFind
        if(mid->data == dataFind){
            std::cout<<"Search is successful!"<<std::endl;
            return true;
        //if mid > dataFind    
        }else if (mid->data > dataFind){
            last = mid;
        //if mid < dataFind
        }else if(mid->data < dataFind){
            start = mid->next;
        }
    }
    std::cout << "Searching is unsuccessful!" << std::endl;
    return false;
}

//ARRAY = BINARY SEARCH (ITERATIVE)
template <typename T>
bool binarySearchArr(int arrSize, T dataFind, T list[], bool showTimes = true){
    //define low high and mid
    int low = 0, up = arrSize-1, middle, iterations = 1;

    //while low is less than middle, high
    while (low <= up){
        //compute for mid
        middle = (int)(low+up)/2;
        if (showTimes){
            std::cout<<"Iteration #"<<iterations<<std::endl;
            std::cout<<"Low = "<<low<<std::endl;
            std::cout<<"Middle = "<<middle<<std::endl;
            std::cout<<"Up = "<<up<<std::endl;
            std::cout<<"Value = "<<list[middle]<<std::endl;
        }
        //if dataFind is middle->data, return
        if (dataFind == list[middle]){
            std::cout<<"Search is successful!\n";
            return true;
            //if dataFind < middle, new up
        }else if(dataFind < list[middle]){
            up = middle - 1;
            //else update low
        }else{
            low = middle +1;
        }
        iterations++;
    }
    std::cout<<"Search is unsuccessful!"<<std::endl;
    return false;   
}

//ARRAY = BINARY SEARCH (RECURSIVE)
template <typename T>
bool binarySearchArrRecursive(int low, int up, T dataFind, T list[], int iterations = 1){
    if (low > up){
        std::cout<<"Searching was unsuccessful!"<<std::endl;
        return false;
    }

    int middle = (low + up) / 2;
    
    std::cout<<"Iteration #"<<iterations<<std::endl;
    std::cout<<"Low = "<<low<<std::endl;
    std::cout<<"Middle = "<<middle<<std::endl;
    std::cout<<"Up = "<<up<<std::endl;
    std::cout<<"Value = "<<list[middle]<<std::endl;

    if (dataFind == list[middle]){
        std::cout<<"Search was successful!"<<std::endl;
        return true;
    }else if(dataFind < list[middle]){
        return binarySearchArrRecursive(low, middle - 1, dataFind, list, iterations + 1 );

    }else{
        return binarySearchArrRecursive(middle + 1, up, dataFind, list, iterations + 1);
    }
}
#endif