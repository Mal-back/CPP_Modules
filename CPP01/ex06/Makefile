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

DEPS = $(OBJ_FILES:%.o=%.d)

SRC = srcs/

SRC_FILES = main.cpp Harl.cpp 

BUILD = build/
OBJ_FILES	= $(addprefix $(BUILD),$(SRC_FILES:%.cpp=%.o))

###########################################################################
###### Compilation arguments
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

CXX = c++

NAME = Harl

###########################################################################
###### Rules

all : $(NAME)

$(NAME) : make_dir $(OBJ_FILES) $(DEPS)
	$(CXX) $(CPPFLAGS) $(OBJ_FILES) -o $(NAME)

-include $(DEPS)

$(BUILD)%.o: $(SRC)%.cpp
	$(CXX) $(CPPFLAGS) -MMD -I$(INCLUDES) -c $< -o $@

make_dir :
	@mkdir -p $(BUILD)

clean :
	rm -rf $(BUILD)

fclean : clean
	rm -rf $(NAME)

to_push : fclean
	rm -rf compile_flags.txt

re : fclean all

.PHONY : all clean fclean re make_dir to_push
