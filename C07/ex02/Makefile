CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
CPPFLAGS	=	-I.
SRC			=	main.cpp
OBJ			=	$(SRC:.cpp=.o)

NAME		=	Array


all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)


%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
