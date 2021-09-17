#include <iostream>
#include "inc/menu.hpp"
#include "inc/json.hpp"
#include "inc/json_handler.hpp"
#include "inc/books.hpp"
#include "inc/account.hpp"

using json = nlohmann::json;

Menu menu;
BooksJSON booksJSON;
Books books;
Account acc;

bool isLoggedIn = false;

int main(){
  int choice, bookID;

  choice = menu.bookMenu();
  
  switch(choice){
    case 1:
      // Add a book
      if(isLoggedIn){
        std::cout << "------------\t Add a Book\t------------" << "\n" << std::endl;
        books.addBook();
      } else {
        std::cout << "Please Log In before adding a book!\n" << std::endl;
      }
      break;
    case 2:
      // Update a book
      if(isLoggedIn){
        std::cout << "Which book ID would you like to update: ";
        std::cin >> bookID;

        if(std::cin.fail()){
          std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
          std::cin.clear();
          std::cin.ignore(10000, '\n');
        } 

        books.updateBook(bookID);
      } else {
        std::cout << "Please Log In before updating a book!\n" << std::endl;
      }

      break;
    case 3:
      // Remove a book
      if(isLoggedIn){
        std::cout << "Which book ID would you like to delete: ";
        std::cin >> bookID;

        if(std::cin.fail()){
          std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
          std::cin.clear();
          std::cin.ignore(10000, '\n');
        } 

        books.deleteBook(bookID);
      } else {
        std::cout << "Please Log In before deleting a book!\n" << std::endl;
      }
      break;
    case 4:
      // List all books
      std::cout << "------------\t All Book Info\t------------" << "\n" << std::endl;
      books.listAllBooks();
      break;
    case 5:
      // Check a book
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
      // Rent a book
      if(isLoggedIn){  
        std::cout << "Which book ID would you like to rent: ";
        std::cin >> bookID;

        if(std::cin.fail()){
          std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
          std::cin.clear();
          std::cin.ignore(10000, '\n');
        } 

        std::cout << std::endl;    

        books.rentBook(bookID);
      } else {
        std::cout << "Please Log In before renting a book!\n" << std::endl;
      }
      break;
    case 7:
      // Return a book
      if(isLoggedIn){
        std::cout << "Which book ID would you like to return: ";
        std::cin >> bookID;

        if(std::cin.fail()){
          std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
          std::cin.clear();
          std::cin.ignore(10000, '\n');
        } 

        std::cout << std::endl;    
        books.returnBook(bookID);
      } else {
        std::cout << "Please Log In before returning a book!\n" << std::endl;
      }        
      break;
    case 8:
      // Register
      std::cout << "------------\t Register \t------------" << "\n" << std::endl;
      acc.accRegister();
      break;
    case 9:
      // Login
      std::cout << "------------\t Login \t------------" << "\n" << std::endl;
      acc.accLogin(&isLoggedIn);
      break;
    case 10:
      // Log Out
      acc.accLogout(&isLoggedIn);
      break;
    case 11:
      // Exit Program
      std::cout << "Exiting Program.\n" << std::endl;
      exit(EXIT_SUCCESS);
      break;
    default:
      std::cout << "Invalid choice. Please try again." << "\n" << std::endl;
      break;
  }

  main();  
}