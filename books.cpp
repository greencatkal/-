#include<iostream>
#include "hnulib.h"
using namespace std;

void books::lookup_name(string name,books *book_head)   //书名精确查找
{
    books *temp=book_head;
    while(temp->next)
    {
        if(temp->name==name)
        {
            cout<<temp->id<<" "<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<temp->description<<'\n';
            cout<<"借阅情况： ";
            if(temp->borrow)
            cout<<"本书已被借阅"<<'\n';
            else
            cout<<"本书可借阅"<<'\n';

            return;
        }
        else
        temp=temp->next;
    }
    cout<<"未查找到相关书籍，请检查输入是否正确或向管理员反应书籍缺失"<<'\n';
    return ;
}

void books::lookup_isbn(string isbn,books *book_head)   //ISBN精确查找
{
    books *temp=book_head;
    while(temp->next)
    {
        if(temp->isbn==isbn)
        {
            cout<<temp->id<<" "<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<temp->description<<'\n';
            cout<<"借阅情况： ";
            if(temp->borrow)
            cout<<"本书已被借阅"<<'\n';
            else
            cout<<"本书可借阅"<<'\n';

            return;
        }
        else
        temp=temp->next;
    }
    cout<<"未查找到相关书籍，请检查输入是否正确或向管理员反应书籍缺失"<<'\n';
    return ;
}
//接下来应该是两个模糊查找
void books::lookup_author(string author,books *book_head)
{
    books *temp=book_head;
    bool finding=false;
    while(temp->next)
    {
        if(temp->author==author)
        {
            finding=true;
            cout<<temp->id<<" "<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<temp->description<<'\n';
            cout<<"借阅情况： ";
            if(temp->borrow)
            cout<<"本书已被借阅"<<'\n';
            else
            cout<<"本书可借阅"<<'\n';
        }
        else
        temp=temp->next;
    }
    if(!finding)
    cout<<"未查找到相关书籍，请检查输入是否正确或向管理员反应书籍缺失"<<'\n';
    return;
}

void books::lookup_publishing(string publishing,books *book_head)
{
    books *temp=book_head;
    bool finding=false;
    while(temp->next)
    {
        if(temp->publishing==publishing)
        {
            finding=true;
            cout<<temp->id<<" "<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<temp->description<<'\n';
            cout<<"借阅情况： ";
            if(temp->borrow)
            cout<<"本书已被借阅"<<'\n';
            else
            cout<<"本书可借阅"<<'\n';
        }
        else
        temp=temp->next;
    }
    if(!finding)
    cout<<"未查找到相关书籍，请检查输入是否正确或向管理员反应书籍缺失"<<'\n';
    return;
}