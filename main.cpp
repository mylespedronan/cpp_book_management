#include <iostream>
#include "inc/menu.hpp"
#include "inc/json.hpp"
#include "inc/json_handler.hpp"

using json = nlohmann::json;

Menu menu;
BooksJSON booksJSON;

void addBook(){
  json books, newBook;
  int bookCount;

  try {
    books = booksJSON.readBookJSON();
    bookCount = books.size();             
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    exit(EXIT_FAILURE);
  }

  try {
    newBook = menu.addBookMenu();
  } catch (const char* msg) {
    std::cerr << msg << "\n" << std::endl;
    newBook = menu.addBookMenu();
  }

  newBook["bookID"] = bookCount;
  newBook["bookInfo"]["avail"] = true;

  books += newBook;
  booksJSON.updateBookJSON(books);

  std::cout << "Book successfully added.\n" << std::endl;

}

void updateBook(int bookID){
  json books, newBook;
  int bookCount, updateOption, choice;
  bool isFound;
  std::string title, author;

  try {
    books = booksJSON.readBookJSON();
    bookCount = books.size();
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    // exit(EXIT_FAILURE);
    return;
  }

  try{
    updateOption = menu.updateBookMenu();
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    return;
  }

  switch(updateOption){
    case 1:
      // Subject
      std::cout << "What is the subject of the book [1: 'history', 2: 'science', 3: 'biography']: ";
      std::cin >> choice;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(10000, '\n');  
        throw "Invalid input. Please try again.";
      } else if (choice < 0 || choice > 3){
        throw "No valid choice selected. Please try again.";
      }

      if(choice == 1){
        newBook["subject"] = "history";
      } else if (choice == 2){
        newBook["subject"] = "science";
      } else {
        newBook["subject"] = "biography";
      }    

      break;
    case 2:
      // Location
      std::cout << "Which library is the book in [1: 'SF', 2: 'SM', 3: 'SJ']: ";
      std::cin >> choice;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(10000, '\n');  
        throw "Invalid input. Please try again.";
      } else if (choice < 0 || choice > 3){
        throw "No valid choice selected. Please try again.";
      }

      if(choice == 1){
        newBook["location"] = "SF";
      } else if (choice == 2){
        newBook["location"] = "SM";
      } else {
        newBook["location"] = "SJ";
      }

      break;
    case 3:
      // Title
      std::cout << "What is the title of the book: ";
      std::cin >> title;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(10000, '\n');  
        throw "Invalid input. Please try again.";
      }
      
      newBook["bookInfo"]["title"] = title;

      break;
    case 4:
      // Author
      std::cout << "Who is the author of the book: ";
      std::cin >> author;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(10000, '\n');  
        throw "Invalid input. Please try again.";
      }

      newBook["bookInfo"]["author"] = author; 
    case 5:
      // Pub year
      int pub;

      std::cout << "What is the publication year: ";
      std::cin >> pub;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(10000, '\n');  
        throw "Invalid input. Please try again.";
      } else if (pub < 1000 || pub > 2025){
        throw "Invalid year. Please try again.";
      }

      newBook["bookInfo"]["pub"] = pub;     
    default: 
      break;
  }

  updateBook(bookID);
}

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
      addBook();
      break;
    case 2:
      std::cout << "------------\t Update a Book\t------------" << "\n" << std::endl;
      std::cout << "Which book ID would you like to update: ";
      std::cin >> bookID;

      if(std::cin.fail()){
        std::cout << "Invalid option selected. Please try again." << "\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      } 

      updateBook(bookID);

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
    case 9:
      exit(EXIT_SUCCESS);
      break;
    default:
      std::cout << "Invalid choice. Please try again." << "\n" << std::endl;
      break;
  }

  main();  
}