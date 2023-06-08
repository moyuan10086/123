#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_ID_LEN 20
#define MAX_ISBN_LEN 15
#define MAX_PUBLISHER_LEN 50
#define MAX_AUTHOR_LEN 50
#define MAX_LOCATION_LEN 20
#define MAX_DATE_LEN 11
#define MAX_BOOKS 1000
#define MAX_READERS 1000

typedef struct Book {
    int id;
    char name[MAX_NAME_LEN];
    char ISBN[MAX_ISBN_LEN];
    char publisher[MAX_PUBLISHER_LEN];
    char author[MAX_AUTHOR_LEN];
    double price;
    char location[MAX_LOCATION_LEN];
    int total;
    int borrowed;
    int available;
    int times_borrowed;
} Book;

typedef struct Reader {
    char name[MAX_NAME_LEN];
    char id[MAX_ID_LEN];
    int borrowed_books;
    int overdue_times;
    char recover_date[MAX_DATE_LEN];
} Reader;

typedef struct Library {
    Book books[MAX_BOOKS];
    Reader readers[MAX_READERS];
    int total_books;
    int total_readers;
} Library;

void loadBookList(Library* library);
void loadReaderList(Library* library);
void saveBookList(Library* library);
void saveReaderList(Library* library);
void addBook(Library* library);
void updateBook(Library* library);
void deleteBook(Library* library);
void addReader(Library* library);
void updateReader(Library* library);
void deleteReader(Library* library);
void searchReader(Library* library);
void searchBook(Library* library);
void borrowBook(Library* library);
void returnBook(Library* library);
int checkBorrowStatus(Reader* reader);

#endif
