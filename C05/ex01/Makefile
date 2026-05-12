SRC	= main.cpp Bureaucrat.cpp Form.cpp
OBJ	= $(SRC:.cpp=.o)
CXX	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= Bureaucrat

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
