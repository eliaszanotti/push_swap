# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 18:32:40 by ezanotti          #+#    #+#              #
#    Updated: 2022/12/28 18:01:41 by elias            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
S_LIB	= ${DIR}ft_isalpha.c ${DIR}ft_isdigit.c ${DIR}ft_isalnum.c \
		${DIR}ft_isascii.c ${DIR}ft_isprint.c ${DIR}ft_strlen.c \
		${DIR}ft_memset.c ${DIR}ft_bzero.c ${DIR}ft_memcpy.c \
		${DIR}ft_memmove.c ${DIR}ft_strlcpy.c ${DIR}ft_strlcat.c \
		${DIR}ft_toupper.c ${DIR}ft_tolower.c ${DIR}ft_strchr.c \
		${DIR}ft_strrchr.c ${DIR}ft_strncmp.c ${DIR}ft_memchr.c \
		${DIR}ft_memcmp.c ${DIR}ft_strnstr.c ${DIR}ft_atoi.c \
		${DIR}ft_calloc.c ${DIR}ft_strdup.c ${DIR}ft_substr.c \
		${DIR}ft_strjoin.c ${DIR}ft_strtrim.c ${DIR}ft_split.c \
		${DIR}ft_itoa.c ${DIR}ft_strmapi.c ${DIR}ft_striteri.c \
		${DIR}ft_putchar_fd.c ${DIR}ft_putstr_fd.c ${DIR}ft_putendl_fd.c \
		${DIR}ft_putnbr_fd.c ${DIR}ft_lstnew.c ${DIR}ft_lstadd_front.c \
		${DIR}ft_lstsize.c ${DIR}ft_lstlast.c ${DIR}ft_lstadd_back.c \
		${DIR}ft_lstdelone.c ${DIR}ft_lstclear.c ${DIR}ft_lstiter.c \
		${DIR}ft_lstmap.c ${DIR}ft_printf.c ${DIR}ft_printf_utils.c

S_SRC	= ${DIR_SRC}main.c ${DIR_SRC}ft_parsing.c ${DIR_SRC}ft_instructions.c \
		${DIR_SRC}ft_sort.c ${DIR_SRC}ft_checker.c ${DIR_SRC}ft_error.c \
		${DIR_SRC}ft_free.c

OBJS	= ${S_LIB:.c=.o} ${S_SRC:.c=.o}

# VARIABLES
NAME	= push_swap
DIR		= libft/
DIR_SRC = srcs/
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# COMPILATION
all :		${NAME}

%.o: %.c	${DIR}ft_printf.h ${DIR}libft.h ${DIR_SRC}push_swap.h
			${CC} ${CFLAGS} -I ${DIR} -I ${DIR_SRC} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME} ${MLX}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME} 

re :		fclean all

.PHONY : all re clean fclean
