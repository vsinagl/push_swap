#test for operations functions and linked list functions
TST_OP:= project/ops1.c\
		 project/list.c\
		 test/list%ops_test.c\
		 test/utils_test.c\

TST_INPUT:= project/ops1.c\
			project/list.c\
			project/main.c\
			test/utils_test.c\

TST:=	project/ops1.c\
		project/list.c\
		project/main.c\
		project/sort.c\
		project/sort2.c\
		project/utils1.c\
		project/utils2.c\
		project/utils3.c\
		project/middleway.c\
		test/utils_test.c\

TST_O:= $(TST:.c=.o)
			
#external libraries
LIBFT:= libft/libft.a
PRINTF:= ft_printf/printf.a

#compiler instructions:
COMPILER:= clang
FLAGS:= -Wall -Wextra -Werror


#test for operations and linked list functions
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

sort_test: $(LIBFT) $(PRINTF)
	$(COMPILER) $(FLAGS) $(TST) -Llibft/ -Llibft/  -Lftprintf -lft ft_printf/libftprintf.a -o push_swap
	#$(COMPILER) $(FLAGS) -c $(TST) -Llibft/ -lft -o mini_sort_test

	
#$(TST_O): $(TST)
#	$(COMPILER) $(FLAGS) -c $(TST)

$(LIBFT):
	make -C libft/

$(PRINTF):
	make -C ft_printf/

.PHONY: ops_test main_test

		 
