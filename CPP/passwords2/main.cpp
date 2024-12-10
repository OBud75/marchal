#include "password.hpp"

int main() {
    try {
        // Create a Password object
        Password password1("Secure@123");
        
        // Print the encrypted password
        std::cout << "Encrypted Password: " << password1 << std::endl;

        // Compare the encrypted password with a string
        if (password1 == "ENC(Secure@123)") {
            std::cout << "Password matches the encrypted string!" << std::endl;
        } else {
            std::cout << "Password does not match the encrypted string." << std::endl;
        }

        // Create another Password object from an encrypted password
        Password password2("ENC(Secure@123)", true);

        // Compare two Password objects
        if (password1 == password2) {
            std::cout << "Passwords are identical!" << std::endl;
        } else {
            std::cout << "Passwords are different!" << std::endl;
        }

        // Access the encrypted password as a string
        std::cout << "Encrypted password as a string: " << password1.str() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

