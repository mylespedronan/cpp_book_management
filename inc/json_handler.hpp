#ifndef _JSON_HANDLER_HPP_
#define _JSON_HANDLER_HPP_

#include <iostream>
#include <iomanip>
#include <fstream>
#include "json.hpp"

class BooksJSON{
  public:
    BooksJSON(){};

    // Book Info
    nlohmann::json readBookJSON();
    void updateBookJSON(nlohmann::json bookInfo);
};

class UsersJSON{
  public:
    UsersJSON(){};
    
    // User Info
    nlohmann::json readUsersJSON();
    void updateUserJSON(nlohmann::json userInfo);
};

#endif // _JSON_HANDLER_HPP_
