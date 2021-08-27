#include "inc/menu.hpp"

int Menu::bookMenu(){
  std::cout << "------------\t Welcome to the Book Rental System\t------------" << "\n" << std::endl;
  std::cout << "1. Add a book" << std::endl;
  std::cout << "2. Update a book" << std::endl;
  std::cout << "3. Remove a book" << std::endl;
  std::cout << "4. List all books" << std::endl;
  std::cout << "5. Check a book" << std::endl;
  std::cout << "6. Rent a book" << std::endl;
  std::cout << "7. Return a book" << std::endl;
  std::cout << "8. Login" << std::endl;
  std::cout << "\nYour choice: ";
  std::cin >> choice;

  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    choice = 0;
  }

  return choice;
}

