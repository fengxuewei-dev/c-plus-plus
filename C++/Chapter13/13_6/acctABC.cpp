#include "acctABC.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

AcctABC::AcctABC(const string & s, const long an, const double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt){
    if(amt < 0)
        cout << "所存金额小于0，存钱操作取消！" << endl;
    else
        balance += amt;
}

void AcctABC::WithDraw(double amt) 
{
    balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const
{
    Formatting f;

    // 这里设置的 cout 是全局形似，但是因为这个是源文件函数实现定义，所以在包含头文件的主程序中，cout 不被共享。
    // setf() 设置格式标志来控制输出形式
    // std::ios_base::fixed: 表示用正常计数法来显示浮点数
    // std::ios_base::floatfield: 表示小数点后面保留6位小数
    // 返回类型为： fmtflags 和 std::ios_base::fixed 是类型一致的
    f.flag = cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    
    // 设置小数点后的位数。
    f.pr = cout.precision(2);

    return f;
}

void AcctABC::Restore(Formatting & f) const
{
    cout.setf(f.flag, std::ios_base::floatfield);
    cout.precision(f.pr);
}


void Brass::WithDraw(double amt)
{
    if(amt < 0)
        cout << "所取金额必须是正数，取钱操作取消！" << std::endl;
    else if(amt <= Balance())
        AcctABC::WithDraw(amt);
    else
        cout << "取钱金额大于账户额度！取钱操作取消！" << std::endl;
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "用户名： " << FullName() << endl;
    cout << "账号： " << AcctNum() << endl;
    cout << "账户余额： " << Balance() << endl;

    Restore(f);
}

void BrassPlus::ViewAcct() const{
    Formatting f = SetFormat();

    cout << "用户名：" << FullName() << endl;

    cout << "账号：" << AcctNum() << endl;
    cout << "账户余额：" << Balance() << endl;
    cout << "贷款额度： "<< maxLoan << endl;
    cout << "所欠银行金额：　" << owesBank << endl;

    cout.precision(3);
    cout << "贷款利率："<< 100 * rate << endl;
    Restore(f);
} 

void BrassPlus::WithDraw(double amt)
{
    Formatting f = SetFormat();

    double bal = Balance();
    if(amt <= bal)
        AcctABC::WithDraw(amt);
    else if (amt <= bal + maxLoan - owesBank){
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "透支金额：　" << advance << endl;
        cout << "最终金额：　" << advance * rate << endl;
        
        Deposit(advance);   // 将透支额度先存到卡内，再执行取钱的操作
        AcctABC::WithDraw(amt);
    }
    else
        cout << "卡被限制消费，交易取消！" << endl;
    
    Restore(f);
}