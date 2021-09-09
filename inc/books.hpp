#ifndef _BOOKS_HPP_
#define _BOOKS_HPP_

#include <iostream>
#include <sstream>
#include "json.hpp"
#include "json_handler.hpp"
#include "menu.hpp"

class Books{
  private:
    BooksJSON booksJSON;
    Menu menu;
  public:
    Books(){};
    void addBook();
    void updateBook(int bookID);
    void deleteBook(int bookID);
    void listAllBooks();
    void listBook(int bookID);
    void rentBook(int bookID);
    void returnBook(int bookID);
};

#endif // _BOOKS_HPP_;