#include <memory>
#include <iostream>
#include <fstream>
#include <string>

class Password; 

class User {
    private:
        int id;
        Password &password;
        bool is_logged_in;

    public:
        explicit User(int id, Password &password);

        void save();
        int login(char *raw_password);
        static User &get(int id);
};
