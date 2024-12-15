#include "password.hpp"
#include "user.hpp"

int main() {
  // Create a Person with password
  // test password encryption
      // assert person.password == "toto"
  // person.save()


  /*
  Password pwd = Password("mypassword"); 

  User u = User(1, pwd);
  //u.save();
  u.login("mypassword");
  u.save();

  std::cout << "user: " << u.str() << std::endl;
  std::cout << u << std::endl;
  */

  auto u2 = User::get(1,Password("mypassword"));
  if (u2) {
  	std::cout << *u2 << std::endl;
  }

  return 0;
};
