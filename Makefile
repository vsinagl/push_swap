#test for operations functions and linked list functions
TST_OP:= src/ops1.c\
		 src/list.c\
		 test/list%ops_test.c\
		 test/utils_test.c\

TST_INPUT:= src/ops1.c\
			src/list.c\
			src/main.c\
			test/utils_test.c\

TST:=	src/ops1.c\
		src/list.c\
		src/main.c\
		src/sort2.c\
		src/utils1.c\
		src/utils2.c\
		src/utils3.c\
		src/middleway.c\
		src/merge_sort.c\
		src/merge_sort_uts.c\
		src/split_chunks.c

BONUS_S:=	src/ops1.c\
		src/list.c\
		src/sort2.c\
		src/utils1.c\
		src/utils2.c\
		src/utils3.c\
		src/middleway.c\
		src/merge_sort.c\
		src/merge_sort_uts.c\
		src/split_chunks.c\
		src/bonus/checker.c\
		src/bonus/get_next_line_bonus.c\
		src/bonus/get_next_line_utils_bonus.c

BONUS_O:= $(BONUS_S:.c=.o)
#test/utils_test.c

TST_O:= $(TST:.c=.o)
			
#external libraries
LIBFT:= libft2/libft.a
PRINTF:= ft_printf/printf.a

#compiler instructions:
COMPILER:= clang
FLAGS:= -Wall -Wextra -Werror
NAME:= push_swap
BONUS:= checker_vsinagl

#COLORS
Black = \033[0;30m
Red = \033[0;31m
Green = \033[0;32m
Yellow = \033[0;33m
Blue = \033[0;34m
Magenta = \033[0;35m
Cyan = \033[0;36m
White = \033[0;37m
END = \033[0;39m

all: $(NAME) $(LIBFT) $(PRINTF)

$(NAME): $(TST_O)
	$(COMPILER) $(FLAGS) $(TST_O) -Llibft2/ -lft -Lft_printf -lftprintf -o $(NAME)

$(BONUS): $(BONUS_O)
	$(COMPILER) $(FLAGS) $(BONUS_O) -Llibft2/ -lft -Lft_printf -lftprintf -o $(BONUS)


%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@
	
$(LIBFT):
	@make -C libft/

$(PRINTF):
	@make -C ft_printf/



bonus: $(BONUS)


clean: 
	rm $(TST_O)

fclean:
	rm $(NAME)

re: fclean clean all
		 
ops: ops_test
	./ops_test

main: main_test
	./main_test 2 3 8 10 12   ++14 -23

sort: sort_test
	./test/sort_test.sh

ops_test: $(tst_op) $(libft)
	$(COMPILER) $(FLAGS)  $(TST_OP) -L $(LIBFT) -o ops_test 

main_test: $(TST_INPUT) $(LIBFT)
	$(COMPILER) $(FLAGS) -o main_test $(TST_INPUT) -Llibft/ -lft -o main_test

.PHONY: ops_test main_test all clean fclean re
