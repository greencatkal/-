#include<iostream>
#include "hnulib.h"
using namespace std;

user* user::login(user *user_head) //登陆
{
    long account;
    cin>>account;
    user *temp=user_head;
    while(temp->account_num)
    {
        if(temp->account_num==account)  //匹配账号
        {
            cout<<"请输入密码"<<'\n';
            long key;
            if(key==temp->key)  //"匹配密码"
            {
                cout<<"登陆成功"<<'\n';
                return temp;
            }
            else
            {
                cout<<"密码不正确，登陆失败"<<'\n';
                return NULL;
            }
        }

    }

    cout<<"账号不存在，请先注册或检查拼写是否正确"<<'\n';
    return NULL;

}
//问题来了，是每进行一次操作登陆一次，还是一直保持登陆状态？
//感觉实现前一个没那么麻烦(虽然用户用起来很麻烦)

void user::change_key(user *user_head)  //改密码
{
    user *temp=user::login(user_head);
    if(!temp)
    {
        return ;
    }
    else
    {
        long new_key1,new_key2;

        in_again:

        cout<<"请输入新密码："<<'\n';
        cin>>new_key1;
        cout<<"请再次输入新密码： "<<'\n';
        cin>>new_key2;
        //嗯嗯，模仿常规登陆情况
        if(new_key1==new_key2)
        {
            temp->key=new_key2;
            cout<<"修改成功！"<<'\n';
            return ;
        }
        else
        {
            cout<<"两次密码输入不一致，请重新输入"<<'\n';
            goto in_again;  //应该可以用while改(懒)
        }
    }
}

void user::show_borrow(user *user_head)
{
    user *temp=user::login(user_head);
    //好吧，这样让用户操作确实很麻烦(少女折寿中)
}