##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## processes compilation for this lib
##

SRC	=	./my_putchar.c				\
		./my_isnum.c				\
		./my_isalpha.c				\
		./my_isalphanum.c			\
		./my_str_is_alphanum.c		\
		./my_int_size.c				\
		./my_strlen.c				\
		./my_strnlen.c				\
		./my_strlen_char.c			\
		./my_strlen_cmpstr.c		\
		./my_arrdup.c				\
		./my_append_to_array.c		\
		./my_arrlen.c				\
		./my_show_arr.c				\
		./my_free_arr.c				\
		./my_putstr.c				\
		./my_getnbr.c				\
		./my_put_nbr.c				\
		./my_put_nbr_u.c			\
		./my_put_nbr_s.c			\
		./my_put_nbr_su.c			\
		./my_put_nbr_l.c			\
		./my_put_nbr_ll.c			\
		./my_put_nbr_lu.c			\
		./my_put_nbr_llu.c			\
		./my_arrcmp.c				\
		./my_strcmp.c				\
		./my_strncmp.c				\
		./my_strdup.c				\
		./my_strndup.c				\
		./my_strdup_char.c			\
		./my_strdup_cmpstr.c		\
		./my_strcat.c				\
		./my_str_to_word_array.c	\
		./find_char_in_str.c		\
		./get_next_line.c			\
		./my_radians.c

SRCMYPRINTF	=	./my_printf/my_printf.c				\
				./my_printf/flag_checkers.c			\
				./my_printf/get_flag.c				\
				./my_printf/create_flag_array.c		\
				./my_printf/redirect_putchar.c		\
				./my_printf/redirect_put_nbr.c		\
				./my_printf/redirect_short.c		\
				./my_printf/redirect_long.c			\
				./my_printf/redirect_percent.c		\
				./my_printf/redirect_lower_upper.c	\
				./my_printf/redirect_hashtag.c		\
				./my_printf/redirect_add_ptr.c		\
				./my_printf/my_flag_cmp.c

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./../../include/

OBJ	=	$(SRC:.c=.o) $(SRCMYPRINTF:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ) -lm
	cp $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.NOTPARALLEL:
.PHONY: all clean fclean re