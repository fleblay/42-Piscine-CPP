SRC_DIR		= ./src
SRC_LIST	= main.cpp Fixed.cpp Point.cpp bsp.cpp
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_LIST))

HEADER_DIR	= ./inc
HEADER_LIST	= Fixed.hpp Point.hpp
HEADERS		= $(addprefix $(HEADER_DIR)/, $(HEADER_LIST))

OBJ_DIR		= ./obj
OBJS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
CPP			= c++

NAME		= bsp

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c $< -I $(HEADER_DIR) -o $@

$(OBJ_DIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJ_DIR)

fclean	: clean
	rm -rf $(NAME)

re : clean all

.PHONY : all clean fclean re
