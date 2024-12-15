// a slightly upgraded version of password 1

#include <string>
#include <iostream>
#include <regex> // for Password::is_valid

class Password {
    private:
        std::string raw_value;
        std::string encrypted_value;
        void encrypt();
        bool is_valid(const std::string &password) const;

    public:
        Password(const std::string &password, bool is_encrypted = false);

	static std::string encrypt(std::string);
        std::string str() const;
        bool operator==(const std::string &str) const;
        bool operator==(const Password &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Password &p);
};

