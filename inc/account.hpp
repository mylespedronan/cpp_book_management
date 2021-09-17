#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <functional>
#include <string>
#include "json_handler.hpp"

class Account{
  private:
    UsersJSON usersJSON;
  public:
    Account(){};
    void accRegister();
    void accLogin(bool *isLoggedIn);
    void accLogout(bool *isLoggedIn);
};

#endif // _ACCOUNT_H_
