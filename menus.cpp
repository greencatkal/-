#include<iostream>
#include "hnulib.h"
using namespace std;
//哦，这是个敷衍的菜单（爬）
void menu::show_menu_main() //等等，你对这个主菜单的用法的构想是不是和我理解的不一样
{
    cout<<"你的身份是"<<'\n';
    cout<<"1.管理员"<<'\n';
    cout<<"2.学生"<<'\n';
    cout<<"0.退出图书馆信息管理系统"<<'\n';
    return ;
}