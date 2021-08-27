#include <iostream>
#include "inc/menu.hpp"

Menu menu;

// void addBook();
// void updateBook();
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
      break;
    case 2:
      std::cout << "------------\t Update a Book\t------------" << "\n" << std::endl;
      std::cout << "Which book ID would you like to update: ";
      std::cin >> bookID;
      break;
    case 3:
      break;
    case 4:
      std::cout << "------------\t All Book Info\t------------" << "\n" << std::endl;
      break;
    case 5:
      std::cout << "------------\tBook Info\t------------" << "\n" << std::endl;
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    default:
      std::cout << "Invalid choice. Please try again." << "\n" << std::endl;
  }

  main();
  
}