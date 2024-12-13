#include "password.hpp"
#include "user.hpp"

int main() {
  // Create a Person with password
  // test password encryption
      // assert person.password == "toto"
  // person.save()


  Password pwd = Password("mypassword"); 

  User u = User(1, pwd);
  u.save();

  return 0;
};
