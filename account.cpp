#include "inc/account.hpp"

using json = nlohmann::json;

void Account::accRegister(){
  json users, newUser;
  int userCount;
  std::string username, pw;
  
  try {
    users = usersJSON.readUsersJSON();
    userCount = users.size();             
  } catch (const char* msg){
    std::cerr << msg << "\n" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "Enter a username: ";
  std::cin >> username;
  
  if(std::cin.fail()){
    std::cout << "ERROR: Incorrect format for username" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::cout << "Enter a password: ";
  std::cin >> pw;
  
  if(std::cin.fail()){
    std::cout << "ERROR: Incorrect format for password" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }
  
  newUser["userID"] = userCount;
  newUser["userInfo"]["username"] = username;
  newUser["userInfo"]["password"] = pw;

  
  users += newUser;
  usersJSON.updateUserJSON(users);

  std::cout << "User successfully registered.\n" << std::endl;
}
