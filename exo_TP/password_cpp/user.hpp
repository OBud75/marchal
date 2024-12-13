#include <memory>
#include <string>

class Password; // makes a error.

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
