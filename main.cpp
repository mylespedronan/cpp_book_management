#include <iostream>
#include "inc/menu.hpp"
#include "inc/json.hpp"
#include "inc/json_handler.hpp"
#include "inc/books.hpp"

using json = nlohmann::json;

Menu menu;
BooksJSON booksJSON;
Books books;

// void removeBook();

// void listBooks();

// void rentBook();

// void returnBook();


int main(){
  int choice, bookID;

  choice = menu.bookMenu();
  
  switch(choice){
    case 1:
      std::cout << "------------\t Add a Book\t------------" << "\n" << std::endl;
      books.addBook();
      break;
    case 2:
      std::cout << "Which book ID would you like to update: ";
      std::cin >> bookID;

      if(std::cin.fail()){
        std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      } 

      books.updateBook(bookID);

      break;
    case 3:
      std::cout << "Which book ID would you like to delete: ";
      std::cin >> bookID;

      if(std::cin.fail()){
        std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      } 

      books.deleteBook(bookID);
      break;
    case 4:
      std::cout << "------------\t All Book Info\t------------" << "\n" << std::endl;
      books.listAllBooks();
      break;
    case 5:
      std::cout << "Which book ID would you like to list: ";
      std::cin >> bookID;

      if(std::cin.fail()){
        std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      } 

      std::cout << std::endl;
      std::cout << "------------\tBook Info\t------------" << "\n" << std::endl;

      books.listBook(bookID);
      break;
    case 6:
      std::cout << "Which book ID would you like to rent: ";
      std::cin >> bookID;

      if(std::cin.fail()){
        std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      } 

      std::cout << std::endl;    

      books.rentBook(bookID);
      break;
    case 7:
      std::cout << "Which book ID would you like to return: ";
      std::cin >> bookID;

      if(std::cin.fail()){
        std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      } 

      std::cout << std::endl;    

      books.returnBook(bookID);
      break;
    case 8:
      break;
    case 9:
      std::cout << "Exiting Program.\n" << std::endl;
      exit(EXIT_SUCCESS);
      break;
    default:
      std::cout << "Invalid choice. Please try again." << "\n" << std::endl;
      break;
  }

  main();  
}