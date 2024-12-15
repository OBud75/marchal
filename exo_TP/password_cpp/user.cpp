#include "user.hpp"
#include "password.hpp"

User::User(int id, Password &password): id(id), password(password) {
  (*this).is_logged_in = false; // same as `this->is_logged_in`
}

std::string extract_id(std::string line) {
	int marker = -1;
	int i = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i]=='|') {
			marker = i;
			break;
		}
	}

	if (marker == -1) {
		return "";
	} else {
		return line.substr(0,marker);
	}
}


bool User::id_exits(std::string id_value) {
  std::ifstream file("pwd.data");

  
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
	  if (extract_id(line)==id_value) {
		  return true;
	  }
    }
    file.close();
  } else {
    std::cerr << "Unable to open file" << std::endl;
  }

  return false;
}

bool User::id_exits(int id_value) {
	return id_exits(std::to_string(id_value));
}

void User::save() {
  // In a file (or DB)
  // id|password (hashed) 

  if (!id_exits(this->id)) {
	  std::string content = std::to_string(this->id) + "|" + password.str() + "\n";
	  std::fstream file("pwd.data", file.out | file.app);
	  file << content;
	  std::cout << "Saved: " << content << std::endl;
  }
  printf("Password already saved!\n");
}

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
