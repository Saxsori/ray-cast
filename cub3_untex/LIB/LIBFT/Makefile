# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 12:10:20 by aaljaber          #+#    #+#              #
#    Updated: 2022/07/14 00:29:59 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_memset.c ft_split.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = ${SRCS:.c=.o}

BONUS = ft_lstdelone.c ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c

BONOBJ = ${BONUS:.c=.o}

NAME = libft.a

INCS = libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c

RM = rm -f

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} :   ${OBJS}
	ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS} ${BONOBJ}
	
fclean :    clean
	${RM} ${NAME}

bonus: ${OBJS} ${BONOBJ}
	ar rc ${NAME} ${OBJS} ${BONOBJ}

re : fclean all

.PHONY : all .c.o clean fclean re bonus
