#include<iostream>
#include"hnulib.h"

using namespace std;

operate _op;
menu show;

void IdenTity(int &n)    //感觉没那么对，到时候用不了就删
{
    switch (n)
    {
    case 1:
    _op._admin_op();
        break;
    case 2:
    _op._user_op();
        break;
    default:
        break;
    }
}

int main()
{ 
    show.show_menu_main();
    
    int Choice;
    cin>>Choice;

    if(Choice==0)
    return 0;

    IdenTity(Choice);

    system("pause");
    return 0;
}