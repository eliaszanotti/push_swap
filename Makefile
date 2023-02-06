# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:45:24 by ezanotti          #+#    #+#              #
#    Updated: 2023/02/06 20:04:05 by ezanotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_SRC	= main.c					\
		${D_PRT}ft_printf.c			\
		${D_PRT}ft_printf_utils.c	\
		${D_UTILS}ft_stack_utils.c	\



S_TMP	= ${addprefix ${D_SRC}, ${S_SRC}}
O_SRC	= $(patsubst %.c, ${D_OBJS}%.o, $(S_TMP))

# VARIABLES
NAME	= push_swap
CC		= cc

# FLAGS
MAKEFLAGS += --no-print-directory
CFLAGS	= -Wall -Wextra -Werror -g3
LIBFT 	= -L ./libft -lft 

# COMMANDS
RM		= rm -rf
PRINT	= @printf

# DIRECTORIES
D_OBJS	= .objs/
D_INC	= includes/
D_LIB	= libft/
D_UTILS	= utils/
D_PRT	= printf/
D_SRC	= srcs/

# COLORS
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
DEFAULT	= \033[0m
SUPPR	= \r\033[2K

all:	${NAME}

${D_OBJS}%.o: %.c	${D_INC}push_swap.h Makefile
		@mkdir -p $(shell dirname $@)
		@${PRINT} "${YELLOW}${SUPPR}Creating ${NAME}'s objects : $@"
		@${CC} ${CFLAGS} -I ${D_LIB} -I ${D_INC} -c $< -o $@ 

${NAME}:ascii lib ${O_SRC}
		@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\n"
		@${PRINT} "${YELLOW}Compiling ${NAME}...${DEFAULT}"
		@${CC} ${O_SRC} -o ${NAME} ${LIBFT}
		@${PRINT} "${GREEN}${SUPPR}Compiling ${NAME} : DONE ${DEFAULT}\n\n"

lib:
		@make -C ./libft

ascii:
		@${PRINT} "$$ASCII\n"

clean:	ascii
		@${PRINT} "${RED}Deleting objects : DONE\n"
		@${RM} ${D_OBJS}

fclean:	clean 
		@${PRINT} "${RED}Cleaning libft : DONE\n"
		@${MAKE} fclean -C ./libft
		@${PRINT} "${RED}Deleting executable : DONE${DEFAULT}\n\n"
		@${RM} ${NAME}

re:		fclean all

define ASCII 
${CYAN} _____ _____ _____ _____       _____ _ _ _ _____ _____
|  _  |  |  |   __|  |  |_____|   __| | | |  _  |  _  |
|   __|  |  |__   |     |_____|__   | | | |     |   __|
|__|  |_____|_____|__|__|     |_____|_____|__|__|__|
${DEFAULT}
endef

export	ASCII

.PHONY:	all re clean fclean lib ascii
