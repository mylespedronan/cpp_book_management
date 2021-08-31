#include "inc/menu.hpp"

using json = nlohmann::json;

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
  std::cout << "9. Exit program" << std::endl;
  std::cout << "\nYour choice: ";
  std::cin >> choice;
  std::cout << std::endl;

  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    choice = 0;
  }

  return choice;
}

json Menu::addBookMenu(){
  json newBook;
  std::string title, author;
  int pub;
  bool con;

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

  // Title
  std::cout << "What is the title of the book: ";
  std::cin >> title;
  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');  
    throw "Invalid input. Please try again.";
  }
  
  newBook["bookInfo"]["title"] = title;

  // Author
  std::cout << "Who is the author of the book: ";
  std::cin >> author;
  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');  
    throw "Invalid input. Please try again.";
  }

  newBook["bookInfo"]["author"] = author;

  // Pub year
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

  // Condition
  std::cout << "Is the book new [true] or used [false]: ";
  std::cin >> std::boolalpha >> con;
  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');  
    throw "Invalid input. Please try again.";
  }
  
  newBook["bookInfo"]["con"] = con;

  // Type
  std::cout << "What is the type of the book [1: 'hardcover', 2: 'paperback', 3: 'pdf']: ";
  std::cin >> choice;
  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');  
    throw "Invalid input. Please try again.";
  } else if (choice < 0 || choice > 3){
    throw "No valid choice selected. Please try again.";
  }

  if(choice == 1){
    newBook["bookInfo"]["type"] = "hardcover";
  } else if (choice == 2){
    newBook["bookInfo"]["type"] = "paperback";
  } else {
    newBook["bookInfo"]["type"] = "pdf";
  }

  std::cout << std::endl;
  return newBook;
}

int Menu::updateBookMenu(){
  std::cout << "1. Update subject" << std::endl;
  std::cout << "2. Update location" << std::endl;
  std::cout << "3. Update title" << std::endl;
  std::cout << "4. Update author" << std::endl;
  std::cout << "5. Update publication year" << std::endl;
  std::cout << "6. Update book condition" << std::endl;
  std::cout << "7. Update availability" << std::endl;
  std::cout << "8. Update book type" << std::endl;
  std::cout << "9. Return to previous menu" << std::endl;
  std::cout << std::endl;
  std::cout << "What would you like to update: ";
  std::cin >> choice;

  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    throw "Invalid option selected. Please try again.";
  }

  return choice;
}