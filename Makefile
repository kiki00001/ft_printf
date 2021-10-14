# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 10:42:23 by heahn             #+#    #+#              #
#    Updated: 2021/10/15 03:54:19 by heahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_print_type.c ft_utils.c ft_utils2.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

RM	= rm -rf
LIB = ar rcu
cc = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	@echo "==COMPILE $(NAME)=="
	@$(cc) $(CFLAGS) -c $(SRCS)
	@$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)

all	: $(NAME)

clean : 
	@echo "==REMOVE OBJECT FILE=="
	@$(RM) $(OBJS)

fclean : clean
	@echo "==REMOVE $(NAME)=="	
	@$(RM) $(NAME)

re : fclean all
