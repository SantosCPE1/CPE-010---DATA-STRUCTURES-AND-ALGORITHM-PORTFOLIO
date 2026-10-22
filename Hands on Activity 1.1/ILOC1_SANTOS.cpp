#include <iostream>
int temp, tempo;
int a, b;   
int main (){
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter Second number: ";
    std::cin >> b;
    std::cout << "Swapping the numbers....\n";

    temp = a;
    tempo = b;
    a = tempo;
    b = temp;
    
    std::cout << a << " swapped " << b;
    
    return 0;
}
