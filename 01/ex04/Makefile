NAME			:= sed
NICKNAME		:= EX04 - SED IS FOR LOSERS

# Directories
HDR_DIR			:= include
LIB_DIR			:= lib
SRC_DIR			:= src
OBJ_DIR			:= obj

# Compiler flags
CC				:= c++
CFLAGS			:= -Wall -Werror -Wextra -std=c++98 

ifdef DEBUG
	CFLAGS		+= -g -fsanitize=address
endif

# Includes
HDR_FILES		:=							\
					colors.h				\

# Files
SRC_FILES		:=							\
					main.cpp				\


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

log:
	@ git log --graph --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%an%C(reset)%C(bold yellow)%d%C(reset) %C(dim white)- %s%C(reset)' --all

clean:
	@ echo "$(RED)$(BOLD)Cleaning $(NICKNAME)...$(RESET)"
	@ rm -rf $(OBJ_DIR)

fclean:
	@ echo "$(RED)$(BOLD)Fully cleaning $(NICKNAME)...$(RESET)"
	@ rm -rf $(OBJ_DIR)
	@ rm -rf ${NAME}

re: fclean ${NAME}

test:
	@ echo "			SHREK" > test
	@ echo "Once upon a time there was a lovely" >> test
	@ echo "princess. But she had an enchantment" >> test
	@ echo "upon her of a fearful sort which could" >> test
	@ echo "only be broken by love's first kiss." >> test
	@ echo "She was locked away in a castle guarded" >> test
	@ echo "by a terrible fire-breathing dragon." >> test
	@ echo "Many brave knights had attempted to" >> test
	@ echo "free her from this dreadful prison," >> test
	@ echo "but non prevailed. She waited in the" >> test
	@ echo "dragon's keep in the highest room of" >> test
	@ echo "the tallest tower for her true love" >> test
	@ echo "and true love's first kiss. (laughs)" >> test
	@ echo "Like that's ever gonna happen. What" >> test
	@ echo "a load of - (toilet flush)" >> test
	@ echo >> test
	@ echo "Allstar - by Smashmouth begins to play. Shrek goes about his" >> test
	@ echo "day. While in a nearby town, the villagers get together to go" >> test
	@ echo "after the ogre." >> test
	@ printf "$(GREEN)$(BOLD)File [test] created!$(RESET)"

cleantest:
	@ rm -rf test
	@ rm -rf test.replace


.PHONY: all norminette clean fclean re test cleantest