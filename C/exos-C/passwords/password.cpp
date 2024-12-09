#include "password.hpp"

Password::Password(std::string &password, bool is_encrypted=false) : 
  _raw_value(password) {
    // check(password) > 6char, 1 maj, 1 char special
    // if is_encrypted == false -> encrypt()
    // else {_encrypted_value = password;}
  }

Password::is_valid(std::string &password){
  // if < 6 chars : raise
  // if not cap letters : raise
}

void Password::encrypt(const std::string &password) {}

std::string Password::str() {
  return _encrypted_value;
}

bool Password::operator==(const std::string &str) const {
  return str == _encrypted_value;
}

bool Password::operator==(const Password &other) const {

}

std::ostream &operator<<(std::ostream &os, const Password &p) {
  os << p._encrypted_value;
  return os;
}
