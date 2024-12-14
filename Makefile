# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:59:30 by mgendrot          #+#    #+#              #
#    Updated: 2024/12/15 00:11:03 by mgendrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= libft.a
NAMETESTS	= tests.out

INCLUDES	=	include

CC			= cc 
CFLAGS		= -Wall -Wextra -Werror -I $(INCLUDES)

RM 			= rm -f
AR			= ar rcs
MKDIR		= mkdir

# **************************************************************************** #
#                                   Colors                                     #                                                                            #
# **************************************************************************** #
DEF_COLOR   		=   \033[0;39m
GRAY 				=   \033[0;90m
RED 				=   \033[0;91m
GREEN      			=   \033[0;92m
YELLOW 				=   \033[0;93m
BLUE        		=   \033[0;94m
MAGENTA				=	\033[0;95m
CYAN       			=   \033[0;96m
WHITE 				=   \033[0;97m
BOLD 				=   $'\x1b[1m'
END 				=   $'\x1b[0m'
TERM_UP				=   \033[1A
TERM_CLEAR_LINE		=   \033[2K\r

# **************************************************************************** #
#                                   Sources                                    #
# **************************************************************************** #

FTPRINTF_DIR     =  ft_printf/
FTPRINT       	=   ft_printf ft_print_c_fd ft_print_d_fd ft_print_x_fd \
					ft_print_s_fd ft_print_p_fd ft_print_u_fd ft_print_pct_fd \
					ft_dprintf

FTGNL_DIR	=	ft_gnl/
FTGNL		=	get_next_line

FTIS_DIR	=	ft_is/
FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR	=	ft_mem/
FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset \
				ft_memcpy ft_arna

FTPUT_DIR	=	ft_put/
FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR	=	ft_to/
FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper ft_atol

FTSTR_DIR	=	ft_str/
FTSTR		=	ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr ft_strlcpy \
				ft_strcmp ft_strjoin3

FTLST_DIR	=	ft_lst/
FTLST		=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
				ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

# **************************************************************************** #
#                                   OBJS                                       #
# **************************************************************************** #

SRCS_DIR        = src/
OBJ_DIR         = obj/

SRC_FILES       = $(addprefix $(FTPRINTF_DIR),$(FTPRINT)) $(addprefix $(FTGNL_DIR),$(FTGNL)) \
                  $(addprefix $(FTIS_DIR),$(FTIS)) $(addprefix $(FTPUT_DIR),$(FTPUT)) \
                  $(addprefix $(FTMEM_DIR),$(FTMEM)) $(addprefix $(FTTO_DIR),$(FTTO)) \
                  $(addprefix $(FTSTR_DIR),$(FTSTR)) $(addprefix $(FTLST_DIR),$(FTLST))

SRCS            = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS            = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS            = $(OBJ:.o=.d)

# **************************************************************************** #
#                             progress_update                                  #
# **************************************************************************** #

TOTAL_FILES := $(words $(SRCS))


define progress_update
    @if [ ! -f .compiled_count ]; then \
        echo 0 > .compiled_count; \
		printf "\n";\
    fi; \
    COMPILED_COUNT=$$(cat .compiled_count); \
    COMPILED_COUNT=$$((COMPILED_COUNT + 1)); \
    echo $$COMPILED_COUNT > .compiled_count; \
    printf "$(TERM_UP)$(TERM_CLEAR_LINE)$(CYAN)Compilation progress: \
        $$((COMPILED_COUNT * 100 / $(TOTAL_FILES)))%% $(BLUE) -> $(1) $(DEF_COLOR)\n"; \
    if [ $$COMPILED_COUNT -eq $(TOTAL_FILES) ]; then \
        rm -f .compiled_count; \
    fi
endef

# **************************************************************************** #
#                                                                              #
#                                                                              #
#                                                                              #
# **************************************************************************** #

all:	$(NAME)

$(NAME): $(OBJS)
	@${AR} ${NAME} ${OBJS} || exit 1
	@printf "$(GREEN)Libft compiled!$(DEF_COLOR)\n"
	
$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(call progress_update,$(notdir $@ ))
	@$(CC) $(CFLAGS) -c $< -o $@ || exit 1

include $(DEPS)

%.d: %.c
	@$(CC) $(CFLAGS) -MM $< -MF $@ -s

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		$(RM) -r $(OBJ_DIR); \
		printf "$(RED)libft object files cleaned!$(DEF_COLOR)\n"; \
	fi

fclean:	clean
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		printf "$(CYAN)libft executable cleaned!$(DEF_COLOR)\n"; \
	fi
	@if [ -f .compiled_count ]; then \
			rm -f .compiled_count; \
	fi;
		
re:	fclean all
	@printf  "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)\n"

tests:	all
	@${CC} ${CFLAGS} tests/.tests.c tests/main.c -L . -l ft  -o ${NAMETESTS}
	@printf -e "$(GREEN)$(BOLD)tests compiled!$(END)$(DEF_COLOR)/n"
	./${NAMETESTS}
	@rm -f ${NAMETESTS}

norm:
	@norminette $(SRCS) $(INCLUDE) | grep -v Norme -B1 || true
	
.PHONY:		all clean fclean re  tests norm