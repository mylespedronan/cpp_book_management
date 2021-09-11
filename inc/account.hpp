#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include "json_handler.hpp"

class Account{
  private:
    UsersJSON usersJSON;
  public:
    Account(){};
    void accRegister();
};

#endif // _ACCOUNT_H_
