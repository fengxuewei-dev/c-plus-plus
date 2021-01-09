#include <iostream>

using namespace std;

#define HELLO 23

int main(void *){

    std::cout << "static_cast<double>(HELLO): " << static_cast<double>(HELLO) << std::endl;

    double xxx = 2576.34;

    std::cout << "static_cast<double>(xxx): " << static_cast<double>(xxx) << " xxx: " << xxx << std::endl;
    std::cout << "int(xxx): " << int(xxx)  << " xxx: " << xxx << std::endl;
    return 0;
}