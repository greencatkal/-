# ifndef _HNULIB_H
# define _HUNLIB_H

#include <iostream>
using namespace std;

class books{    //图书信息
friend user;
friend admin;
public:
    bool borrow;    //该图书是否被借阅
    void lookup_name(wstring name);  //书名查找图书
    void lookup_isbn(string isbn);  //isbn查找图书
    void lookup_author(wstring author);  //作者查找图书
    void lookup_publishing(wstring publishing);  //出版社查找图书
    void book_list();   //图书借阅次数排行榜
    void author_list(); //作者借阅次数排行榜
    void new_publish(); //最新出版排行榜

protected:
    int id; //图书id
    string isbn;    //图书isdn，较长
    wstring name;   //图书名，有中文
    wstring author; //作者名
    wstring publishing; //出版社名字
    string published;   //出版日期
    double price;   //图书价格，含小数
    int pages;  //图书页数
    wstring description;    //图书描述

};

class user{ //读者（用户）
friend admin;
public:
    void change_key();  //更改密码
    void show_borrow(); //查看借阅记录
    void b_r(); //借阅或归还图书
protected:
    long int account_num;   //账号
    long int key;   //密码
    int log[20];    //借阅记录，最多借阅20本书

};

class admin{    //管理员

public:
    void add_book();    //增加图书
    void del_book();    //删除图书
    void change_book();    //更改图书信息

protected:
    long int account_num;
    long int key;

};

class menus{
public:
    void show_menu_main();  //主目录
    void show_menu_admin(); //管理员目录
    void show_menu_user();  //使用者目录
};
class tourist{  //游客（待开发）

};

# endif