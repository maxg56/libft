
SCRS		= ft_isdigit.c   ft_isalpha.c    ft_isascii.c   ft_isprint.c  ft_memchr.c     \
			  ft_strlen.c    ft_atoi.c       ft_bzero.c     ft_calloc.c   ft_strdup.c     \
			  ft_memcmp.c    ft_memmove.c    ft_memset.c    ft_strchr.c   ft_strlcat.c    \
			  ft_memcpy.c    ft_strnstr.c    ft_toupper.c   ft_isalnum.c  ft_strrchr.c    \
			  ft_strlcpy.c   ft_tolower.c    ft_substr.c    ft_strjoin.c  ft_split.c      \
			  ft_strtrim.c   ft_itoa.c       ft_strmapi.c   ft_striteri.c ft_putchar_fd.c \
			  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strncmp.c


OBJS		= ${SCRS:.c=.o}

BONUS		= ft_lstnew_bons.c  ft_lstadd_fron_bons.c ft_lstsize_bons.c   \
			  ft_lstlast_bons.c ft_lstdelone_bons.c   ft_lstclear_bons.c  \
			  ft_lstiter_bons.c ft_lstmap_bons.c 	  ft_lstadd_back_bons.c 


BONUS_OBJS	= ${BONUS:.c=.o}

NAME		= libft.a
NAMETESTS	= tests.out	

CC			= cc 
CFLAGS		= -Wall -Wextra -Werror -g -Og

all:		${NAME}

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@ -I libft.h

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

bonus :		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $^

tests:		all
			${CC} ${CFLAGS} .tests.c -L . -l ft  -o ${NAMETESTS}
			./${NAMETESTS}
			rm -f ${NAMETESTS}
			
.PHONY:		all clean fclean re bonus tests 