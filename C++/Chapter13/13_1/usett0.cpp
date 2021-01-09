#include <iostream>
#include "tabtenn0.h"

void Show(const TableTennisPlayer & rt)
{
    using std::cout;
    cout << "Name: ";
    rt.Name();  cout << "\n Table:" ; 
    if(rt.HasTable())
        cout << "yes\n";
    else
    {
        cout << "no\n";
    }
    
}

int main(void){
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("chuck", "Blizzard", false);
    // TableTennisPlayer player2("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    
    player1.Name();
    if(player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    
    // player2.Name();
    // if (player2.HasTable())
    // {
    //     cout << ": has a table.\n";
    // }else
    // {
    //     cout << ": hasn't a table.\n";
    // }
    rplayer1.Name();
    if (rplayer1.HasTable())
    {
        cout << ": has a table.\n";
    }else
    {
        cout << ": hasn't a table.\n";
    }
    cout << "Name: " ;
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating : " << rplayer2.Rating() << endl;


    cout << "派生类和基类之间的特殊关系:" << endl;
    TableTennisPlayer & rt = rplayer1;          // 基类引用指向派生类对象
    TableTennisPlayer * pt = &rplayer1;         // 基类指针指向派生类对象地址

    rt.Name();
    cout << endl;
    pt->Name();
    cout << endl;

    Show(player1);      // 基类
    Show(rplayer1);     // 派生类
    return 0;
}
