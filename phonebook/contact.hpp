#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class contact{
    private:
    std::string _name;
    std::string _surname;
    std::string _nickname;
    std::string _phone;
    std::string _darkest_secret;
    public:
    void set_name(std::string name);
};
#endif