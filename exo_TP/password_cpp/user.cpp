#include "user.hpp"
#include "password.hpp"

User::User(int id, Password &password): id(id), password(password) {
  this.is_logged_in = false;
}

bool does_id_exits(std::string) {
  std::ifstream file("filename.txt");
  
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Unable to open file" << std::endl;
  }

  return false;
}


void User::save() {
  // In a file (or DB)
  // id|password (hashed) 
  std::string content = std::to_string(this->id) + "|" + password.str() + "\n";

  std::fstream file("filename.txt", file.out | file.app);
  file << content;

  std::cout << "Saved: " << content << std::endl;

  does_id_exits(std::to_string(this->id));
};

int User::login(char *raw_password) {
  // Compare raw_password with password in DB
  // for user with id this.id
  is_logged_in = true; // If passwords match
  return 0;
}

/*
User& User::get(int id) {
  // Read file
  // if id of row == id:
  // get raw data
  // password = Password(raw[password], is_encrypted=true)
  // return User(raw[id], password)
}
*/
