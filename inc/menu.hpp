#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <iostream>
#include <string>
#include "json.hpp"

class Menu{
  private:
    int choice;
  public:
    Menu(){};
    int bookMenu();
    nlohmann::json addBookMenu();
    int updateBookMenu();
};

#endif // _MENU_HPP_
