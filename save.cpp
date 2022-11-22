//此文件用于图书、管理员、用户链表更新后的保存文件函数，每次链表更新后都要保存；
#include "hnulib.h"
#include <iostream>
#include <fstream>
using namespace std;

void save_books(books *books_head){
    books *h=books_head->next;
    ofstream ofs;
    ofs.open("books.txt",ios::out);
    while(h!=NULL){
        ofs<<h->id<<" "<<h->isbn<<" "<<h->name<<" "<<h->author<<" "
        <<h->publishing<<" "<<h->published<<" "<<h->price<<" "<<h->pages
        <<" "<<h->description<<endl;
        h=h->next;
    }
    ofs.close();
}

void save_users(user *users_head){
    ofstream ofs;
    ofs.open("user.txt",ios::out);
    user *h=users_head->next;
    while(h!=NULL){
        ofs<<h->account_num<<" "<<h->key<<" "<<h->log_num;
        if(h->log_num==0){
            ofs<<endl;
            h=h->next;
        }
        else{
            for(int i=0;i<h->log_num;i++){
                ofs<<" "<<h->log[i];
            }
            ofs<<endl;
            h=h->next;
        }
    }
    ofs.close();
}

void save_admins(admin *admins_head){
    ofstream ofs;
    ofs.open("admin.txt",ios::out);
    admin *h=admins_head->next;
    while(h!=NULL){
        ofs<<h->account_num<<" "<<h->key<<endl;
        h=h->next;
    }
    ofs.close();
}