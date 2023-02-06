# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 17:58:08 by ezanotti          #+#    #+#              #
#    Updated: 2023/02/06 15:19:39 by ezanotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_LIB	= ft_isalpha.c ft_isdigit.c ft_isalnum.c 			\
		ft_isascii.c ft_isprint.c ft_strlen.c				\
		ft_memset.c ft_bzero.c ft_memcpy.c 				\
		ft_memmove.c ft_strcmp.c ft_strlcpy.c 			\
		ft_toupper.c ft_tolower.c ft_strchr.c 			\
		ft_strrchr.c ft_strncmp.c ft_memchr.c 			\
		ft_memcmp.c ft_strnstr.c ft_atoi.c 				\
		ft_calloc.c ft_strdup.c ft_substr.c 				\
		ft_strjoin.c ft_strtrim.c ft_split.c 				\
		ft_itoa.c ft_strmapi.c ft_striteri.c 				\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c 	\
		ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c 		\
		ft_lstsize.c ft_lstlast.c ft_lstadd_back.c 		\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c 		\
		ft_lstmap.c ft_strlcat.c 

D_OBJS	= .objs/
OBJS	= $(patsubst %.c, $(D_OBJS)%.o, $(S_LIB))

# VARIABLES
NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
PRINT	= @printf

all:		${NAME}

${D_OBJS}%.o: %.c libft.h Makefile
			@mkdir -p $(shell dirname $@)
			@${PRINT} "${YELLOW}${SUPPR}Creating ${NAME}'s objects : $@"
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\n"
			@${PRINT} "${YELLOW}Compiling ${NAME}... ${DEFAULT}"
			@ar rc ${NAME} ${OBJS}
			@${PRINT} "${GREEN}${SUPPR}Compiling ${NAME} : DONE ${DEFAULT}\n"

clean:
			@${RM} ${D_OBJS}

fclean:		clean
			@${RM} ${NAME} 

re:			fclean all

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
DEFAULT		= \033[0m
SUPPR		= \r\033[2K
MAKEFLAGS	+= --no-print-directory

.PHONY:		all re clean fclean
