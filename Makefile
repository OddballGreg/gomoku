# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 11:16:22 by ggroener          #+#    #+#              #
#    Updated: 2016/11/28 13:40:28 by khansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gomoku

CFLAGS =	-Wno-deprecated-declarations -Wall -Wextra -Werror -g -g3 -O3

#LINUX
CFLAGS2 = 	-g -g3 -lpanel -lcurses -O3

#MAC
#CFLAGS2 =	-framework OpenGL -framework GLUT -Wno-deprecated-declarations \
			-g -Ofast -ltpanel -lcurses

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = ai.c					\
			draw_grid.c				\
			draw_win.c				\
			exit_prog.c				\
			heuristic.c				\
			init.c					\
			main.c					\
			manage_ui.c				\
			manage_wins.c			\
			options.c				\
			signals.c				\
			validate_move.c			\
			win_checks.c			\

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

#uncomment these to work on Mac and comment to work on Linux.
#LIBRARY = -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

#INCLUDES = -I includes/ -I libft/includes

#uncomment these to work on Linux and comment to work on Mac.
#LIBRARY = -L /usr/X11/lib -lmlx -lX11 -lm -lXext -L libft/ -lft
LIBRARY = -L libft/ -lft
#INCLUDES = -I includes/ -I libft/includes -I /usr/X11/include
INCLUDES = -I includes -I libft/includes

HEADER = 	$(INCLUDES_PATH)gomoku.h	\

all: qme odir $(NAME)

define colourecho
	@tput setaf 14
	@echo $1
	@tput sgr0
endef

define colourecho2
	@tput setaf 2
	@echo $1
	@tput sgr0
endef

$(NAME): $(OBJS)
#	@Make -C libft
	@$(call colourecho, " - Making $(NAME)")
	@clear
	@$(CC) $(CFLAGS2) -o $(NAME) $^ $(LIBRARY) $(INCLUDES) -I$(INCLUDES_PATH)
	@clear
	@$(call colourecho, "Make Done!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -I$(INCLUDES_PATH)
	@$(call colourecho, "Compiling Done!")

odir:
	@mkdir -p $(OBJS_PATH)

clean:
#	@Make clean -C libft
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@$(call colourecho, "clean done!")

fclean: clean
#	@Make fclean -C libft
	@$(call colourecho, "Clearing executable files")
	@rm -f $(NAME)
	@$(call colourecho, "fclean done")

re: fclean all
	@$(call colourecho, "re Done!")

format: norme me

norme: norm

norm:
	@clear
	@$(call colourecho2, "Norminette:")
	@norminette $(SRCS)
	@norminette $(HEADER)

fnorm: fnorme

fnorme:
	@clear
	@$(call colourecho2, "Norminette:")
	@find ./srcs -name "*.c" -maxdepth 1 -type f -exec norminette  {} \;
	@find ./includes -name "*.h" -maxdepth 1 -type f -exec norminette  {} \;

qme:
	@if [ ! -f author ]; then \
		whoami > author; \
	fi
	
me: qme
	cat -e author

submodule:
	@$(call colourecho, "Checking Submodules...")
	@if [ ! -d libft/includes ]; then \
		git submodule init libft; \
		git submodule update; \
	fi;
	@$(call colourecho, "done checking submodules")

.PHONY: clean fclean re odir