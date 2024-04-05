###########################################################################
###### Colors :
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m
RESET	=	\033[0m

###########################################################################
###### Sources and includes path
INCLUDES = includes/

DEPS = $(addprefix $(INCLUDES), HumanA.hpp, HumanB.hpp, Weapon.hpp)

SRC = srcs/

SRC_FILES = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

BUILD = build/
OBJ_FILES	= $(addprefix $(BUILD),$(SRC_FILES:%.cpp=%.o))

###########################################################################
###### Compilation arguments
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

CXX = c++

NAME = Weapon

###########################################################################
###### Rules

all : $(NAME)

$(NAME) : $(OBJ_FILES) 
	$(CXX) $(CPPFLAGS) $(OBJ_FILES) -o $(NAME)

$(BUILD)%.o: $(SRC)%.cpp
	@mkdir -p $(BUILD)
	$(CXX) $(CPPFLAGS) -I$(INCLUDES) -c $< -o $@

clean :
	rm -rf $(BUILD)

fclean : clean
	rm -rf $(NAME)

to_push : fclean
	rm -rf compile_flags.txt

re : fclean all

.PHONY : all clean fclean re to_push
