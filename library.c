#include "library.h"

void loadBookList(Library* library)
{
    FILE* file = fopen("D:\\文件\\大学\\c\\5月9日\\新建文件夹\\BookList.txt", "r");
    if (file == NULL) {
        printf("无法打开图书文件。\n");
        return;
    }

    library->total_books = 0;
    while (fscanf(file, "%d %s %s %s %s %lf %s %d %d %d %d",
                  &(library->books[library->total_books].id),
                  library->books[library->total_books].name,
                  library->books[library->total_books].ISBN,
                  library->books[library->total_books].publisher,
                  library->books[library->total_books].author,
                  &(library->books[library->total_books].price),
                  library->books[library->total_books].location,
                  &(library->books[library->total_books].total),
                  &(library->books[library->total_books].borrowed),
                  &(library->books[library->total_books].available),
                  &(library->books[library->total_books].times_borrowed)) != EOF) {
        library->total_books++;
    }

    fclose(file);
}

void loadReaderList(Library* library)
{
    FILE* file = fopen("D:\\文件\\大学\\c\\5月9日\\新建文件夹\\readerList.txt", "r");
    if (file == NULL) {
        printf("无法打开读者文件。\n");
        return;
    }

    library->total_readers = 0;
    while (fscanf(file, "%s %s %d %d %s",
                  library->readers[library->total_readers].name,
                  library->readers[library->total_readers].id,
                  &(library->readers[library->total_readers].borrowed_books),
                  &(library->readers[library->total_readers].overdue_times),
                  library->readers[library->total_readers].recover_date) != EOF) {
        library->total_readers++;
    }

    fclose(file);
}

void saveBookList(Library* library)
{
    FILE* file = fopen("D:\\文件\\大学\\c\\5月9日\\新建文件夹\\BookList.txt", "w");
    if (file == NULL) {
        printf("无法打开图书文件。\n");
        return;
    }

    for (int i = 0; i < library->total_books; i++) {
        fprintf(file, "%d %s %s %s %s %.2lf %s %d %d %d %d\n",
                library->books[i].id,
                library->books[i].name,
                library->books[i].ISBN,
                library->books[i].publisher,
                library->books[i].author,
                library->books[i].price,
                library->books[i].location,
                library->books[i].total,
                library->books[i].borrowed,
                library->books[i].available,
                library->books[i].times_borrowed);
    }

    fclose(file);
}

void saveReaderList(Library* library)
{
    FILE* file = fopen("D:\\文件\\大学\\c\\5月9日\\新建文件夹\\readerList.txt", "w");
    if (file == NULL) {
        printf("无法打开读者文件。\n");
        return;
    }

    for (int i = 0; i < library->total_readers; i++) {
        fprintf(file, "%s %s %d %d %s\n",
                library->readers[i].name,
                library->readers[i].id,
                library->readers[i].borrowed_books,
                library->readers[i].overdue_times,
                library->readers[i].recover_date);
    }

    fclose(file);
}

void addBook(Library* library)
{
    printf("请输入图书信息：\n");
    scanf("%d %s %s %s %s %lf %s %d %d %d %d",
          &(library->books[library->total_books].id),
          library->books[library->total_books].name,
          library->books[library->total_books].ISBN,
          library->books[library->total_books].publisher,
          library->books[library->total_books].author,
          &(library->books[library->total_books].price),
          library->books[library->total_books].location,
          &(library->books[library->total_books].total),
          &(library->books[library->total_books].borrowed),
          &(library->books[library->total_books].available),
          &(library->books[library->total_books].times_borrowed));

    library->total_books++;
}

void updateBook(Library* library)
{
    int id;
    printf("请输入需要更新的图书ID：\n");
    scanf("%d", &id);

    for (int i = 0; i < library->total_books; i++) {
        if (library->books[i].id == id) {
            printf("请输入新的图书信息：\n");
            scanf("%d %s %s %s %s %lf %s %d %d %d %d",
                  &(library->books[i].id),
                  library->books[i].name,
                  library->books[i].ISBN,
                  library->books[i].publisher,
                  library->books[i].author,
                  &(library->books[i].price),
                  library->books[i].location,
                  &(library->books[i].total),
                  &(library->books[i].borrowed),
                  &(library->books[i].available),
                  &(library->books[i].times_borrowed));
            return;
        }
    }

    printf("找不到图书。\n");
}

void deleteBook(Library* library)
{
    int id;
    printf("请输入需要删除的图书ID：\n");
    scanf("%d", &id);

    for (int i = 0; i < library->total_books; i++) {
        if (library->books[i].id == id) {
            library->books[i] = library->books[library->total_books - 1];
            library->total_books--;
            return;
        }
    }

    printf("找不到图书。\n");
}

