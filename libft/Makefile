# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 18:24:42 by yataji            #+#    #+#              #
#    Updated: 2021/04/26 04:45:39 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libft.a

OC= 	ft_atoi.c\
		ft_atoi_base.c\
		ft_bzero.c\
		ft_compt_digit.c\
		ft_lendd.c\
		ft_cpt.c\
		ft_is_negative.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putlst.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_revtab.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_swap.c\
		ft_tolower.c\
		ft_toupper.c\
		get_next_line.c\

HEADER = libft.h

OB = $(addprefix $(OBJ_DIR)/,$(OC:.c=.o))

OBJ_DIR = ./obj

NAME 	= libft.a

CC		= @gcc

all : $(NAME)

$(NAME) : $(OB)
	@ar rc libft.a $(OB)
	@echo "\033[92mDone for libft\033[0m"

$(OBJ_DIR):
	@-mkdir $(OBJ_DIR)

$(OB): $(OBJ_DIR)/%.o : ./%.c $(HEADER) | $(OBJ_DIR)
	@gcc -c  $(INCLUDE) $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
fclean : clean
	@rm -f $(NAME)

norme:
	@norminette $(OC) libft.h

re : fclean all

