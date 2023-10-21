#if !defined( PHONEBOOK_HPP )
#define PHONEBOOK_HPP
#include "contact.hpp"
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
	void prompt_the_user2();
	void print_name();
	void add_contacta();
};
int check_isdigi(std::string digit);
int ask_index();
int isalpha_s(std::string str);
std::string parse_name(std::string name , std:: string parameter);
void	parse_phone(std::string phone);
std::string truncateString(const std::string& input, int maxChars);
std::string ft_cin() ;

#endif // 
