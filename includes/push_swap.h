/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:55:44 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/29 19:56:02 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include <stdlib.h>

# define SIGN "+-"
# define ERROR "Error"
# define MALLOC_E "Malloc Error"

typedef struct s_node
{
	int				value;
	size_t			number;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node		*top;
	size_t		size;
	char		type;
}				t_stack;

// sort
void		decision_sort(t_stack *a, t_stack *b);
int			check_sort(t_stack *stack);
void		three_below(t_stack *stack);
void		six_below(t_stack *a, t_stack *b);
void		coordinate_comp(t_stack *stack);
size_t		base_convert(size_t n, size_t base);
// super_sort
void		super_sort(t_stack *a, t_stack *b);
int			check_all_num(t_stack *b, size_t *pivot);
int			check_b_to_a(t_stack *b, size_t max);
// stack
int			add(t_stack *stack, int argc, char **argv);
t_stack		*create_stack(char type);
int			pop(t_stack *stack);
t_node		*create_node(int value);
void		s_n_free(t_stack *a, t_stack *b);
void		coordinate_comp(t_stack *stack);

// operation
int			swap(t_stack *stack);
int			push(t_stack *active, t_stack *passive);
int			rotate(t_stack *stack);
int			reverse_rotate(t_stack *stack);
int			swap_ss(t_stack *a, t_stack *b);
int			rotate_rr(t_stack *a, t_stack *b);
int			reverse_rotate_rr(t_stack *a, t_stack *b);
int			ope_print(int sign, char type);

//error
int			check_error(char **str, size_t elem);
int			quotation2_error_check(char **argv);
void		error_show(int sign);
char		**all_free(char **strs);
size_t		split_count(char **strs);
//print
void		print_stack(t_stack *stack);

#endif
