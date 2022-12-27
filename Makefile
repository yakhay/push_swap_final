NAME = push_swap
SRC = test3.c test4.c main.c ft_pushswap.c push_swap_function.c ft_push_swap.c function.c
BONUS			= ./Get_Next_Line/get_next_line_utils.c ./Get_Next_Line/get_next_line.c checker.c  function.c test3.c ft_chek.c ft_ss_rr_rrr.c
CFLAGS			= -Wall -Wextra -Werror
all : $(SRC)
	gcc $(CFLAGS) $(SRC) ./libft/libft.a -o $(NAME) 

NAME2 = checker
bonus: $(SRC)
	gcc $(CFLAGS) $(BONUS) ./libft/libft.a -o $(NAME2) 
clean:
				rm $(NAME)

fclean:			clean
				

re:				fclean all