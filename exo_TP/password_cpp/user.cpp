#include "user.hpp"
#include "password.hpp"

User::User(int id, Password &password): id(id), password(password) {
  is_logged_in = false;
}

/*
void User::save() {
  // In a file (or DB)
  // id | password (hashed) 
  std::string content = std::to_string(this->id) + "|" + password->str();
  printf("%s\n", content);
};

int User::login(char *raw_password) {
  // Compare raw_password with password in DB
  // for user with id this.id
  is_logged_in = true; // If passwords match
  return 0;
}

User& User::get(int id) {
  // Read file
  // if id of row == id:
  // get raw data
  // password = Password(raw[password], is_encrypted=true)
  // return User(raw[id], password)
}
*/
