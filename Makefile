PUSH_SWAP = push_swap
CHECKER = checker 
SRC	= ./srcs/ft_algorithm_sort.c \
	  ./srcs/ft_big_bubble_sort.c \
	  ./srcs/ft_bubble_sort.c \
	  ./srcs/ft_checker.c \
	  ./srcs/ft_delete_first.c \
	  ./srcs/ft_delete_last.c \
	  ./srcs/ft_free_tab.c \
	  ./srcs/ft_lst_bubble_sort.c \
	  ./srcs/ft_lst_is_over.c \
	  ./srcs/ft_lst_is_revsorted.c \
	  ./srcs/ft_lst_issorted.c \
	  ./srcs/ft_lst_is_under.c \
	  ./srcs/ft_lst_len.c \
	  ./srcs/ft_lst_max.c \
	  ./srcs/ft_lst_median.c \
	  ./srcs/ft_lst_min.c \
	  ./srcs/ft_lst_bubble_reverse_sort.c \
	  ./srcs/ft_lst_values.c \
	  ./srcs/ft_max_under_max.c \
	  ./srcs/ft_operations.c \
	  ./srcs/ft_operations_print.c \
	  ./srcs/ft_print_stacks.c \
	  ./srcs/ft_push_ab.c \
	  ./srcs/ft_push_back.c \
	  ./srcs/ft_push_front.c \
	  ./srcs/ft_push_max.c \
	  ./srcs/ft_push_min.c \
	  ./srcs/ft_push_selected_value.c \
	  ./srcs/ft_reverse_rotate.c \
	  ./srcs/ft_rotate.c \
	  ./srcs/ft_shell_help.c \
	  ./srcs/ft_swap_one_two.c \
	  ./srcs/ft_visual_in_terminal.c \
	  ./srcs/ft_get_index_value.c \
	  ./srcs/get_next_line.c \
	  ./srcs/ft_parsing_input.c \
	  ./srcs/shell.c \
	  ./srcs/ft_update_spe.c

PUSH_SWAP_C = ./srcs/push_swap.c
CHECKER_C = ./srcs/checker.c
OBJ = $(SRC:.c=.o)
PUSH_SWAP_O = $(PUSH_SWAP_C:.c=.o)
CHECKER_O = $(CHECKER_C:.c=.o)

MAKE = make

GCC = gcc
FLAGS = -Wall -Werror -Wextra

INC = ./includes
LIB = ./libft

.PHONY: clean fclean all re lib

all: lib $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(OBJ) $(PUSH_SWAP_O)
	@echo Compiling $(PUSH_SWAP)
	@$(GCC) $(FLAGS) -o $(PUSH_SWAP) $(OBJ) $(PUSH_SWAP_O) -I $(INC) -L $(LIB) -lft
	@echo ======[Done]======

$(CHECKER): $(OBJ) $(CHECKER_O)
	@echo Compiling $(CHECKER)
	@$(GCC) $(FLAGS) -o $(CHECKER) $(OBJ) $(CHECKER_O) -I $(INC) -L $(LIB) -lft
	@echo ======[Done]======

$(OBJ): srcs/%.o : srcs/%.c
	@echo "$(PUSH_SWAP)|$(CHECKER) >>> Add/Update $^"
	@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@

$(PUSH_SWAP_O): srcs/%.o : srcs/%.c
	@echo "$(PUSH_SWAP) --> Add/Update $^"
	@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@

$(CHECKER_O): srcs/%.o : srcs/%.c
	@echo "$(CHECKER) --> Add/Update $^"
	@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@

lib:
	@$(MAKE) -C $(LIB)

clean:
	@$(MAKE) -C $(LIB) clean
	@echo Clean objects $(PUSH_SWAP) - $(CHECKER)
	@rm -rf $(OBJ) $(PUSH_SWAP_O) $(CHECKER_O)

fclean: clean
	@$(MAKE) -C $(LIB) fclean
	@echo Clean $(PUSH_SWAP) - $(CHECKER)
	@rm -rf $(PUSH_SWAP) $(CHECKER)
	@echo ======[Clean]======

re: fclean all
