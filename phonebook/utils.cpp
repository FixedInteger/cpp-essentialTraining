#include "phonebook.hpp"
std::string ft_cin() ;
int check_isdigi(std::string digit)
{
	for(int i = 0; i < (int )digit.length(); i++)
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
	std ::string indexo ;
	indexo = ft_cin();
	if(!check_isdigi(indexo))
		return -1;
	int index = atoi(indexo.c_str());
	if(std::cin.fail() || index > 7 || index < 0)
		return -1;
	return index;
}
int isalpha_s(std::string str)
{
	for(int i = 0; i < (int )str.length(); i++)
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
std::string truncateString(const std::string& input, int maxChars)
{
    if ((int)input.length() > maxChars) {
        return input.substr(0, maxChars) + ".";
    }
    return input;
}
std::string ft_cin() {
    std::string str;
    std::getline(std::cin, str); 
    return str;
}