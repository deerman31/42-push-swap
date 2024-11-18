/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:34:12 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/22 06:04:24 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	size_t		i;
	t_node		*tmp;

	if (stack->size == 0)
		return (1);
	i = 1;
	tmp = stack->top;
	while (i < stack->size)
	{
		if (tmp->value >= tmp->next->value)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
