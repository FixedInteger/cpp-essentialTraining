#include <iostream>
#include <list>
#include <string>
 

int check_parameters(int argc,char const *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		for( int j = 0; j < (int)strlen(argv[i]); j++)
		std::cout << (char)toupper(argv[i][j]);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		check_parameters(argc,argv);
	return 0;
}

	