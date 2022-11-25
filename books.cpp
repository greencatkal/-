//本文件实现对图书的查找、排序

#include<iostream>
#include "hnulib.h"
using namespace std;

books* books::lookup_name(string name,books *book_head)   //书名精确查找
{
    books *temp=book_head;
    while(temp->next)
    {
        if(temp->name==name)
        {
            cout<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<temp->description<<'\n';
            cout<<"借阅情况： ";
            if(temp->borrow)
            cout<<"本书已被借阅"<<'\n';
            else
            cout<<"本书可借阅"<<'\n';

            return temp;
        }
        else
        temp=temp->next;
    }
    cout<<"未查找到相关书籍，请检查输入是否正确或向管理员反应书籍缺失"<<'\n';
    return NULL;
}

books* books::lookup_isbn(string isbn,books *book_head)   //ISBN精确查找
{
    books *temp=book_head;
    while(temp->next)
    {
        if(temp->isbn==isbn)
        {
            cout<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<temp->description<<'\n';
            cout<<"借阅情况： ";
            if(temp->borrow)
            cout<<"本书已被借阅"<<'\n';
            else
            cout<<"本书可借阅"<<'\n';

            return temp;
        }
        else
        temp=temp->next;
    }
    cout<<"未查找到相关书籍，请检查输入是否正确或向管理员反应书籍缺失"<<'\n';
    return NULL;
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
            cout<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<temp->description<<'\n';
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
    return ;
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
            cout<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<temp->description<<'\n';
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

books* books::dictionary_list(books* books_head){
    books *tmp_head=new books;  //深拷贝一份链表
    books *tmp_end=tmp_head;
    books *node=new books;
    books *tmp=books_head->next;
    while(tmp!=NULL){
        node->id=tmp->id;
        node->isbn=tmp->isbn;
        node->name=tmp->name;
        node->author=tmp->author;
        node->publishing=tmp->publishing;
        node->published=tmp->published;
        node->price=tmp->price;
        node->pages=tmp->pages;
        node->description=tmp->description;
        node->b_num=tmp->b_num;
        node->borrow=tmp->borrow;
        tmp=tmp->next;
        tmp_end=node;
        tmp_end->next=node;
        tmp_end=tmp_end->next;
        books *node=new books;
    }
    delete node;
    tmp_end->next=NULL;
    int i,count=0,num;
    books *p,*q,*last;
    p=tmp_head->next;
    while(p->next!=NULL){
        count++;
        p=p->next;
    }
    for(i=0;i<count-1;i++){
        p=tmp_head->next;
        q=p->next;
        last=tmp_head;
        for(num=0;num<count-i-1;num++){
            if(p->name.compare(q->name)==1){    //链表交换
                last->next=q;
                p->next=q->next;
                q->next=p;
            }
            last=last->next;
            p=last->next;
            q=p->next;
        }
    }
    return tmp_head;

}