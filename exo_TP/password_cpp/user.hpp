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
	bool id_exits(int id_value);
	bool id_exits(std::string id_value);

    public:
        explicit User(int id, Password &password);

        void save();
        int login(char *raw_password);
        static User &get(int id);
};
