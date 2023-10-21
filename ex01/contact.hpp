#ifndef Contact_HPP
#define Contact_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

class Contact{
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
#endif