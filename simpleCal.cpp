#include <iostream>

int main() {
    // Write C++ code here
    float a,b;
    char x;
    std::cout << "Enter First Operand: ";
    std::cin >> a;
    std::cout << "Enter An Operator(such as +,-,*,/): ";
    std::cin >> x;
    std::cout << "Enter Second Operand: ";
    std::cin >> b;
    switch(x){
        case '+': // Addition
            std::cout<<"Result: "<<a+b;
            break;
        case '-': // Subtraction
            std::cout<<"Result: "<<a-b;
            break; 
        case '*': // Multiplication
            std::cout<<"Result: "<<a*b;
            break; 
        case '/': // Division
            std::cout<<"Result: "<<a/b;
            break;
        case '%': // Modulo
            std::cout<<"Result: "<<int(a)%int(b);
            break;
    }
    return 0;
}