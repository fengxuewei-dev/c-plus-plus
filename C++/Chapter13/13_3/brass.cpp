#include "brass.h"

#include <iostream>

using std::cout;
using std::endl;

// ios_base 是输入输出流的基类
// 格式控制信息的枚举类型　fmtflags ，　影响到
// 如何解释输入序列的格式、
// 如何生成输出序列的格式，
// 例如整数是16进制还是10进制表示，浮点数是科学计数法还是定点形式等；
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis; // 设置缓冲区的大小

format setFormat();
void restore(format f, precis p);

Brass::Brass(const string & s, const long an, double bal){
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if(amt < 0)
        cout << "Negative deposit not allowed; "<< "deposit is cancelled.\n";
    else
    {
        balance += amt;
    }
    
}
void Brass::WithDraw(double amt){
    format initialState = setFormat();

    precis prec = cout.precision(2);

    if(amt < 0)
        cout << "Withdrawal amount must be positive; withdrawal canceled.\n";
    else if (amt <= balance)
        balance -= amt;
    else
    {
        cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n" << "Withdrawal canceled!\n";
    }
    restore(initialState, prec);
}

double Brass::Balance() const
{
    return balance;
}
void Brass::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}


// 派生类
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : Brass(s, an, bal){
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r){
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();      // 派生类方法可以调用基类的公有方法，若派生类重写了该方法，则必须使用作用域解析运算符；反之，则可以不使用作用域解析运算符，因为在派生类中，没有重定义.
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owe to bank: " << owesBank << endl;
    cout.precision(3);
    cout << "Loan rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}
void BrassPlus::WithDraw(double amt)
{
    // 使用　格式化方法　setf 和 precision 将浮点数值的输出模式设置为定点，即包含了两位有效数字
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if(amt <= bal)
        Brass::WithDraw(amt);
    else if(amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);

        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::WithDraw(amt);
    }
    else
    {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    restore(initialState, prec);
}
// 设置定点表示法 并返回以前的标记设置
format setFormat(){
    return cout.setf(
        std::ios_base::fixed, 
        std::ios_base::floatfield
    );
}

void restore(format f, precis p){ // 重新设置了 格式和精度
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}