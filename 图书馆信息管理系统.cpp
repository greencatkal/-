#include<iostream>
using namespace std;

void IdenTity(int n)
{

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