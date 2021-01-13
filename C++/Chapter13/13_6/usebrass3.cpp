#include "acctABC.h"

#include <iostream>

const int CLIENTS = 4;

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;

    AcctABC * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "输入用户名： ";            getline(cin, temp); // 从 cin 读取一行输入
        cout << "输入用户卡号： ";          cin >> tempnum;
        cout << "输入账户金额： ";          cin >> tempbal;
        cout << "输入用户类型(1: Brass 用户； 2：BrassPlus 用户)：";
        while(cin >> kind && (kind != '1' && kind != '2'))
            cout << "输入1或2！\n";
        if(kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "输入额度限制： ";      cin >> tmax;
            cout << "输入贷款利率： ";      cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }

    cout << endl;

    for(int i = 0; i < CLIENTS; i++)
    { // 多态性的体现
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];
    }
    cout << "Done.\n";

    return 0;
}