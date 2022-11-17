#include<iostream>//一个先放着估计要删的函数部分（）
#include "hnulib.h"
using namespace std;
menu show;  //调用了菜单
admin _ad;  //调用了管理员类
user _us;   //调用了用户类

void operate::_admin_op()
{
    int num;
    
    while (true)
    {
        show.show_menu_admin();
        switch (num)
        {
        case 1:
            _ad.add_book();
            break;
        case 2:
            _ad.change_book();
           break;
        case 3:
            _ad.del_book();
            break;
        case 4:
            _ad.reset_key();
        case 0:
            return ;
        default:
            cout<<"没有相应功能，请检查输入"<<'\n';
            break;
       }
    }
    
}

void operate::_user_op()//这么看，还缺了不少功能
{
    int num;
    
    while (true)
    {
        show.show_menu_user();
        switch (num)
        {
        case 1:
            _us.b_r();
            break;
        case 2:
            _us.change_key();
            break;
        case 3:
            _us.show_borrow();
            break;
        case 0:
            return ;
        default:
            cout<<"没有相应功能，请检查输入"<<'\n';
            break;
       }
    }
    
}