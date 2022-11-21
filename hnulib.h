# ifndef _HNULIB_H
# define _HUNLIB_H

#include <iostream>
#include <fstream>
using namespace std;

class books{    //图书信息
friend struct books* loading_books(int &num);
friend struct user* loading_users(int &num,books *head_books);
friend user;
friend admin;
friend menu;
public:
    bool borrow;    //该图书是否被借阅
    void lookup_name(string name,books *book_head);  //书名查找图书
    void lookup_isbn(string isbn,books *book_head);  //isbn查找图书
    void lookup_author(string author,books *book_head);  //作者查找图书
    void lookup_publishing(string publishing,books *book_head);  //出版社查找图书
    void book_list();   //图书借阅次数排行榜
    void author_list(); //作者借阅次数排行榜
    void new_publish(); //最新出版排行榜

protected:
    long int num;   //图书数目
    int id; //图书id
    string isbn;    //图书isdn，较长
    string name;   //图书名，有中文
    string author; //作者名
    string publishing; //出版社名字
    string published;   //出版日期
    double price;   //图书价格，含小数
    int pages;  //图书页数
    string description;    //图书描述
    struct books *next;

};

class user{ //读者（用户）
friend struct user* loading_users(int &num,books *head_books);
friend void reg_user(user *user_head);
friend admin;
friend menu;
public:
    user* login(user *user_head);   //登陆
    void change_key(user *user_head);  //更改密码
    void show_borrow(user *user_head); //查看借阅记录
    void b_r(user *user_head); //借阅或归还图书
protected:
    string account_num;   //账号
    string key;   //密码
    int log_num;    //借阅书的数目
    int log[20];    //借阅记录，最多借阅20本书
    user *next;

};

class admin{    //管理员
friend struct admin* loading_admin(int &num);
friend void reg_admin(admin *admin_head);
public:
    bool login();   //登陆
    void add_book();    //增加图书
    void del_book();    //删除图书
    void change_book();    //更改图书信息
    void reset_key();   //重置学生密码
protected:
    string account_num;
    string key;
    admin *next;

};

class menu{
    public:
    void show_menu_main();  //主目录
    void show_menu_admin(); //管理员目录
    void show_menu_user();  //使用者目录
};
class tourist{  //游客（待开发）


};
class operate{  //用户操作(待删除)(什么啊笑死)
    public:
    void _admin_op();
    void _user_op();
};

struct books* loading_books(int &num);
struct admin* loading_admin(int &num);
struct user* loading_users(int &num,books *head_books);
void reg_admin(admin *admin_head);

# endif