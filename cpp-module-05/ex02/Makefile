# cpp makefile

NAME	:= forms
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++17

SRCS	:= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ_DIR	:= objs/
OBJS	:= $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

RED		:=	\033[0;31m
GREEN	:=	\033[0;32m
EC		:=	\033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(EC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed$(EC)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf home_shrubbery
	@echo "$(RED)Full clean up completed$(EC)"

re: fclean all

.PHONY: all clean fclean re