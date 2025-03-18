# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 14:23:25 by francesca         #+#    #+#              #
#    Updated: 2025/03/18 14:53:31 by fmontini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME	=	push_swap

# Source files (add your files from src/ here)
SRC	=	push_swap.c \
		ft_create_node.c \
		ft_create_stack.c \
		ft_exit.c \
		ft_swap.c \
		ft_push.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		ft_check_inputvalue.c \

# adds the src/ prefix to files in SRC
SRC	:= $(addprefix src/, $(SRC))

# .c to .o compilation
OBJ	=	$(SRC:.c=.o)

# compilation flags
CFLAGS	=  -Wall -Werror -Wextra 

# Libft
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Printf
FT_PRINTF_DIR = Printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

# Rules
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	cc -o $(NAME) $(OBJ) $(LIBFT) $(CFLAGS) $(FT_PRINTF)

# Esegui il Makefile di libft
$(LIBFT):
	@make -C $(LIBFT_DIR)
# Esegui Makefile di ft_printf
$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

all:	$(NAME)

clean:
	rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)

fclean:	clean
	rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)

re:	fclean all 
	rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	
.PHONY : all bonus clean fclean re