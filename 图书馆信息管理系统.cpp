#include<iostream>
#include"hnulib.h"

using namespace std;

int main()
{ 
    
    menu show;
    user us_now;
    admin ad_now;
    books bo_now;

    int book_num,ad_num,us_num;

    books* book_head=loading_books(book_num);
    admin* admin_head=loading_admin(ad_num);
    user* user_head=loading_users(us_num,book_head);

    while (true)
    {
        int i;

        cout<<"欢迎使用图书馆信息管理系统！"<<'\n';
        i=show.show_menu_main();
        switch (i)
        {
        case 0:
            return 0;
        case 1:
        menu_ag:
            i=show.show_menu_reg();
            switch (i)
            {
            case 0:
                break;
            case 1:
                reg_user(user_head);
                break;
            case 2:
                reg_admin(admin_head);
                break;            
            default:
                cout<<"没有对应选项，请检查输入"<<'\n';
                goto menu_ag;
            }
            break;
        case 2:
            i=show.show_menu_tourist();
            switch (i)
            {
            case 0:
                break;
            case 1:
            case 2:
                bo_now.book_list(book_head);
                break;
            case 3:
                bo_now.author_list(book_head);
                break;
            case 4:
                bo_now.new_publish(book_head);
                break;
            default:
                cout<<"没有对应选项，请检查输入"<<'\n';
                break;
            }
            break;
        case 3:
            i=show.show_menu_user();
            
            switch (i)
            {
            case 0:
                break;
            case 1:
            case 2:
                us_now.b_r(2,user_head,book_head);
                break;
            case 3:
                us_now.b_r(1,user_head,book_head);
                break;
            case 4:
                us_now.change_key(user_head);
                break;
            case 5:
                us_now.show_borrow(user_head,book_head);
                break;
            case 6:
                bo_now.book_list(book_head);
                break;
            case 7:
                bo_now.author_list(book_head);
                break;
            case 8:
                bo_now.new_publish(book_head);
                break;

            default:
                cout<<"没有对应选项，请检查输入"<<'\n';
                break;
            }
            break;
        case 4:
            i=show.show_menu_admin();
            switch (i)
            {
            case 0:
                break;
            case 1:
                ad_now.add_book(book_head);
                break;
            case 2:
                ad_now.del_book(book_head);
                break;
            case 3:
                ad_now.change_book(book_head);
                break;
            case 4:
                ad_now.reset_key(user_head);
                break;
            default:
                cout<<"没有对应选项，请检查输入"<<'\n';
                break;
            }
            break;
        default:
            cout<<"没有对应选项，请检查输入"<<'\n';
            break;
        }
    }
    

    system("pause");
    return 0;
}