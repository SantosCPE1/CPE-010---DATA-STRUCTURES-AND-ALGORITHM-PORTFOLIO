#include <iostream>
#include <cmath> 
#include <string>

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
    
public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    bool validateTriangle() const; 
    // New required function declarations
    double area(double sideA, double sideB, double sideC);
    double perimeter(double sideA, double sideB, double sideC);
    std::string triangleType() const;
};

// Constructor
Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

// Setter
void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B; 
    angleC = C;
    totalAngle = A + B + C;
}

bool Triangle::validateTriangle() const {
    return (totalAngle == 180 && angleA > 0 && angleB > 0 && angleC > 0);
}

double Triangle::area(double sideA, double sideB, double sideC) {
    double s = (sideA + sideB + sideC) / 2.0; // Semi-perimeter
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangle::perimeter(double sideA, double sideB, double sideC) {
    return sideA + sideB + sideC;
}

std::string Triangle::triangleType() const {
    if (!validateTriangle()) {
        return "Invalid Triangle";
    }
    
    if (angleA == 90 || angleB == 90 || angleC == 90) {
        return "Right-angled (Others)";
    }

    else if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "Obtuse-angled";
    }
    else {
        return "Acute-angled";
    }
}

int main() {
    Triangle set1(40, 30, 110);
    
    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
        
        double a = 7.0;
        double b = 5.5;
        double c = 10.3;
        
        std::cout << "Perimeter: " << set1.perimeter(a, b, c) << "\n";
        std::cout << "Area: " << set1.area(a, b, c) << "\n";
        std::cout << "Classification: " << set1.triangleType() << "\n";
        
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }
    
    return 0;
}