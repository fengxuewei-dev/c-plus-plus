#include <iostream>
#include <climits>

int main(void){
    using namespace std;
    int n_int = INT_MAX;        // 存储最大的数据
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;


    cout << "int is " << sizeof(int) << " byte" << endl;
    cout << "int is " << sizeof n_int << " byte" << endl;
    return 0;
}
