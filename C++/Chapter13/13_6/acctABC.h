#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

/**
 * @brief AcctABC, 将 Brass 和 BrassPlus 两个类中共有属性进行提取，获取抽象基类
*/

class AcctABC
{
    private:
        std::string fullName;
        long acctNum;
        double balance;
    protected:
        struct Formatting
        {
            std::ios_base::fmtflags flag;
            std::streamsize pr;
        };
        const std::string & FullName() const {return fullName;}
        long AcctNum() const {return acctNum;}
        Formatting SetFormat() const;
        void Restore(Formatting & f) const;
    public:
        AcctABC(const std::string & s = "NullBody", const long an = -1, const double bl = 0.0);
        virtual ~AcctABC() {}
        void Deposit(double amt);       // 取钱
        double Balance() const {return balance;}

        virtual void WithDraw(double amt) = 0;
        virtual void ViewAcct() const = 0;
        
};

/**
 * @brief Brass 继承抽象基类，实现简单用户的访问
*/
class Brass : public AcctABC
{
    public:
        Brass(const std::string & s = "NullBody", const long an = -1, const double bal = 0.0) : AcctABC(s, an, bal) { }
        virtual ~Brass() {}

        // 将抽象基类中的纯虚函数设置为虚函数
        virtual void WithDraw(double amt);
        virtual void ViewAcct() const;
};

/**
 * @brief BrassPlus 继承抽象基类，实现用户的访问
*/
class BrassPlus : public AcctABC
{
    private:   
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const std::string & s = "NullBody", const long an = -1, const double bal = 0.0, const double ml = 500, const double r = 0.10) : AcctABC(s, an, bal), maxLoan(ml), rate(r) { owesBank = 0.0; }
        BrassPlus(const Brass & ba, const double ml = 500, const double r = 0.10);

        virtual void ViewAcct() const;
        virtual void WithDraw(double amt);

        void ResetMax(double m) {maxLoan = m;}
        void ResetRate(double r ){ rate = r; }
        void ResetOwes() {owesBank = 0.0;}
};

#endif
