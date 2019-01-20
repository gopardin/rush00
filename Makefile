# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/12 13:25:54 by vsokolog          #+#    #+#              #
#    Updated: 2019/01/20 14:40:11 by ailkiv           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC := clang++

FLAGS := -Wall -Wextra -Werror -g 
HEADERS := 
INCLUDES :=	.
HFILES = $(patsubst %, $(INCLUDES)/%.hpp, $(HEADERS))

source_dirs := .

RM := rm -rf

search_wildcards := $(addsuffix /*.cpp, $(source_dirs))

OBJ = $(notdir $(patsubst %.cpp, %.o, $(wildcard $(search_wildcards))))

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) -o $@ $(OBJ) -lncurses

VPATH := $(source_dirs)

%.o: %.cpp $(HFILES)
	$(CC) -I $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

.PHONY: clean fclean re all
