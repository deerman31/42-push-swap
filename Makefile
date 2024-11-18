# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 22:03:50 by ykusano           #+#    #+#              #
#    Updated: 2023/03/27 02:59:26by ykusano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

CFLAGS := -Wall -Wextra -Werror

AR := ar rcs

RM := rm -f

NAME := push_swap

INC := -I ./includes

SRCS := ./ft_printf/libft/ft_isalpha.c ft_printf/libft/ft_isdigit.c ft_printf/libft/ft_isalnum.c ft_printf/libft/ft_isascii.c ft_printf/libft/ft_isprint.c ft_printf/libft/ft_strlen.c ft_printf/libft/ft_memset.c ft_printf/libft/ft_bzero.c ft_printf/libft/ft_memcpy.c ft_printf/libft/ft_memmove.c ft_printf/libft/ft_strlcpy.c ft_printf/libft/ft_strlcat.c ft_printf/libft/ft_toupper.c ft_printf/libft/ft_tolower.c ft_printf/libft/ft_strchr.c ft_printf/libft/ft_strrchr.c ft_printf/libft/ft_strncmp.c ft_printf/libft/ft_memchr.c ft_printf/libft/ft_memcmp.c ft_printf/libft/ft_strnstr.c ft_printf/libft/ft_atoi.c ft_printf/libft/ft_calloc.c ft_printf/libft/ft_strdup.c ft_printf/libft/ft_substr.c ft_printf/libft/ft_strjoin.c ft_printf/libft/ft_strtrim.c ft_printf/libft/ft_split.c ft_printf/libft/ft_itoa.c ft_printf/libft/ft_strmapi.c ft_printf/libft/ft_striteri.c ft_printf/libft/ft_putchar_fd.c ft_printf/libft/ft_putstr_fd.c ft_printf/libft/ft_putendl_fd.c ft_printf/libft/ft_putnbr_fd.c ft_printf/libft/ft_lstnew.c ft_printf/libft/ft_lstadd_front.c ft_printf/libft/ft_lstsize.c ft_printf/libft/ft_lstlast.c ft_printf/libft/ft_lstadd_back.c ft_printf/libft/ft_lstdelone.c ft_printf/libft/ft_lstclear.c ft_printf/libft/ft_lstiter.c ft_printf/libft/ft_lstmap.c \
ft_printf/printf/ft_printf.c ft_printf/printf/all_print.c ft_printf/printf/convert_hexadecimal.c ft_printf/printf/diu_putnbr.c \
push_swap_main.c \
stack/add.c stack/coordinate_comp.c stack/create_node.c stack/create_stack.c stack/pop.c stack/s_n_free.c \
operation/ope_print.c operation/push.c operation/reverse_rotate_rrr.c operation/reverse_rotate.c operation/rotate_rr.c operation/rotate.c operation/swap_ss.c operation/swap.c \
error/check_error.c error/error_show.c error/quotation2_error_check.c \
sort/check_sort.c sort/decision_sort.c sort/six_below.c sort/three_below.c \
sort/super_sort/super_sort.c sort/super_sort/super_sort_utils.c \
stack/print_stack.c \

OBJS := $(SRCS:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re