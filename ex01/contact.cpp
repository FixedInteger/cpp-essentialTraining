#include "contact.hpp"

void Contact::set_name(std::string name)
{
   this->_name = name;
}
void Contact::set_surname(std::string surname)
{
   this->_surname = surname;
}
void Contact::set_nickname(std::string nickname)
{
   this->_nickname = nickname;
}
void Contact::set_phone(std::string phone)
{
   this->_phone = phone;
}
void Contact::set_darkest_secret(std::string darkest_secret)
{
   this->_darkest_secret = darkest_secret;
}

class PhoneBook
{
    private:
    Contact _Contact[8];
    int _Contact_count;
    public:
    void set_Contact_count(int Contact_count);
    int get_Contact_count();
    void add_Contact();
    void search_Contact();
    void print_Contact();
};

void PhoneBook::set_Contact_count(int Contact_count)
{
    this->_Contact_count = Contact_count;
}
int PhoneBook::get_Contact_count()
{
    return this->_Contact_count;
}
void PhoneBook::add_Contact()
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
    set_Contact_count(get_Contact_count() + 1);
    _Contact[get_Contact_count()].set_name(name);
    _Contact[get_Contact_count()].set_surname(surname);
    _Contact[get_Contact_count()].set_nickname(nickname);
    _Contact[get_Contact_count()].set_phone(phone);
    _Contact[get_Contact_count()].set_darkest_secret(darkest_secret);
    
}

