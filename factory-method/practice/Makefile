NAME 	:= order
CXX 	:= c++
CXXFLAGS:= -std=c++11 -Wall -Wextra -Werror -pedantic -O3
SRC 	:= $(wildcard *.cpp)
OBJ 	:= $(SRC:.cpp=.o)
RM 		:= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re