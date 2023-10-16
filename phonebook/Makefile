NAME = phonebook
CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =  contact.cpp phonebook.cpp utils.cpp

# Path: phonebook/Makefile
OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	$(CC) $(FLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)


clean:
	rm -f $(OBJ)