/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:52:00 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/22 16:21:10 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zero_pattern(t_stack *active, t_node *top)
{
	active->top = top;
	active->top->next = top;
	active->top->prev = top;
}

static void	else_pattern(t_stack *active, t_node *top)
{
		top->next = active->top;
		top->prev = active->top->prev;
		active->top->prev->next = top;
		active->top->prev = top;
		active->top = top;
}

int	push(t_stack *active, t_stack *passive)
{
	t_node		*top;

	if (passive->size == 0)
		return (0);
	passive->top->next->prev = passive->top->prev;
	passive->top->prev->next = passive->top->next;
	top = passive->top;
	passive->top = passive->top->next;
	if (active->size == 0)
		zero_pattern(active, top);
	else
		else_pattern(active, top);
	active->size++;
	passive->size--;
	if (passive->size == 0)
		passive->top = NULL;
	return (2);
}
