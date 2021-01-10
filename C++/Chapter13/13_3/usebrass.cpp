#include "brass.h"

#include <iostream>

int main(void){
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);

    // 方法是使用 对象 调用的，没有使用虚方法
    Piggy.ViewAcct(); cout << endl;
    Hoggy.ViewAcct(); cout << endl;

    cout << "Depositing $1000 into the Hogg Account: \n";       Hoggy.Deposit(1000.00);
    cout << "New Balance： $ " << Hoggy.Balance() << endl;

    cout << "Withdrawing $4200 from the Pigg Account:\n";       Piggy.WithDraw(4200.00);
    cout << "Pigg account balance： $ " << Piggy.Balance() << endl;

    cout << "Withdrawing $4200 from the Hogg Account:\n";       Hoggy.WithDraw(4200.00);
    Hoggy.ViewAcct();

    return 0;
}