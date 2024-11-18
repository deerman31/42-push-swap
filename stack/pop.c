/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:15:25 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/27 04:31:17 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *stack)
{
	t_node		*free_node;

	if (stack->size == 0)
		return (0);
	free_node = stack->top;
	if (stack->size == 1)
	{
		free(stack->top);
		stack->top = NULL;
	}
	else
	{
		stack->top->next->prev = stack->top->prev;
		stack->top->prev->next = stack->top->next;
		stack->top = stack->top->next;
		free(free_node);
		free_node = stack->top;
	}
	stack->size--;
	return (1);
}
