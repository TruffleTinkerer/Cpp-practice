#include <iostream>

struct Fraction {
    int numerator{};
    int denominator{1}
}

Fraction getFraction(){
    Fraction temp{};
    std::cout<<"Enter a value for the numerator: ";
    std::cin>>temp.numerator;
    std::cout<<"Enter a value for the denominator: ";
    std::cin>>temp.denominator;
    std::cout<<'\n';

    return temp;
}

Fraction multiply (const Fraction& f1, const Fraction& f2){
    return {f1.numerator*f2.numerator, f1.denominator*f2.denominator}
}

void printFraction(const Fraction& f){
    std::cout<<f.numerator<<'/'<<f.denominator<<'\n';
}

int main(){
    Fraction f1{getFraction()};
    Fraction f2{getFraction()};

    std::cout<<"Your fractions multiplied together: ";
    printFraction(multiply(f1,f2));
}