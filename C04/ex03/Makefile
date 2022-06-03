SRC_DIR		= ./src
SRC_LIST	= AMateria.cpp Character.cpp Ice.cpp MateriaSource.cpp main.cpp Cure.cpp
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_LIST))

HEADER_DIR	= ./inc
HEADER_LIST	= AMateria.hpp Character.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp\
			MateriaSource.hpp Colors.hpp Cure.hpp
HEADERS		= $(addprefix $(HEADER_DIR)/, $(HEADER_LIST))

OBJ_DIR		= ./obj
OBJS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3
CPP			= c++

NAME		= test

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
