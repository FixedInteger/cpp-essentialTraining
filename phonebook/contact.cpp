#include "contact.hpp"

void contact::set_name(std::string name)
{
   this->_name = name;
}
void contact::set_surname(std::string surname)
{
   this->_surname = surname;
}
void contact::set_nickname(std::string nickname)
{
   this->_nickname = nickname;
}
void contact::set_phone(std::string phone)
{
   this->_phone = phone;
}
void contact::set_darkest_secret(std::string darkest_secret)
{
   this->_darkest_secret = darkest_secret;
}

class phonebook
{
    private:
    contact _contact[8];
    int _contact_count;
    public:
    void set_contact_count(int contact_count);
    int get_contact_count();
    void add_contact();
    void search_contact();
    void print_contact();
};

void phonebook::set_contact_count(int contact_count)
{
    this->_contact_count = contact_count;
}
int phonebook::get_contact_count()
{
    return this->_contact_count;
}
void phonebook::add_contact()
{
    std::string name;
    std::string surname;
    std::string nickname;
    std::string phone;
    std::string darkest_secret;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter surname: ";
    std::cin >> surname;
    std::cout << "Enter nickname: ";
    std::cin >> nickname;
    std::cout << "Enter phone: ";
    std::cin >> phone;
    std::cout << "Enter darkest_secret: ";
    std::cin >> darkest_secret;
    set_contact_count(get_contact_count() + 1);
    _contact[get_contact_count()].set_name(name);
    _contact[get_contact_count()].set_surname(surname);
    _contact[get_contact_count()].set_nickname(nickname);
    _contact[get_contact_count()].set_phone(phone);
    _contact[get_contact_count()].set_darkest_secret(darkest_secret);
    
}

