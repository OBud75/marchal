#include "password.hpp"
#include <functional> // For std::hash


Password::Password(const std::string &password, bool is_encrypted) {
    if (!is_encrypted) {
        if (!is_valid(password)) {
		std::cout << "Password must be at least 6 characters long, contain one uppercase letter, and one special character (using it anyway)." << std::endl;
        }
        raw_value = password;
        encrypt();
    } else {
        encrypted_value = password;
    }
}

bool Password::is_valid(const std::string &password) const {
    if (password.length() < 6) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[A-Z]"))) {
        return false;
    }
    if (!std::regex_search(password, std::regex("[!@#$%^&*(),.?\":{}|<>]"))) {
        return false;
    }
    return true;
}

std::string Password::encrypt(std::string str) {
    // return "ENC(" + str + ")";
    // Doing is better... (ref: https://en.cppreference.com/w/cpp/utility/hash):
    std::hash<std::string> hasher;
    std::size_t hashed_value = hasher(str); // `size_t` is an `unsigned int`
    return std::to_string(hashed_value);
}

void Password::encrypt() {
    // Simple encryption logic for demonstration purposes
    encrypted_value = encrypt(raw_value);
}

std::string Password::str() const {
    return encrypted_value;
}

bool Password::operator==(const std::string &str) const {
    return str == encrypted_value;
}

bool Password::operator==(const Password &other) const {
    return encrypted_value == other.encrypted_value;
}

std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p.encrypted_value;
    return os;
}

