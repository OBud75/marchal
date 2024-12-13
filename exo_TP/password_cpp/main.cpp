#include "password.hpp"
#include "user.hpp"

int main() {
  // Create a Person with password
  // test password encryption
      // assert person.password == "toto"
  // person.save()


  auto pwd = Password("mypassword"); 
  //std::cout << p->str() << std::endl;

  auto u = User(1, pwd);

  std::cout << "ok" << std::endl;

  return 0;
};
