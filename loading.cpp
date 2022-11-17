#include "hnulib.h"
#include <fstream>
using namespace std;

//此文件编写每次程序开始时进行对图书、管理员、用户的数据处理函数，返回值为链表头结点
struct books* loading_books(int &num){
    ifstream ifs;
    ifs.open("books.txt",ios::in);
    num=0;
    cout<<"程序加载中(0%)。。。。。。"<<endl;
    char ch;
    ifs>>ch;
    books *head=new books;
    head->next=NULL;
    if(ifs.eof()){
        ifs.close();
    }
    
    else{
        ifs.close();    //重新打开文件；
        ifs.open("books.txt",ios::in); //此处及以下文件路径需要改动
        
        books *end=head;
        books *node=new books;
        head->next=node;
        while(ifs>>node->id&&ifs>>node->isbn&&ifs>>node->name&&ifs>>node->author&&ifs>>node->publishing&&ifs>>node->published&&ifs>>node->price&&ifs>>node->pages&&ifs>>node->description){
            node->borrow=false; //这是没写存数据部分是吗
            end->next=node;
            end=end->next;
            num++;
        }
        end->next=NULL;
        ifs.close();
    }
    system("cls");
    return head;
}

struct admin* loading_admin(int &num){
    ifstream ifs;
    ifs.open("admin.txt",ios::in);
    num=0;
    cout<<"程序加载中(25%)。。。。。。"<<endl;
    char ch;
    ifs>>ch;
    admin *head=new admin;
    head->next=NULL;
    if(ifs.eof()){
        ifs.close();
    }
    
    else{
        ifs.close();    //重新打开文件；
        ifs.open("books.txt",ios::in); //此处及以下文件路径需要改动
        
        admin *end=head;
        admin *node=new admin;
        head->next=node;
        while(ifs>>node->account_num&&ifs>>node->key){
            end->next=node;
            end=end->next;
            num++;
        }
        end->next=NULL;
        ifs.close();
    }
    system("cls");
    return head;
}