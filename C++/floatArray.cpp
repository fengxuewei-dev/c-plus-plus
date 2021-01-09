#include <iostream>
using namespace std;

void print(float *eular){
    eular[0] = 12;
    eular[1] = 21;
    eular[2] = 23;
}

int main(){
    float x[3];
    print(x);
    for(size_t i = 0; i < 3; i++)
        std::cout << x[i] << std::endl;
    return 0;
}