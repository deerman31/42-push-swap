/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:56:04 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/01 18:11:52 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	node_add(t_stack *stack, int value)
{
	t_node		*node;

	node = create_node(value);
	if (node == NULL)
		return (-1);
	if (stack->top == NULL)
		stack->top = node;
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
	return (1);
}

int	add(t_stack *stack, int argc, char **argv)
{
	size_t		i;
	size_t		len;
	char		**strs;

	if (argc == 1)
	{
		strs = ft_split(argv[0], ' ');
		if (strs == NULL)
			return (-1);
	}
	else
		strs = argv;
	i = 0;
	len = split_count(strs);
	while (i < len)
	{
		if (node_add(stack, ft_atoi(strs[len - i - 1])) == -1)
			return (-1);
		i++;
	}
	coordinate_comp(stack);
	if (argc == 1)
		all_free(strs);
	return (1);
}
