#include "inc/books.hpp"

using json = nlohmann::json;

void Books::addBook(){
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

void Books::updateBook(int bookID){
  json books;
  int bookCount, updateOption, choice, pub;
  bool isFound, con, avail;
  std::string title, author;

  isFound = false;

  try {
    books = booksJSON.readBookJSON();
    bookCount = books.size();
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    return;
  }
  
  if(bookID < bookCount){
    for(int i = 0; i < bookCount; i++){
      if(books[i]["bookID"] == bookID){
        updateOption = menu.updateBookMenu();
        
        switch(updateOption){
          case 0:
            std::cout << "Invalid option chosen. Please try again.\n" << std::endl;
            break;
          case 1:
            // Subject
            std::cout << "What is the subject of the book [1: 'history', 2: 'science', 3: 'biography']: ";
            std::cin >> choice;
            if(std::cin.fail()){
              std::cin.clear();
              std::cin.ignore(10000, '\n');  
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              break;
            } else if (choice < 0 || choice > 3){
              std::cout << "No valid choice selected. Please try again.\n" << std::endl;
              break;
            }

            if(choice == 1){
              books[i]["subject"] = "history";
            } else if (choice == 2){
              books[i]["subject"] = "science";
            } else {
              books[i]["subject"] = "biography";
            }

            booksJSON.updateBookJSON(books);

            break;
          case 2:
            // Location
            std::cout << "Which library is the book in [1: 'SF', 2: 'SM', 3: 'SJ']: ";
            std::cin >> choice;
            if(std::cin.fail()){
              std::cin.clear();
              std::cin.ignore(10000, '\n');  
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              break;
            } else if (choice < 0 || choice > 3){
              std::cout << "No valid choice selected. Please try again.\n" << std::endl;
              break;
            }

            if(choice == 1){
              books[i]["location"] = "SF";
            } else if (choice == 2){
              books[i]["location"] = "SM";
            } else {
              books[i]["location"] = "SJ";
            }

            booksJSON.updateBookJSON(books);

            break;
          case 3:
            // Title
            std::cout << "What is the title of the book: ";
            std::getline(std::cin >> std::ws, title);
            if(std::cin.fail()){
              std::cin.clear();
              std::cin.ignore(10000, '\n');  
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              break;
            }
            
            books[i]["bookInfo"]["title"] = title;
            booksJSON.updateBookJSON(books);
            
            break;
          case 4:
            // Author
            std::cout << "Who is the author of the book: ";
            std::getline(std::cin >> std::ws, author);
            if(std::cin.fail()){
              std::cin.clear();
              std::cin.ignore(10000, '\n');  
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              break;
            }

            books[i]["bookInfo"]["author"] = author; 
            booksJSON.updateBookJSON(books);
            
            break;
          case 5:
            // Pub year
            std::cout << "What is the publication year: ";
            std::cin >> pub;
            if(std::cin.fail()){
              std::cin.clear();
              std::cin.ignore(10000, '\n');  
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              break;
            } else if (pub < 1000 || pub > 2025){
              std::cout << "Invalid year. Please try again.\n" << std::endl;
            }

            books[i]["bookInfo"]["pub"] = pub;                
            booksJSON.updateBookJSON(books);
            
            break;
          case 6:
            std::cout << "Is the book new [true] or used [false]: ";
            std::cin >> std::boolalpha >> con;
            if(std::cin.fail()){
              std::cin.clear();
              std::cin.ignore(10000, '\n');  
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              break;
            }
            
            books[i]["bookInfo"]["con"] = con;
            booksJSON.updateBookJSON(books);

            break;
          case 7:
            std::cout << "Is the book available [true] or rented [false]: ";
            std::cin >> std::boolalpha >> avail;
            if(std::cin.fail()){
              std::cin.clear();
              std::cin.ignore(10000, '\n');  
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              break;
            }
            
            books[i]["bookInfo"]["avail"] = avail;
            booksJSON.updateBookJSON(books);

            break;
          case 8:
            std::cout << "What is the type of the book [1: 'hardcover', 2: 'paperback', 3: 'pdf']: ";
            std::cin >> choice;

            if(std::cin.fail()){
              std::cin.clear();
              std::cin.ignore(10000, '\n');  
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              break;
            } else if (choice < 0 || choice > 3){
              std::cout << "No valid choice selected. Please try again.\n" << std::endl;
              break;
            }

            if(choice == 1){
              books[i]["bookInfo"]["type"] = "hardcover";
            } else if (choice == 2){
              books[i]["bookInfo"]["type"] = "paperback";
            } else {
              books[i]["bookInfo"]["type"] = "pdf";
            }

            booksJSON.updateBookJSON(books);

            break;
          case 9:
            int tempID;

            std::cout << "Enter a new Book ID : ";
            std::cin >> tempID;

            if(std::cin.fail()){
              std::cout << "Invalid input. Please try again.\n" << std::endl;
              std::cin.clear();
              std::cin.ignore(10000, '\n');
            } else {
              bookID = tempID;
            }

            std::cout << std::endl;
            break;
          case 10:
            return;
            break;
          default: 
            std::cout << "Input is out of range. Please try again.\n" << std::endl;
            break;
        }

        isFound = true;
      }
    }
  }

  if(!isFound){
    std::cout << "Error: Book ID not found.\n" << std::endl;

    return;
  }

  updateBook(bookID);
}

void Books::deleteBook(int bookID){
  int tempID, bookCount;
  json books;
  bool isFound;

  isFound = false;

  try {
    books = booksJSON.readBookJSON();
    bookCount = books.size();
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    return;
  }
  
  if(bookID > (bookCount - 1)){
    std::cout << "ERROR: Book ID is not listed. Please try again.\n" << std::endl;
    return;
  }

  for(int i = 0; i < bookCount; i++){
    if(isFound){
      books[i]["bookID"] = tempID;
      tempID++;
    } else if ((books[i]["bookID"] == bookID) && !isFound){
      isFound = true;
      tempID = bookID;
    }
  }

  books.erase(books.begin() + bookID);
  booksJSON.updateBookJSON(books);

  std::cout << "Book Deleted.\n" << std::endl;
}

void Books::listAllBooks(){
  json books;
  int bookCount;

  try {
    books = booksJSON.readBookJSON();
    bookCount = books.size();             
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    exit(EXIT_FAILURE);
  }  

  for(int i = 0; i < bookCount; i++){
    std::cout << "Book ID : " << books[i]["bookID"] << std::endl;
    std::cout << "\t- Title : " << books[i]["bookInfo"]["title"] << std::endl;
    std::cout << "\t- Author : " << books[i]["bookInfo"]["author"] << std::endl;
    std::cout << "\t\t- Subject : " << books[i]["subject"] << std::endl;
    std::cout << "\t\t- Publication Year : " << books[i]["bookInfo"]["pub"] << std::endl;
    std::cout << "\t\t- Condition : " << books[i]["bookInfo"]["con"] << std::endl;
    std::cout << "\t\t- Type : " << books[i]["bookInfo"]["type"] << std::endl;
    std::cout << "\t\t- Location : " << books[i]["location"] << std::endl;
    std::cout << "\t\t- Available : " << books[i]["bookInfo"]["avail"] << std::endl;
    std::cout << std::endl;
  }
}

void Books::listBook(int bookID){
  json books;
  int bookCount;
  bool isFound;

  isFound = false;

  try {
    books = booksJSON.readBookJSON();
    bookCount = books.size();             
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    exit(EXIT_FAILURE);
  }

  if(bookID < bookCount){
    for(int i = 0; i < bookCount; i++){
      if(books[i]["bookID"] == bookID){
        std::cout << "Book ID : " << books[i]["bookID"] << std::endl;
        std::cout << "\t- Title : " << books[i]["bookInfo"]["title"] << std::endl;
        std::cout << "\t- Author : " << books[i]["bookInfo"]["author"] << std::endl;
        std::cout << "\t\t- Subject : " << books[i]["subject"] << std::endl;
        std::cout << "\t\t- Publication Year : " << books[i]["bookInfo"]["pub"] << std::endl;
        std::cout << "\t\t- Condition : " << books[i]["bookInfo"]["con"] << std::endl;
        std::cout << "\t\t- Type : " << books[i]["bookInfo"]["type"] << std::endl;
        std::cout << "\t\t- Location : " << books[i]["location"] << std::endl;
        std::cout << "\t\t- Available : " << books[i]["bookInfo"]["avail"] << std::endl;
        std::cout << std::endl;

        isFound = true;
      }
    }
  }

  if(!isFound){
    std::cout << "Error: Book ID not found.\n" << std::endl;

    return;
  }

  std::cout << std::endl;
}

void Books::rentBook(int bookID){
  json books;
  int bookCount;
  bool isFound;

  isFound = false;

  try {
    books = booksJSON.readBookJSON();
    bookCount = books.size();             
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    exit(EXIT_FAILURE);
  }

  if(bookID < bookCount){
    if(books[bookID]["bookInfo"]["avail"] == false){
      std::cout << "Book is unavailable.\n" << std::endl;
    } else {
      books[bookID]["bookInfo"]["avail"] = false;
      
      booksJSON.updateBookJSON(books);
      std::cout << "Book rented.\n" << std::endl;
    }
    isFound = true;
  }

  if(!isFound){
    std::cout << "Error: Book ID not found.\n" << std::endl;

    return;
  }
}

void Books::returnBook(int bookID){
  json books;
  int bookCount;
  bool isFound;

  isFound = false;

  try {
    books = booksJSON.readBookJSON();
    bookCount = books.size();             
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    exit(EXIT_FAILURE);
  }

  if(bookID < bookCount){
    if(books[bookID]["bookInfo"]["avail"] == true){
      std::cout << "Book is already available.\n" << std::endl;
    } else {
      books[bookID]["bookInfo"]["avail"] = true;
      
      booksJSON.updateBookJSON(books);
      std::cout << "Book returned.\n" << std::endl;
    }

    isFound = true;
  }

  if(!isFound){
    std::cout << "Error: Book ID not found.\n" << std::endl;

    return;
  }
    
}
