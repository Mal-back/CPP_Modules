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

DEPS =

SRC = srcs/

SRC_FILES = megaphone.cpp

BUILD = build/
OBJ_FILES	= $(addprefix $(BUILD),$(SRC_FILES:%.cpp=%.o))

###########################################################################
###### Compilation arguments
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

NAME = megaphone

###########################################################################
###### Rules

all : $(NAME)

$(NAME) : $(OBJ_FILES) $(DEPS) 
	$(CXX) $(CPPFLAGS) $(OBJ_FILES) -o $(NAME)

$(BUILD)%.o: $(SRC)%.cpp
	mkdir -p ${BUILD}
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(BUILD)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
