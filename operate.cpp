#include<iostream>
#include "hnulib.h"
using namespace std;
menu show;
admin _ad;
user _us;

void operate::_admin_op()
{
    int num;
    cin>>num;
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