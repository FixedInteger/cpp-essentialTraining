#include <iostream>
#include <list>
// setters and getterskkpp
class contact{
	private:
	std::string _name;
	std::string _surname;
	std::string _nickname;
	std::string _phone;
	std::string _darkest_secret;
public:
	//setters prototypes
	void set_name(std::string name);
	void set_surname(std::string surname);
	void set_nickname(std::string nickname);
	void set_phone(std::string phone);
	void set_darkest_secret(std::string darkest_secret);
	//getters prototypes
	std::string get_name() {return _name;}
	std::string get_surname() {return _surname;}
	std::string get_nickname() {return _nickname;}
	std::string get_phone() {return _phone;}
	std::string get_darkest_secret() {return _darkest_secret;}

};
void contact ::set_name(std::string name)
{
	this->_name = name;
}
void	contact::set_surname(std::string surname)
{
	this->_surname = surname;
}
void contact :: set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}
void contact :: set_phone(std::string phone)
{
	this->_phone = phone;
}
void contact :: set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
int ask_index()
{
	std::cout << "Enter index: ";
	int index;
	std::cin >> index;
	return index;
}
class phonebook
{
	private:
	contact _contact[8];
	int _contact_count;
	int oldest_contact;
public:
	void set_contact_count(int contact_count);
	int get_contact_count();
	void add_contact()
	{
    if (_contact_count < 8) 
	{
		oldest_contact = 0;
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
        _contact[_contact_count].set_name(name);
        _contact[_contact_count].set_surname(surname);
        _contact[_contact_count].set_nickname(nickname);
        _contact[_contact_count].set_phone(phone);
        _contact[_contact_count].set_darkest_secret(darkest_secret);
        _contact_count++;
    }
    else {

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
        _contact[oldest_contact].set_name(name);
        _contact[oldest_contact].set_surname(surname);
        _contact[oldest_contact].set_nickname(nickname);
        _contact[oldest_contact].set_phone(phone);
        _contact[oldest_contact].set_darkest_secret(darkest_secret);
		oldest_contact++;
		if(oldest_contact == 7)
			oldest_contact = 0;
    }
}

	void print_name()
	{
		for(int i = 0; i < _contact_count; i++)
		{
			std::cout << "Contact " << i << std::endl;
			std::cout << _contact[i].get_name() << std::endl;
			if(_contact[i].get_surname().empty())
				std::cout << "Surname is empty" << std::endl;
			else {
			std::cout << _contact[i].get_surname() << std::endl;
			std::cout << _contact[i].get_nickname() << std::endl;
			std::cout << _contact[i].get_phone() << std::endl;
			std::cout << _contact[i].get_darkest_secret() << std::endl;
			}
		}
		unsigned long   index = ask_index();
		while(index)
		{
			if(index >= 0 && index < _contact_count || index < 7)
				break ;
			else
			{
				std::cout << "Wrong index" << std::endl;
				std::cin.clear();
				index = ask_index();
			}
		}
		std::cout << "Contact " << index << std::endl;
		std::cout << _contact[index].get_name() << std::endl;
		if(_contact[index].get_surname().empty())
			std::cout << "Surname is empty" << std::endl;
		else {
		std::cout << _contact[index].get_surname() << std::endl;
		std::cout << _contact[index].get_nickname() << std::endl;
		std::cout << _contact[index].get_phone() << std::endl;
		std::cout << _contact[index].get_darkest_secret() << std::endl;
		}
		
	}


};

void phonebook::set_contact_count(int contact_count)
{
	this->_contact_count = contact_count;
}

int main()
{

	phonebook phonebook;
	phonebook.set_contact_count(0);
	while(true)
	{
		if(std::cin.eof() || std::cin.fail())
			break ;
		std::cin.clear();
		std::cout << "Enter command: ";
		std::string command;
		std::cin >> command;
		if(command == "ADD")
			phonebook.add_contact();
		if(command == "SEARCH")
			phonebook.print_name();
		if(command == "EXIT")
			break ;
	}

	return 0;
}