void addReader(Library* library)
{
    printf("请输入读者信息：\n");
    scanf("%s %s %d %d %s",
          library->readers[library->total_readers].name,
          library->readers[library->total_readers].id,
          &(library->readers[library->total_readers].borrowed_books),
          &(library->readers[library->total_readers].overdue_times),
          library->readers[library->total_readers].recover_date);

    library->total_readers++;
}

void updateReader(Library* library)
{
    char id[20];
    printf("请输入需要更新的读者ID：\n");
    scanf("%s", id);

    for (int i = 0; i < library->total_readers; i++) {
        if (strcmp(library->readers[i].id, id) == 0) {
            printf("请输入新的读者信息：\n");
            scanf("%s %s %d %d %s",
                  library->readers[i].name,
                  library->readers[i].id,
                  &(library->readers[i].borrowed_books),
                  &(library->readers[i].overdue_times),
                  library->readers[i].recover_date);
            return;
        }
    }

    printf("找不到读者。\n");
}

void deleteReader(Library* library)
{
    char id[20];
    printf("请输入需要删除的读者ID：\n");
    scanf("%s", id);

    for (int i = 0; i < library->total_readers; i++) {
        if (strcmp(library->readers[i].id, id) == 0) {
            library->readers[i] = library->readers[library->total_readers - 1];
            library->total_readers--;
            return;
        }
    }

    printf("找不到读者。\n");
}

void searchReader(Library* library)
{
    char id[20];
    printf("请输入需要搜索的读者ID：\n");
    scanf("%s", id);

    for (int i = 0; i < library->total_readers; i++) {
        if (strcmp(library->readers[i].id, id) == 0) {
            printf("姓名：%s\n身份证号：%s\n已借阅数量：%d\n连续逾期次数：%d\n借阅资格恢复时间：%s\n",
                   library->readers[i].name,
                   library->readers[i].id,
                   library->readers[i].borrowed_books,
                   library->readers[i].overdue_times,
                   library->readers[i].recover_date);
            return;
        }
    }

    printf("找不到读者。\n");
}

void searchBook(Library* library)
{
    int id;
    printf("请输入需要搜索的图书ID：\n");
    scanf("%d", &id);

    for (int i = 0; i < library->total_books; i++) {
        if (library->books[i].id == id) {
            printf("图书编号：%d\n名称：%s\nISBN号：%s\n出版社：%s\n作者：%s\n价格：%lf\n摆放位置：%s\n总数：%d\n借出数：%d\n余数：%d\n被借次数：%d\n",
                   library->books[i].id,
                   library->books[i].name,
                   library->books[i].ISBN,
                   library->books[i].publisher,
                   library->books[i].author,
                   library->books[i].price,
                   library->books[i].location,
                   library->books[i].total,
                   library->books[i].borrowed,
                   library->books[i].available,
                   library->books[i].times_borrowed);
            return;
        }
    }

    printf("找不到图书。\n");
}

void borrowBook(Library* library)
{
    char id[20];
    int book_id;

    printf("请输入读者ID和图书ID：\n");
    scanf("%s %d", id, &book_id);

    for (int i = 0; i < library->total_readers; i++) {
        if (strcmp(library->readers[i].id, id) == 0) {
            for (int j = 0; j < library->total_books; j++) {
                if (library->books[j].id == book_id) {
                    if (library->books[j].available > 0) {
                        library->books[j].available--;
                        library->books[j].borrowed++;
                        library->books[j].times_borrowed++;
                        library->readers[i].borrowed_books++;
                        printf("图书借阅成功。\n");
                        return;
                    } else {
                        printf("图书库存不足。\n");
                        return;
                    }
                }
            }
        }
    }

    printf("找不到读者或图书。\n");
}

void returnBook(Library* library)
{
    char id[20];
    int book_id;

    printf("请输入读者ID和图书ID：\n");
    scanf("%s %d", id, &book_id);

    for (int i = 0; i < library->total_readers; i++) {
        if (strcmp(library->readers[i].id, id) == 0) {
            for (int j = 0; j < library->total_books; j++) {
                if (library->books[j].id == book_id) {
                    if (library->books[j].borrowed > 0) {
                        library->books[j].available++;
                        library->books[j].borrowed--;
                        library->readers[i].borrowed_books--;
                        printf("图书归还成功。\n");
                        return;
                    } else {
                        printf("图书信息有误。\n");
                        return;
                    }
                }
            }
        }
    }

    printf("找不到读者或图书。\n");
}
