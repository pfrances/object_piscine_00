# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pierre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 12:19:16 by pierre            #+#    #+#              #
#    Updated: 2024/09/24 15:41:00 by pierre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = divide_and_conquer
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -pedantic -std=c++98
INCLUDE = -I includes

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
SRCS = $(addprefix $(SRCS_DIR)/,	main.cpp			\
									BankAccount.cpp		\
									Bank.cpp)
OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CXXFLAGS += -g -fsanitize=address
debug: re

.PHONY: all clean fclean re debug

-include $(DEPS)