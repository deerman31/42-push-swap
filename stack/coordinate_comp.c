/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_comp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:26:53 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/27 14:48:26 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_generation(t_stack *s)
{
	size_t		i;
	t_node		*tmp;
	int			max;

	tmp = s->top;
	i = 0;
	max = INT_MIN;
	while (i < s->size)
	{
		if (tmp->number == 0 && max < tmp->value)
			max = tmp->value;
		i++;
		tmp = tmp->next;
	}
	return (max);
}

static void	max_cmp(t_stack *stack, size_t c)
{
	size_t		i;
	t_node		*tmp;
	int			max;

	tmp = stack->top;
	max = max_generation(stack);
	i = 0;
	while (i < stack->size)
	{
		tmp = tmp->next;
		if (tmp->number == 0 && max == tmp->value)
		{
			tmp->number = stack->size - c;
			return ;
		}
		i++;
	}
}

void	coordinate_comp(t_stack *stack)
{
	size_t		i;

	i = 1;
	while (i < stack->size)
	{
		max_cmp(stack, i);
		i++;
	}
}
