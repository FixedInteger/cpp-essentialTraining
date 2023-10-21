#include "phonebook.hpp"

void phonebook :: add_contacta()
	{
		std::cout << _contact_count << std::endl;
	if (_contact_count < 8) 
	{
		oldest_contact = 0;
		prompt_the_user();
	}
	else 
	{
	   std::string name;
	   std::string surname;
	   std::string nickname;
	   std::string phone;
	   std::string darkest_secret;
	   std::cout << "Enter name: ";
	   name = ft_cin();
	   parse_name(name, "name");
	   std::cout << "Enter surname: ";
	   surname = ft_cin();
	   parse_name(surname, "surname");
	   std::cout << "Enter nickname: ";
	   nickname = ft_cin();
	   parse_name(nickname, "nickname");
	   std::cout << "Enter phone: ";
	   phone = ft_cin();
	   parse_phone(phone);
	   std::cout << "Enter darkest_secret: ";
	   darkest_secret = ft_cin();
	   _contact[oldest_contact].set_name(name);
	   _contact[oldest_contact].set_surname(surname);
	   _contact[oldest_contact].set_nickname(nickname);
	   _contact[oldest_contact].set_phone(phone);
	   _contact[oldest_contact].set_darkest_secret(darkest_secret);
		oldest_contact++;
		if (oldest_contact == 8)
			oldest_contact = 0;
		
	}
};
void phonebook:: print_name()
{
	
	int columnWidth = 15;
	int maxChars = 10;  // Increased to ensure consistency
	std::cout << std::left << std::setw(columnWidth) << "--------------------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(columnWidth) << "|Index         |   First Name   |   Last Name    |  Nickname |" << std::endl;
	std::cout << std::left << std::setw(columnWidth) << "--------------------------------------------------------------" << std::endl;

	for (int i = 0; i < _contact_count; i++) 
	{
		std::cout << std::left << std::setw(columnWidth) << i;
		std::cout << std::left << "| " << std::setw(columnWidth) << truncateString(_contact[i].get_name(), maxChars);
		std::cout << std::left << "| " << std::setw(columnWidth) << truncateString(_contact[i].get_surname(), maxChars);
		std::cout << std::left << "| " << std::setw(columnWidth) << truncateString(_contact[i].get_nickname(), maxChars)<< std::endl;
	}


	int  index = ask_index();
	while (true) 
	{
		if(index == -1 || index > _contact_count - 1 || index < 0)
		{
			std::cout << "Invalid index" << std::endl;
			index = ask_index();
		}
		else
			break;
	} 
		 columnWidth = 5;
		std::cout << std::left << std::setw(columnWidth) << "Name:     " << _contact[index].get_name() << std::endl;
		std::cout << std::left << std::setw(columnWidth) << "Surname:    " << _contact[index].get_surname() << std::endl;
		std::cout << std::left << std::setw(columnWidth) << "Nickname:   " << _contact[index].get_nickname() << std::endl;
		std::cout << std::left << std::setw(columnWidth) << "Phone:    " << _contact[index].get_phone() << std::endl;
		std::cout << std::left << std::setw(columnWidth) << "Darkest secret:  " << _contact[index].get_darkest_secret()<< std::endl;	
}
void phonebook::prompt_the_user() 
{
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone;
	std::string darkest_secret;
	std::cout << "Enter name: ";
	name = ft_cin();
	name = parse_name(name, "name");
	std::cout << "Enter surname: ";
	surname = ft_cin();   
	surname =parse_name(surname, "surname");
	std::cout << "Enter nickname: ";
	nickname = ft_cin();
	nickname = parse_name(nickname, "nickname");
	std::cout << "Enter phone: ";
	phone = ft_cin();
	parse_phone(phone);
	std::cout << "Enter darkest_secret: ";
	darkest_secret = ft_cin();
	darkest_secret = parse_name(darkest_secret, "darkest_secret");
	_contact[_contact_count].set_name(name);
	_contact[_contact_count].set_surname(surname);
	_contact[_contact_count].set_nickname(nickname);
	_contact[_contact_count].set_phone(phone);
	_contact[_contact_count].set_darkest_secret(darkest_secret);
	_contact_count++;
}


std::string parse_command(std::string command) 
{
	int start = 0;
	while (start < (int)command.size() && std::isspace(command[start]))
		start++;
	  int end = command.size();
	while (end > start && std::isspace(command[end - 1]))
		end--;
	if (start < end) 
		return command.substr(start, end - start);
	else 
		return "";
}


#include <iostream>
#include <string>

int main() {
	phonebook phonebook;
	phonebook.set_contact_count(0);

	while (true) {
		std::string command;
		std::cout << "Enter command: ";
		command = ft_cin();
		command = parse_command(command);
		if(std::cin.eof())
			break;
		if (command == "ADD")
			phonebook.add_contacta();
		if (command == "SEARCH")
			phonebook.print_name();
		if (command == "EXIT")
			break;
	}

	return 0;
}









