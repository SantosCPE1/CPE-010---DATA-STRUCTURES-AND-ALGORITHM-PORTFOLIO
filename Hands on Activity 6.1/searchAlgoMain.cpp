#include <iostream>
#include "node.h"
#include "searchAlgo.h"

//PROBLEM 1 & 2 ARRAY
int seqArray[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

int main(){
    //LL IMPLEMENTATION 
    Node<int>* seq1 = new_node(15);
    Node<int>* seq2 = new_node(18);
    Node<int>* seq3 = new_node(2);
    Node<int>* seq4 = new_node(19);
    Node<int>* seq5 = new_node(18);
    Node<int>* seq6 = new_node(0);
    Node<int>* seq7 = new_node(8);
    Node<int>* seq8 = new_node(14);
    Node<int>* seq9 = new_node(19);
    Node<int>* seq10 = new_node(14);

    seq1->next = seq2;
    seq2->next = seq3;
    seq3->next = seq4;
    seq4->next = seq5;
    seq5->next = seq6;
    seq6->next = seq7;
    seq7->next = seq8;
    seq8->next = seq9;
    seq9->next = seq10;

    //==================================
    //PROBLEM #1
    //==================================

    int comparisonArray = 0;
    int similarityArray = linearSearchArr(10, 18, seqArray, comparisonArray, false);

    int comparisonLL = 0;
    int similarityLL = LinearSearchLL(seq1, 18, comparisonLL, false);

    std::cout << "=============================" << std::endl;
    std::cout << "PROBLEM 1: SEQUENTIAL SEARCH" << std::endl;
    std::cout << "Searching for key 18" << std::endl;

    std::cout << "Array comparisons: "<< comparisonArray << std::endl;

    std::cout << "Linked list comparisons: "<< comparisonLL << std::endl;

    std::cout << "Answer: 2 comparisons are needed to find the first 18."<< std::endl;

    //==================================
    //PROBLEM #2
    //==================================

    int countComparisonArray = 0;
    int countComparisonLL = 0;

    //for array
    int similarsArray = linearSearchArr(10, 18, seqArray, comparisonArray, true);

    //for ll
    int similarsLL = LinearSearchLL(seq1, 18, comparisonLL, true);

    std::cout << "=============================" << std::endl;
    std::cout << "PROBLEM 2: COUNT OCCURRENCES"<< std::endl;

    std::cout << "Array occurrences of 18: "<< similarsArray << std::endl;

    std::cout << "Linked list occurrences of 18: "<< similarsLL << std::endl;

    std::cout << "Answer: 18 occurs 2 times."<< std::endl;

    //==================================
    //PROBLEM #3
    //==================================

    //array for 3 & 4
    int binaryArray[10] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    std::cout << "============================="<< std::endl;

    std::cout << "PROBLEM 3: ITERATIVE BINARY SEARCH"<< std::endl;

    std::cout << "Searching for key 8"<< std::endl;

    binarySearchArr(10, 8, binaryArray);

    //==================================
    //PROBLEM #4
    //==================================
    std::cout << "============================="<< std::endl;

    std::cout << "PROBLEM 4: RECURSIVE BINARY SEARCH"<< std::endl;

    std::cout << "Searching for key 8"<< std::endl;

    binarySearchArrRecursive(0, 9, 8, binaryArray);
    std::cout << "============================="<< std::endl;


    return 0;
}