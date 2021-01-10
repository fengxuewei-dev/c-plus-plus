#ifndef BRASS_H_
#define BRASS_H_

#include <string>
using std::string;

/**
 * @brief Brass类，记录了普通银行用户的信息
 * 数据成员：姓名，账户额度，账户金额
 * 成员函数：构造函数，存款，取款、查看金额
*/
class Brass
{
    private:
        string fullName;
        long acctNum;
        double balance;
    public:
        Brass(const string & s = "NULLBody", const long an = -1, const double bl = 0.0);
        void Deposit(double amt);   // 存款
        double Balance() const;

        virtual void WithDraw(double amt);  // 取钱
        virtual void ViewAcct() const;      // 查看
        virtual ~Brass() {}                 // 虚析构函数；确保释放派生类对象的时候，正确顺序执行析构函数
};
/**
 * @brief BrassPlus 超级用户
 * 用户可以透支额度，且具有一定的上线。同时银行工作人员可以重新设置相关的透支额度和利率
 * 类中声明了 ViewAcct() 和 WithDraw() 函数，但是执行动作和 Brass 中是不一样的
*/

class BrassPlus : public Brass
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const string & s = "NULLBody", const long an = -1, const double bl = 0.0,const double ml = 500, const double r = 0.111125);
        BrassPlus(const Brass & ba, double ml = 500, double r = 0.111125);

        virtual void ViewAcct() const;          // 定义和基类相同的成员函数，使用 virtual，保证后期可以灵活访问基类或者派生类的函数体
        virtual void WithDraw(double amt);

        // 重设数据值
        void ResetMax(double m) {maxLoan = m; }
        void ResetRate(double r) {rate = r;}
        void ResetOwes() { owesBank = 0; }
};

#endif
