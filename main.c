#include "library.h"
#include <stdio.h>

void showMainMenu()
{
    printf("========= 图书管理系统 =========\n");
    printf("1. 管理员登录\n");
    printf("2. 读者登录\n");
    printf("3. 退出系统\n");
    printf("请输入您的选择：");
}

void showAdminMenu()
{
    printf("========= 管理员菜单 =========\n");
    printf("1. 添加图书\n");
    printf("2. 更新图书信息\n");
    printf("3. 删除图书\n");
    printf("4. 管理读者\n");
    printf("5. 查询图书\n");
    printf("6. 返回主菜单\n");
    printf("请输入您的选择：");
}

void showReaderMenu()
{
    printf("========= 读者菜单 =========\n");
    printf("1. 查询图书\n");
    printf("2. 借阅图书\n");
    printf("3. 归还图书\n");
    printf("4. 返回主菜单\n");
    printf("请输入您的选择：");
}

void showmanageReader()
{
    printf("========= 管理读者菜单 =========\n");
    printf("1. 添加读者\n");
    printf("2. 更新读者\n");
    printf("3. 删除读者\n");
    printf("4. 搜索读者\n");
    printf("5. 返回主菜单\n");
    printf("请输入您的选择：");
}

// 实现管理员菜单处理函数
void handleAdminMenu(Library* library)
{
    int choice,choice_1;
    do
    {
        showAdminMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBook(library);
            break;
        case 2:
            updateBook(library);
            break;
        case 3:
            deleteBook(library);
            break;
        case 4:
            showmanageReader();
            scanf("%d", &choice_1);
                    switch (choice_1)
                    {
                        case 1:
                            addReader(library);
                            break;
                        case 2:
                            updateReader(library);
                            break;
                        case 3:
                            deleteReader(library);
                            break;
                        case 4:
                            searchReader(library);
                            break;
                        case 5:
                            printf("返回主菜单。\n");
                            break;
                        default:
                            printf("无效选择，请重新输入。\n");
                            break;
                    }
            break;
        case 5:
            //searchBook(Library * library, char *name);
            break;
        case 6:
            printf("返回主菜单。\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
            break;
        }
    } while (choice != 6);
}

// 实现读者菜单处理函数
void handleReaderMenu(Library* library)
{
    int choice;
    do
    {
        showReaderMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            searchBook(library);
            break;
        case 2:
            borrowBook(library);
            break;
        case 3:
            returnBook(library);
            break;
        case 4:
            printf("返回主菜单。\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
            break;
        }
    } while (choice != 4);
}

// 实现主函数
int main()
{
    Library library;

    // 加载读者和图书列表
    loadBookList(&library);
    loadReaderList(&library);

    int choice;
    do
    {
        showMainMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            handleAdminMenu(&library);
            break;
        case 2:
            handleReaderMenu(&library);
            break;
        case 3:
            printf("退出系统。\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
            break;
        }
    } while (choice != 3);

    // 保存读者和图书列表
    saveBookList(&library);
    saveReaderList(&library);

    return 0;
}
