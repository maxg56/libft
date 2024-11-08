# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:59:30 by mgendrot          #+#    #+#              #
#    Updated: 2024/11/08 16:28:32 by mgendrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= libft.a
NAMETESTS	= tests.out

INCLUDES	=	include

CC			= cc 
CFLAGS		= -Wall -Wextra -Werror 

RM			= rm
AR			= ar rcs
MKDIR		= mkdir

# **************************************************************************** #
#                                   Colors                                     #
#                                                                              #
# **************************************************************************** #
GRAY = \033[0;90m
RED = \033[0;91m
YELLOW = \033[0;93m
WHITE = \033[0;97m
BOLD=$'\x1b[1m
END=$'\x1b[0m
DEF_COLOR   		=   \033[0;39m
GREEN      			=   \033[0;92m
BLUE        		=   \033[0;94m
CYAN       			=   \033[0;96m
TERM_UP				=	\033[1A
TERM_CLEAR_LINE		=	\033[2K\r
MAGENTA				=	\033[0;95m

# **************************************************************************** #
#                                                                              #
#                                   Sources                                    #
#                                                                              #
# **************************************************************************** #
FTPRINTF_DIR     =   src/ft_printf/
FTPRINT       	=   ft_printf

PRINTERS_FILES_DIR  =  src/ft_printf/ft_print/
PRINTERS_FILES  =   ft_print_c_fd ft_print_d_fd ft_print_x_fd ft_print_s_fd \
					ft_print_p_fd ft_print_u_fd ft_print_pct_fd

FTGNL_DIR	=	src/ft_gnl/
FTGNL		=	get_next_line

FTIS_DIR	=	src/ft_is/
FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR	=	$(SRCS_DIR)/ft_mem/
FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset

FTPUT_DIR	=	$(SRCS_DIR)/ft_put/
FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR	=	$(SRCS_DIR)/ft_to/
FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR	=	$(SRCS_DIR)/ft_str/
FTSTR		=	ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
				ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
				ft_strnstr ft_strrchr ft_strtrim ft_substr

FTLST_DIR	=	$(SRCS_DIR)/ft_lst/
FTLST		=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
				ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

# **************************************************************************** #
#                                                                              #
#                                   OBJS                                       #
#                                                                              #
# **************************************************************************** #
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/

SRCS  += $(addprefix $(FTPRINTF_DIR), $(addsuffix .c, $(FTPRINT)))
SRCS  += $(addprefix $(PRINTERS_FILES_DIR), $(addsuffix .c, $(PRINTERS_FILES)))
SRCS  += $(addprefix $(FTGNL_DIR), $(addsuffix .c, $(FTGNL)))
SRCS  += $(addprefix $(FTIS_DIR), $(addsuffix .c, $(FTIS)))
SRCS  += $(addprefix $(FTPUT_DIR), $(addsuffix .c, $(FTPUT)))
SRCS  += $(addprefix $(FTMEM_DIR), $(addsuffix .c, $(FTMEM)))
SRCS  += $(addprefix $(FTTO_DIR), $(addsuffix .c, $(FTTO)))
SRCS  += $(addprefix $(FTSTR_DIR), $(addsuffix .c, $(FTSTR)))
SRCS  += $(addprefix $(FTLST_DIR), $(addsuffix .c, $(FTLST)))

OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

# **************************************************************************** #
#                                                                              #
#                             progress_update                                  #
#                                                                              #
# **************************************************************************** #
TOTAL_FILES     =   $(words $(SRCS))
COMPILED_COUNT  =   0

define progress_update
	printf "$(TERM_UP)"; \
	$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT)+1)))) ; \
	printf "$(TERM_CLEAR_LINE)$(CYAN)Compilation progress: $$(($(COMPILED_COUNT) * 100 / $(TOTAL_FILES))) %% $(YELLOW)$< $(DEF_COLOR)\n"
endef

# **************************************************************************** #
#                                                                              #
#                       \__                                                    #
#                                                                              #
# **************************************************************************** #
OBJSF		=	.cache_exists

all:		${NAME}

${NAME}:	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@echo -e "$(GREEN)$(BOLD)Libft compiled!$(END)$(DEF_COLOR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@mkdir -p $(dir $@)
			@$(progress_update)
			@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)
			@echo -e "$(BLUE)libft objects files cleaned!$(DEF_COLOR)"

fclean:		clean
			@${RM} -f ${NAME}
			@echo -e "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo -e "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

tests: allSRC_DIR