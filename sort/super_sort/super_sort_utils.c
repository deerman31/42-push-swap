/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:56:36 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/29 18:04:56 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all_num(t_stack *b, size_t *pivot)
{
	size_t		i;
	size_t		len;
	t_node		*tmp;

	tmp = b->top;
	i = 0;
	len = b->size;
	while (i < len)
	{
		if (tmp->number >= *(pivot - 1) && tmp->number < *pivot)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	check_b_to_a(t_stack *b, size_t max)
{
	t_node		*ntmp;
	t_node		*ptmp;

	if (b->top->number == max || b->top->number == max - 1)
		return (0);
	ntmp = b->top->next;
	ptmp = b->top->prev;
	while (ntmp != b->top)
	{
		if (max == ntmp->number)
			return (1);
		else if (max == ptmp->number)
			return (-1);
		ntmp = ntmp->next;
		ptmp = ptmp->prev;
	}
	return (0);
}
