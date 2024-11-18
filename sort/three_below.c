/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_below.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:29:18 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/22 06:05:31 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_judgment(t_stack *s)
{
	size_t		num[3];

	num[0] = s->top->number;
	num[1] = s->top->next->number;
	num[2] = s->top->next->next->number;
	if (num[1] < num[0] && num[0] < num[2])
		ope_print(swap(s), s->type);
	else if (num[2] < num[1] && num[1] < num[0])
	{
		ope_print(swap(s), s->type);
		ope_print(reverse_rotate(s), s->type);
	}
	else if (num[1] < num[2] && num[2] < num[0])
		ope_print(rotate(s), s->type);
	else if (num[0] < num[2] && num[2] < num[1])
	{
		ope_print(swap(s), s->type);
		ope_print(rotate(s), s->type);
	}
	else if (num[2] < num[0] && num[0] < num[1])
		ope_print(reverse_rotate(s), s->type);
}

void	three_below(t_stack *s)
{
	if (check_sort(s) == 1)
		return ;
	if (s->size < 3)
		ope_print(swap(s), s->type);
	else
		three_judgment(s);
}
