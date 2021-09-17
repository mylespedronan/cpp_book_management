#include "inc/account.hpp"

using json = nlohmann::json;

void Account::accRegister(){
  json users, newUser;
  int userCount;
  std::string username, pw;
  std::size_t user_hash, pw_hash;

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
    return;
  }

  std::cout << "Enter a password: ";
  std::cin >> pw;
  
  if(std::cin.fail()){
    std::cout << "ERROR: Incorrect format for password" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return;
  }

  user_hash = std::hash<std::string>{}(username);
  pw_hash = std::hash<std::string>{}(pw);
  
  newUser["userID"] = userCount;
  newUser["userInfo"]["username"] = user_hash;
  newUser["userInfo"]["password"] = pw_hash;

  
  users += newUser;
  usersJSON.updateUserJSON(users);

  std::cout << "User successfully registered.\n" << std::endl;
}

void Account::accLogin(bool *isLoggedIn){
  json users, newUser;
  int userCount;
  std::string username, password;
  std::size_t user_hash, pw_hash;
  bool isFound;

  isFound = false;

  if(*isLoggedIn){
    std::cout << "A user is already logged in!\n" << std::endl;
    return;
  }

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
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid input. Please try again.\n" << std::endl;
    accLogin(isLoggedIn);
  }

  user_hash = std::hash<std::string>{}(username);

  std::cout << "Enter a password: ";
  std::cin >> password;

  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid input. Please try again.\n" << std::endl;
  }

  pw_hash = std::hash<std::string>{}(password);
  
  for(int i = 0; (i < userCount); i++){
    if(users[i]["userInfo"]["username"] == user_hash){
      if(users[i]["userInfo"]["password"] == pw_hash){
        isFound = true;
      }
    }
  }

  if(isFound){
    std::cout << "Login successful!\n" << std::endl;
    *isLoggedIn = true;
  } else {
    std::cout << "ERROR: User not found!\n" << std::endl;
    *isLoggedIn = false;
  }
}

void Account::accLogout(bool *isLoggedIn){
  int choice;

  if(!*isLoggedIn){
    std::cout << "No user logged in!" << "\n" << std::endl;
    return;
  }

  std::cout << "Do you wish to log out [1 - yes][0 - no]: ";
  std::cin >> choice;
  std::cout << std::endl;

  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid choice. Please try again.\n" << std::endl;
  } else if (choice != 0 && choice != 1){
    std::cout << "Number out of range. Please try again\n" << std::endl;
  }

  if(choice == 1){
    *isLoggedIn = false;
    std::cout << "User successfully logged out!\n" << std::endl;
  } else {
    *isLoggedIn = true;
  }
}