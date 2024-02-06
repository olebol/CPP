NAME			:= RPN
NICKNAME		:= EX01 - Reverse Polish Notation

# Directories
HDR_DIR			:= include
LIB_DIR			:= lib
SRC_DIR			:= src
OBJ_DIR			:= obj

# Compiler flags
CC				:= c++
CFLAGS			:= -Wall -Werror -Wextra -std=c++11 

ifdef DEBUG
	CFLAGS		+= -g -fsanitize=address
endif

# Includes
HDR_FILES		:=								\
					RPN.hpp						\


# Files
SRC_FILES		:=								\
					main.cpp					\
					RPN.cpp						\

SRC				:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ				:= ${addprefix ${OBJ_DIR}/, ${SRC_FILES:.cpp=.o}}
HDR				:= $(addprefix $(HDR_DIR)/, $(HDR_FILES))

# Colours
GREEN			:= \033[32;1m
YELLOW			:= \033[33;1m
RED				:= \033[31;1m
BOLD			:= \033[1m
RESET			:= \033[0m

# Rules
all: ${NAME}

$(NAME): $(OBJ)
	@ printf "%b%s%b" "$(YELLOW)$(BOLD)" "Compiling $(NICKNAME)..." "$(RESET)"
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@ printf "\t\t%b%s%b\n" "$(GREEN)$(BOLD)" "[OK]" "$(RESET)"


$(OBJ_DIR)/%.o: src/%.cpp $(HDR)
	@ mkdir -p obj
	@ $(CC) $(CFLAGS) -c $< -o $@ -I $(HDR_DIR)

open: $(NAME)
	@ ./$(NAME)

test: $(NAME)
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@ echo

	./$(NAME) "7 7 * 7 -"
	@ echo

	./$(NAME) "1 2 + 3 4 + *"
	@ echo

	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@ echo

	./$(NAME) "1"
	@ echo

	./$(NAME) "1 2 3 4 5 6 7 8 9 1 + + + + + + + + +"
	@ echo

	./$(NAME) "     -1     "
	@ echo

	./$(NAME) "8 -9 * 9 - -9 - 9 - -4 - 1 +"
	@ echo

	./$(NAME) "1 2 3 4 5 6 7 8 9 10"
	@ echo

	./$(NAME) "(1 + 1)"
	@ echo

	./$(NAME) "1 2"
	@ echo

	./$(NAME) "12 2 +"
	@ echo

	./$(NAME) "1 + 2"
	@ echo

	./$(NAME) "+"
	@ echo

	./$(NAME) ""
	@ echo

	./$(NAME)
	@ echo

clean:
	@ echo "$(RED)$(BOLD)Cleaning $(NICKNAME)...$(RESET)"
	@ rm -rf $(OBJ_DIR)

fclean:
	@ echo "$(RED)$(BOLD)Fully cleaning $(NICKNAME)...$(RESET)"
	@ rm -rf $(OBJ_DIR)
	@ rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all test clean fclean re