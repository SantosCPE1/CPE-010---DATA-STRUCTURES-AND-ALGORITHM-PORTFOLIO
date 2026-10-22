#include <iostream>

char choice;
float Kelv, Fahr;
float KelvtoFahr (float Kelv, float Fahr);

int main() {
    
    std::cout << "Welcome to temperature calculator \n";
    std::cout << "----------------------------------\n";
    std::cout << "Kelvin -> Fahrenheit [F]\n";
    std::cout << "Fahrenheit -> Kelvin [K] \n";
    std::cout << "Enter option: ";
    std::cin >> choice;
    
    if (choice == 'F'|| choice == 'f' ) {
        std::cout << "----------------------------------\n";
        std::cout << "Chosen Kelvin -> Fahrenheit \n";
        std::cout << "Enter Temperature in Kelvin: ";
        std::cin >> Kelv;
        float sum = KelvtoFahr (Kelv, Fahr);
        
    } else if (choice == 'F'|| choice == 'f' ) {
        std::cout << "----------------------------------\n";
        std::cout << "Chosen Fahrenheit -> Kelvin \n";
        std::cout << "Enter Temperature in Fahrenheit: ";
        std::cin >> Fahr;
    } else { 
        std::cout << "Error";
    }

    return 0;
}

float KelvtoFahr (float Kelv, float Fahr){ 
    Fahr = Kelv - 273.15; 
    std::cout << Fahr;
    return Fahr;
    
}

float FahrtoKelv (float Kelv, float Fahr){ 
    Kelv = Fahr + 273.15; 
    std::cout << Kelv;
    return Kelv;
    
}