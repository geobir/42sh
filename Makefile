#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/15 04:58:45 by gbir              #+#    #+#              #
#    Updated: 2014/06/25 18:20:44 by gbir             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	42sh
CC		=	cc
DEBUG	=	no
CLEAR	=	no
LAUNCH	=	no
ARGS	=	
SDIR	=	srcs
ODIR	=	obj

FUNFILE	=	ft_putstr			ft_strclen			ft_putchar			\
			ft_strlen			ft_putnbr			ft_isdigit			\
			ft_isalpha			ft_isalnum			ft_iswhispa			\
			ft_strjoin			ft_strcmp			ft_strsplit			\
			ft_strncmp			ft_strndup			ft_strdup

BUILFILE=	built_cd			built_exit			built_env			\
			built_unsetenv		built_setenv

FILES	=	$(FUNFILE)			$(BUILFILE)			\
			main				g_n_l				iscmd				\
			searchcmd			isbuiltins			builtins			\
			mainshell			makeenv				error				\
			prompt				split_operator		takeenv

IDIR	=	inc

SRCS	=	$(addsuffix .c, $(addprefix $(SDIR)/, $(FILES)))
OBJS	=	$(addsuffix .o, $(FILES))

ifeq ($(DEBUG),yes)
	CFLAGS	?=	-Wall -Werror -Wextra -g
else
	CFLAGS	=	-Wall -Werror -Wextra
endif

all:		clear CREATDIR $(NAME) launch

try:
			echo $(IDIR)

$(NAME):	$(addprefix $(ODIR)/, $(OBJS))
			$(CC) -o $@ $^ -I$(IDIR) $(CFLAGS)

$(ODIR)/%.o:$(SDIR)/%.c
			@$(CC) -c $< -o $@ -I$(IDIR) $(CFLAGS)
			@echo "$^ => \033[32m$@\033[0m"

CREATDIR:
			@mkdir -p $(ODIR)

clear:
ifeq ($(CLEAR),yes)
			@clear
endif

launch:
ifeq ($(LAUNCH),yes)
			@echo "===================== \033[32m$(NAME)\033[0m ====================="
			@./$(NAME) $(ARGS)
endif

norme:		clear
			norminette $(IDIR)/* $(SDIR)/*

clean:
			rm -f $(addprefix $(ODIR)/, $(OBJS))

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
