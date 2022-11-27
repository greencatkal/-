#include<iostream>
#include "hnulib.h"
using namespace std;

user* user::login(user *user_head) //登陆
{
    cout<<"请输入账号：";
    string account;
    cin>>account;
    user *temp=user_head;
    while(temp->next)
    {
        if(temp->account_num==account)  //匹配账号
        {
            cout<<"请输入密码"<<'\n';
            string key;
            if(key==temp->key)  //"匹配密码"
            {
                cout<<"登录成功"<<'\n';
                return temp;
            }
            else
            {
                cout<<"密码不正确，登录失败"<<'\n';
                return NULL;
            }
        }
        else
        {
            temp=temp->next;
        }

    }

    cout<<"账号不存在，请先注册或检查拼写是否正确"<<'\n';
    return NULL;

}
//问题来了，是每进行一次操作登陆一次，还是一直保持登陆状态？
//感觉实现前一个没那么麻烦(虽然用户用起来很麻烦)
//等等，好像可以不用每次都登陆

void user::change_key(user *user_head)  //改密码
{
    cout<<"请先登录"<<'\n';
    user *temp=user::login(user_head);  //先登着
    if(!temp)
    {
        return ;
    }
    else
    {
        string new_key1,new_key2;

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
            save_users(user_head);
            return ;
        }
        else
        {
            cout<<"两次密码输入不一致，请重新输入"<<'\n';
            goto in_again;  //应该可以用while改(懒)
        }
    }
}

void user::show_borrow(user *user_head,books *book_head)
{
    cout<<"请先登录"<<'\n';
    user *temp=user::login(user_head);
    //好吧，这样让用户操作确实很麻烦(少女折寿中)
    cout<<"你借过"<<temp->log_num<<"本书"<<'\n';
    cout<<"分别是：";
    for(int i=0;i<log_num;i++)
    {
        books *t=book_head;
    while(t->next)
    {
        if(t->id==temp->log[i])
        {
            cout<<t->isbn<<" "<<t->name<<" "<<t->author<<" "<<t->publishing<<" "<<t->published<<" "<<t->price<<" "<<t->price<<"\n"<<t->description<<'\n';
        }
        else
        t=t->next;
    }
    } 
    return;
}

void user::b_r(int n,user *user_head,books* book_head)   //这个部分的编写跟目录结构有点关系，等目录出来大概是要改
{
    cout<<"请先登录"<<'\n';
    user *temp=user::login(user_head);
    books* tmp;
    
    int i;
    string isbn;
    string bo_name;
    books* book;
ag:
    cout<<"请查找图书 输入1-按ISBN查找图书 2-按书名查找图书 0-退出"<<'\n';
    switch (i)
    {
    case 1:
        book=tmp->lookup_isbn(isbn,book_head);
        break;
    case 2:
        book=tmp->lookup_name(bo_name,book_head);
    case 0:
        return ;
    default:
        cout<<"输入错误"<<endl;
        goto ag;
    }
    if(n==1)    //借书
    {
        if(book->borrow==false&&temp->log_num<=20)
        {
            book->borrow=true;
            book->b_num+=1;
            temp->log_num+=1;
            temp->log[log_num-1]=book->id;
            cout<<"借阅成功！"<<'\n';
            return;
        }
        else if(temp->log_num>20)
        {
            cout<<"借阅数量不得超过20本"<<'\n';
            return;
        }
        else
        {
            cout<<"本书已被借阅"<<'\n';
            return;
        }
    }
    if(n==2)
    {
        if(book->borrow==true)
        {
            book->borrow=true;
            cout<<"归还成功！"<<'\n';
            return;
        }
        else
        {
            cout<<"本书已归还"<<'\n';
            return;
        }
    }
    else
    cout<<"输入错误，请重新输入"<<'\n';
    return;
}