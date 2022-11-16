#include<iostream>
#include"hnulib.h"

using namespace std;

menus show;

void IdenTity(int n)    //感觉没那么对，到时候用不了就删
{
   
    switch (n)
    {
    case 1:
        //怎么调用都很奇怪，给用户操作部分再来一个函数吧
        show.show_menu_admin();
        break;
    case 2:
        show.show_menu_user();
        break;
    default:
        cout<<"输入不规范"<<'\n';
        break;
    }
}

int main(){
    
    show.show_menu_main();
    
    int Choice;
    cin>>Choice;

    if(Choice==0)
    return 0;

    IdenTity(Choice);

    system("pause");
    return 0;
}