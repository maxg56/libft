#Standard

NAME		= libft.a
NAMETESTS	= tests.out

INCLUDES	=	include
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/

CC			= cc 
CFLAGS		= -Wall -Wextra -Werror -I

RM			= rm
AR			= ar rcs
MKDIR		= mkdir
#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
BOLD=$'\x1b[1m
END=$'\x1b[0m

#Sources

FTIS_DIR	=	ft_is/
FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR	=	ft_mem/
FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset

FTPUT_DIR	=	ft_put/
FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR	=	ft_to/
FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR	=	ft_str/
FTSTR		=	ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr

FTLST_DIR	=	ft_lst/
FTLST		=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
				ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

SRC_FILES  += $(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES  += $(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES  += $(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES  += $(addprefix $(FTTO_DIR),$(FTTO))
SRC_FILES  += $(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES  += $(addprefix $(FTLST_DIR),$(FTLST))
OBJDIR		= obj

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

#_______________________#

OBJSF		=	.cache_exists

all:		${NAME}

${NAME}:	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@echo -e "$(GREEN)$(BOLD)Libft compiled!$(END)$(DEF_COLOR)"


$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@mkdir -p $(dir $@)
			@echo -e "$(YELLOW)Compiling: $< $(DEF_COLOR)\n"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJSF):

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)
			@echo -e "$(BLUE)libft objects files cleaned!$(DEF_COLOR)"

fclean:		clean
			@${RM} -f ${NAME}
			@echo -e "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo -e "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"


tests:		all
			 @${CC} ${CFLAGS} tests/.tests.c tests/main.c -L . -l ft  -o ${NAMETESTS}
			 @echo -e "$(GREEN)$(BOLD)tests compiled!$(END)$(DEF_COLOR)""
			 ./${NAMETESTS}
			 @rm -f ${NAMETESTS}
			
.PHONY:		all clean fclean re  tests 