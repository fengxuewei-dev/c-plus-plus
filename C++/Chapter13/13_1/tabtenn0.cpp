#include "tabtenn0.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(
    const string & fn,
    const string & ln,
    bool ht
):firstName(fn), lastName(ln), hasTable(ht) {}  // 使用初始化列表语法，直接使用 string 的复制构造函数将 firstName 初始化为 fn；使用函数体赋值语句需要执行两个步骤：1. 调用 string 的默认构造函数，2 调用 string 的赋值运算符将 fn 赋值给 firstname

void TableTennisPlayer::Name() const{
    std::cout << lastName << ", " << firstName;
}

// 如果 没有 : TableTennisPlayer() 使用 基类默认构造函数
// 既可以在类的声明中，也可以在函数定义中声明缺省参数，但不能既在类声明中又在函数定义中同时缺省参数
RatedPlayer::RatedPlayer(unsigned int r, const string & fn,  const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    rating = r;
}

// TableTennisPlayer(tp) 调用基类的复制构造函数
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r)
{
}