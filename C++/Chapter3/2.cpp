#include <iostream>
#define ZERO 0
#include <climits>     // 定义了一些常用的数据类型的使用限制宏

int main(void){
    using namespace std;

    short sam = SHRT_MAX;
    unsigned short sue = sam;

    sam = sam + 2; // 超过了 short 最大的定义数据范围, 跳转到 最大的负数，为其中进行增大某些数量
    sue = sue + 1;

    cout << "Sam has " << sam << " dollars and Sue has " << sue;
    cout << " dollars deposited.\nPoor Sam!" << SHRT_MIN;
    return 0;
}
