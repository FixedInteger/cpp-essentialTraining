#include "phonebook.hpp"
void  PhoneBook::prompt_the_user2()
{
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone;
	std::string darkest_secret;
	name = parse_name("name");
	surname = parse_name( "surname");
	nickname = parse_name("nickname");
	phone = parse_phone("phone");
	darkest_secret = parse_name("darkest_secret");
	_Contact[oldest_Contact].set_name(name);
	_Contact[oldest_Contact].set_surname(surname);
	_Contact[oldest_Contact].set_nickname(nickname);
	_Contact[oldest_Contact].set_phone(phone);
	_Contact[oldest_Contact].set_darkest_secret(darkest_secret);
		oldest_Contact++;
		if (oldest_Contact == 7)
			oldest_Contact = 0;
	
}
void PhoneBook :: add_Contacta()
{
	if (_Contact_count < 8) 
	{
		oldest_Contact = 0;
		prompt_the_user();
	}
	else
		prompt_the_user2();
}
void PhoneBook:: print_name()
{
	if(_Contact_count == 0)
	{
		std::cout << "No contacts" << std::endl;
		return;
	}
	
	int columnWidth = 15;
	int maxChars = 10;// Increased to ensure consistency
	std::cout << std::right << std::setw(columnWidth) << "--------------------------------------------------------------" << std::endl;
	std::cout << std::right << std::setw(columnWidth) << "|Index         |   First Name   |   Last Name    |   Nickname  |" << std::endl;
	std::cout << std::right << std::setw(columnWidth) << "--------------------------------------------------------------" << std::endl;

	for (int i = 0; i < _Contact_count; i++) 
	{
		std::cout << std::right << std::setw(columnWidth) << i;
		std::cout << std::right << "| " << std::setw(columnWidth) << truncateString(_Contact[i].get_name(), maxChars);
		std::cout << std::right << "| " << std::setw(columnWidth) << truncateString(_Contact[i].get_surname(), maxChars);
		std::cout << std::right << "| " << std::setw(12) << truncateString(_Contact[i].get_nickname(), maxChars)<< std::endl;
	}


	int  index = ask_index();
	while (true) 
	{
		if(index == -1 || index > _Contact_count - 1 || index < 0)
		{
			std::cout << "Invalid index" << std::endl;
			index = ask_index();
		}
		else
			break;
	} 
		 columnWidth = 5;
		std::cout << std::left << std::setw(columnWidth) << "Name:     " << _Contact[index].get_name() << std::endl;
		std::cout << std::left << std::setw(columnWidth) << "Surname:    " << _Contact[index].get_surname() << std::endl;
		std::cout << std::left << std::setw(columnWidth) << "Nickname:   " << _Contact[index].get_nickname() << std::endl;
		std::cout << std::left << std::setw(columnWidth) << "Phone:    " << _Contact[index].get_phone() << std::endl;
		std::cout << std::left << std::setw(columnWidth) << "Darkest secret:  " << _Contact[index].get_darkest_secret()<< std::endl;	
}
void PhoneBook::prompt_the_user() 
{
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone;
	std::string darkest_secret;
	name = parse_name("name");
	surname = parse_name( "surname");
	nickname = parse_name("nickname");
	phone = parse_phone("phone");
	darkest_secret = parse_name("darkest_secret");
	_Contact[_Contact_count].set_name(name);
	_Contact[_Contact_count].set_surname(surname);
	_Contact[_Contact_count].set_nickname(nickname);
	_Contact[_Contact_count].set_phone(phone);
	_Contact[_Contact_count].set_darkest_secret(darkest_secret);
	_Contact_count++;
}




#include <iostream>
#include <string>

int main() {
	PhoneBook phonebook;
	phonebook.set_Contact_count(0);
	while (true) {
		std::string command;
		std::cout << "Enter command: ";
		command = ft_cin();
		if(std::cin.eof())
			break;
		if (command == "ADD")
			phonebook.add_Contacta();
		if (command == "SEARCH")
			phonebook.print_name();
		if (command == "EXIT")
			break;
		else if(command != "ADD" && command != "SEARCH" && command != "EXIT" && !std::cin.eof())
			std::cout << "Invalid command" << std::endl;

	}

	return 0;
}









