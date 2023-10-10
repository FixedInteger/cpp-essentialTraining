#include <iostream>
#include <list>
#include <iomanip> 
#include <limits>
#include <string>
std::string ft_cin() ;
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

int check_isdigi(std::string digit)
{
	for(int i = 0; i < digit.length(); i++)
	{
		if((digit[i] == '-' || digit [i] == '+')&& i == 0)
		{
			i++;
			if(!isdigit(digit[i]) || digit.length() > 2)
				return 0;
		}
		if(!isdigit(digit[i]) && digit.length() > 2)
			return 0;
		
	}
	return 1;
}
int ask_index()
{
	std::cout << "Enter index: ";
	std::string indexo;
	std::cin >> indexo;
	if(!check_isdigi(indexo))
		return -1;
	int index = std::stoi(indexo);
	if(std::cin.fail() || index > 7 || index < 0)
		return -1;
	return index;
}
int isalpha_s(std::string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(!isalpha(str[i]) || isspace(str[i]) )
			return 0;
	}
	return 1;
}
void parse_name(std::string name , std:: string parameter)
{
	while(1)
	{
		if(name.empty() || isalpha_s(name) == 0 )
		{
			std::cout << parameter <<" is invalid" << std::endl;
			std::cout << "Enter " << parameter << ": ";
			name = ft_cin();
		}
		else
			break ;
	}
}


void	parse_phone(std::string phone)
{
	while(1)
	{
		if(phone.empty()  || isdigit(phone[0]) == 0 || phone.length() != 10)
		{
			std::cout << "Phone is invalid" << std::endl;
			if(std::cin.fail() )
			{
				std::cout << "Invalid command" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue ;
			}
			std::cout << "Enter phone: ";
			phone = ft_cin();
			break;
		}
		else
			break ;
	}
}
std::string truncateString(const std::string& input, int maxChars) {
    if (input.length() > maxChars) {
        return input.substr(0, maxChars) + ".";
    }
    return input;
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
	void prompt_the_user();
	void add_contact()
	{
    if (_contact_count < 8) 
	{
		oldest_contact = 0;
		prompt_the_user();
        _contact_count++;
    }
    else {
		prompt_the_user();
		oldest_contact++;
		if(oldest_contact == 7)
			oldest_contact = 0;
    }
}


	void print_name()
	{
	 int columnWidth = 6;
    int maxChars = 10; // Maximum characters to display

    // Print header row
    std::cout << std::left << std::setw(columnWidth) << "Contact";
    std::cout << std::left << std::setw(columnWidth) << "Name";
    std::cout << std::left << std::setw(columnWidth) << "Surname";
    std::cout << std::left << std::setw(columnWidth) << "Nickname";
    std::cout << std::left << std::setw(columnWidth) << "Phone";
    std::cout << std::left << std::setw(columnWidth) << "Darkest Secret" << std::endl;

    // Iterate through contacts and display each contact's information
    for (int i = 0; i < _contact_count; i++) {
        std::cout << std::left << std::setw(columnWidth) << i;

        // Display the first ten characters of each field with a point
        std::cout << std::left << std::setw(columnWidth) << truncateString(_contact[i].get_name(), maxChars);
        std::cout << std::left << std::setw(columnWidth) << truncateString(_contact[i].get_surname(), maxChars);
        std::cout << std::left << std::setw(columnWidth) << truncateString(_contact[i].get_nickname(), maxChars);
        std::cout << std::left << std::setw(columnWidth) << truncateString(_contact[i].get_phone(), maxChars);
        std::cout << std::left << std::setw(columnWidth) << truncateString(_contact[i].get_darkest_secret(), maxChars) << std::endl;
    }

	unsigned long   index = ask_index();
	while (true) 
	{
    if (index < 0 || index >= _contact_count || _contact[index].get_name().empty()) 
	{
        std::cout << "Wrong index" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        index = ask_index();
    } 
	else 
	{
		 int columnWidth = 5;
        std::cout << std::left << std::setw(columnWidth) << "Name:" << _contact[index].get_name() << std::endl;
    	std::cout << std::left << std::setw(columnWidth) << "Surname:" << _contact[index].get_surname() << std::endl;
    	std::cout << std::left << std::setw(columnWidth) << "Nickname:" << _contact[index].get_nickname() << std::endl;
    	std::cout << std::left << std::setw(columnWidth) << "Phone:" << _contact[index].get_phone() << std::endl;
    	std::cout << std::left << std::setw(columnWidth) << "Darkest secret:" << _contact[index].get_darkest_secret()<< std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
}		
}
};

void phonebook::set_contact_count(int contact_count)
{
	this->_contact_count = contact_count;
}
std::string ft_cin() {
    std::string str;
    std::getline(std::cin, str); 

    return str;
}


void phonebook::prompt_the_user() {
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
	parse_name(darkest_secret, "darkest_secret");
    _contact[_contact_count].set_name(name);
    _contact[_contact_count].set_surname(surname);
    _contact[_contact_count].set_nickname(nickname);
    _contact[_contact_count].set_phone(phone);
    _contact[_contact_count].set_darkest_secret(darkest_secret);
}

int main()
{

	phonebook phonebook;
	phonebook.set_contact_count(0);
	while(true)
	{
		std::cin.clear();
		std::cout << "Enter command: ";
		std::string command;
		command = ft_cin();
		if(std::cin.fail())
		{
			std::cout << "Invalid command" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			continue ;
		}
		if(command == "ADD")
			phonebook.add_contact();
		if(command == "SEARCH")
			phonebook.print_name();
		if(command == "EXIT")
			break ;
	}

	return 0;
}



