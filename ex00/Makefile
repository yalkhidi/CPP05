CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98
NAME		:= bureaucrat
FILES		:= Bureaucrat.cpp main.cpp
OBJ			:= $(FILES:.cpp=.o)
HEADER		:= Bureaucrat.hpp


all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
 
re: fclean all

.PHONY: all re clean fclean