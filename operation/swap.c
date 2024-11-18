/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:43:31 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/17 22:06:07 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	t_node		*top;
	t_node		*second;
	t_node		*last;

	if (stack->size < 2)
		return (0);
	else if (stack->size == 2)
	{
		stack->top = stack->top->next;
		return (1);
	}
	top = stack->top;
	second = stack->top->next;
	last = stack->top->prev;
	top->next = second->next;
	top->prev = second;
	second->next->prev = top;
	second->prev = last;
	second->next = top;
	last->next = second;
	stack->top = second;
	return (1);
}
