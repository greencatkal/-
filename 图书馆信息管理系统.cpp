#include<iostream>
#include"hnulib.h"

using namespace std;

menu show;

int main()
{ 
    while (true)
    {
        int i;

        int book_num,ad_num,us_num;

        books* book_head=loading_books(book_num);
        admin* admin_head=loading_admin(ad_num);
        user* user_head=loading_users(us_num,book_head);

        cout<<"欢迎使用图书馆信息管理系统！"<<'\n';
        i=show.show_menu_main();

    }
    

    system("pause");
    return 0;
}