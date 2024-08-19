PROG    = so_long

SRCS    =	so_long.c checkmap.c \
			checkmap2.c \
			frees.c \
			gamestart.c \
			hooks.c \
			hooks2.c

OBJS     = ${SRCS:.c=.o}
MAIN    = so_long.c

HEADER    = -Iinclude

CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -g

.c.o:	%.o : %.c
	@gcc ${CFLAGS} -Imlx -c $< -o $(<:.c=.o)

all:         ${PROG}

${PROG}:    ${OBJS}
						@echo "\033[33m----Compiling lib----"
						@make -C mlx/
						@make -C libft/
						@$(CC) ${OBJS} -lmlx -lXext -lX11 -L mlx -o${PROG} libft/libft.a
						@echo "\033[32mSo Long Compiled!\n"

clean:
						@rm -f ${OBJS}


fclean:     clean
						@rm -f $(NAME)
						@rm -f ${PROG}
						@echo "\n\033[31mDeleting EVERYTHING!\n"

git:
	git add .
	git commit -m "update"
	git push

re:            fclean all

.PHONY: all clean fclean re