#include<iostream>
#include"hnulib.h"

using namespace std;

void IdenTity(int n)    //感觉没那么对，到时候用不了就删
{
    switch (n)
    {
    case 1:
        //怎么调用都很奇怪
        break;
    case 2:

        break;
    default:
        break;
    }
}

int main(){
    
    cout<<"你的身份是"<<'\n';
    cout<<"1.管理员"<<'\n';
    cout<<"2.学生"<<'\n';
    cout<<"0.退出图书馆信息管理系统"<<'\n';
    
    int Choice;
    cin>>Choice;

    if(Choice==0)
    return 0;

    IdenTity(Choice);

    system("pause");
    return 0;
}