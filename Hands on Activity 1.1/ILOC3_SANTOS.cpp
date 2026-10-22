#include <iostream>
#include <cmath>

float distance (int a, int b, int c, int d);
int a, b, c, d;
int main() {
  
    std::cout << "Input 1st point: ";
    std::cin >> a >> b;
    std::cout << "Input 2nd point: ";
    std::cin >> c >> d;
    float dist = distance (a, b, c, d);
    std::cout << "THe distance between the two points is " << dist;
    
    return 0;
}
float distance (int a, int b, int c, int d){
    double First = pow((b - a),2);
    double Second = pow((d - c),2);
    return sqrt(First + Second);
}