#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

void Have1(float * _value_){
    int b = 10;
    int *a = &b;

    std::cout << "*a : " << *a << std::endl;
    std::cout << "*_value_ : " << *_value_ << std::endl;
    
    *_value_ = *a;
}

int main(void *){
    float value = 0;
    Have1(&value);
    std::cout << "value : " << value << std::endl;
    return 0;
}