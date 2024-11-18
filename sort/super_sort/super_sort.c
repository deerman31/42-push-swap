/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:07:32 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/29 19:33:40 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	max_stack(t_stack *b)
{
	t_node		*tmp;
	t_node		*top;
	size_t		max;

	if (b->top == NULL)
		return (0);
	tmp = b->top->next;
	top = b->top;
	max = b->top->number;
	while (tmp != top)
	{
		if (max < tmp->number)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

static void	b_to_a(t_stack *a, t_stack *b, size_t *pivot, size_t len)
{
	size_t		i;

	i = len;
	while (b->top != NULL)
	{
		while (check_all_num(b, &pivot[i]))
		{
			if (check_b_to_a(b, max_stack(b)) == 0)
			{
				ope_print(push(a, b), a->type);
				if (a->top->number > a->top->next->number)
					ope_print(swap(a), a->type);
			}
			else
			{
				if (check_b_to_a(b, max_stack(b)) == 1)
					ope_print(rotate(b), b->type);
				else if (check_b_to_a(b, max_stack(b)) == -1)
					ope_print(reverse_rotate(b), b->type);
				if ((max_stack(b) - 1) == b->top->number)
					ope_print(push(a, b), a->type);
			}
		}
		i--;
	}
}

static void	a_to_b(t_stack *a, t_stack *b, size_t *pivot, size_t len)
{
	size_t		i;

	i = 1;
	while (i < len)
	{
		while (check_all_num(a, &pivot[i]) || check_all_num(a, &pivot[i + 1]))
		{
			if (a->top->number < pivot[i])
			{
				ope_print(push(b, a), b->type);
				if (a->top != NULL && a->top->number >= pivot[i + 1])
					ope_print(rotate_rr(a, b), a->type);
				else
					ope_print(rotate(b), b->type);
			}
			else if (a->top->number < pivot[i + 1])
				ope_print(push(b, a), b->type);
			else
				ope_print(rotate(a), a->type);
		}
		i += 2;
	}
	while (a->top != NULL)
		ope_print(push(b, a), b->type);
}

static void	pivot_create(size_t *pivot, t_stack *s, size_t len)
{
	size_t		i;
	size_t		size;
	size_t		max;

	i = 1;
	size = s->size / len;
	max = s->size;
	pivot[0] = 0;
	while (i < len)
	{
		pivot[i] = size * (i);
		i++;
	}
	pivot[i] = max;
}

void	super_sort(t_stack *a, t_stack *b)
{
	size_t		pivot[25];
	size_t		len;

	len = 25;
	if (a->size <= 100)
		len = 7;
	else if (a->size <= 300)
		len = 11;
	else if (a->size <= 500)
		len = 16;
	pivot_create(pivot, a, len);
	a_to_b(a, b, pivot, len);
	b_to_a(a, b, pivot, len);
}
