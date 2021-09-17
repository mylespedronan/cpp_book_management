#include "inc/json_handler.hpp"

using json = nlohmann::json;

json BooksJSON::readBookJSON(){
  json book;

  std::ifstream bookJSON("json_files/books.json");

  if(!bookJSON.is_open()){
    throw "File unable to open! Program exiting.\n";
  }

  bookJSON >> book;
  bookJSON.close();

  return book;
}

void BooksJSON::updateBookJSON(json bookInfo){
  std::ofstream bookJSON("json_files/books.json");
  bookJSON << std::setw(4) << bookInfo << std::endl;
  bookJSON.close();
}

json UsersJSON::readUsersJSON(){
  json user;

  std::ifstream usersJSON("json_files/users.json");

  if(!usersJSON.is_open()){
    throw "File unable to open! Program exiting.\n";
  }

  usersJSON >> user;
  usersJSON.close();

  return user;
}

void UsersJSON::updateUserJSON(json userInfo){
  std::ofstream usersJSON("json_files/users.json");
  usersJSON << std::setw(4) << userInfo << std::endl;
  usersJSON.close();
}
