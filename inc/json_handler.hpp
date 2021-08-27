#ifndef _JSON_HANDLER_HPP_
#define _JSON_HANDLER_HPP_

#include <iostream>
#include <iomanip>
#include <fstream>
#include "json.hpp"

class BooksJSON{
  public:
    BooksJSON(){};

    nlohmann::json readBookJSON();
    void updateBookJSON(nlohmann::json bookInfo);
};

#endif // _JSON_HANDLER_HPP_
