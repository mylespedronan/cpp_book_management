This is a project for a Book Inventory Management System in C++. A user is able to manage book records such as adding, updating, removing, listing all, checking, renting, and returning books. Data is stored in a JSON file using nlohmann's json library [https://github.com/nlohmann/json]. 

The basic features of the book rental system are:

- Add book (Takes inputs of book details [subject, year, new/used, available/not available])
- Update book Details (Updates details of book in the book records [cost, condition])
- Remove book (Clears existing record of a book)
- List all books (Show all available books)
- Check book (Check book data)
- Rent a book 
- Return a book
- Register 
- Login 
- Logout

Requirements:
- User is brought to book menu upon starting program. User must select an option
  - Book menu shows all available options
  - Users can login at book menu if wanted
    - Book menu changes if user is logged in
      - Changes in book menu include user log out
- To check out a book, a user must have an account
  - If a user is logged in, they will be able to rent a book if they have enough credits
    - If a user does not have enough credits, they cannot rent a book unless they return a book
      - Returning a book adds a credit to user's account
      - Renting a book removes a credit to user's account
      - All accounts have a maximum of 5 credits
  - If a user is new, they must create an account which will be stored in users.json
  
This program uses the hash library found at:
- https://en.cppreference.com/w/cpp/utility/hash