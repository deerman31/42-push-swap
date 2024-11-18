/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_below.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:09:59 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/22 18:07:47 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ago_back_judge(t_stack *s)
{
	t_node		*tmp;
	int			flag;
	size_t		i;
	size_t		pivot;

	if (s->size == 4)
		pivot = 2;
	else
		pivot = 3;
	tmp = s->top;
	i = 0;
	while (i < s->size)
	{
		if (0 == tmp->number)
			return (i);
		tmp = tmp->next;
		i++;
	}
	flag = 0;
	if (i > pivot)
		flag = 1;
	return (flag);
}

static void	min_push(t_stack *a, t_stack *b)
{
	size_t		i;
	size_t		len;
	int			flag;

	i = 0;
	len = a->size - 3;
	flag = ago_back_judge(a);
	while (i < len)
	{
		if (check_sort(a) == 1)
			break ;
		if (i == a->top->number)
		{
			ope_print(push(b, a), b->type);
			i++;
		}
		else
		{
			if (flag == 1)
				ope_print(rotate(a), a->type);
			else
				ope_print(reverse_rotate(a), a->type);
		}
	}
	three_below(a);
}

void	six_below(t_stack *a, t_stack *b)
{
	min_push(a, b);
	while (b->top != NULL)
		ope_print(push(a, b), a->type);
}
