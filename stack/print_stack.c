/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:15:30 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/29 17:58:02 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node		*print;
	size_t		i;

	print = stack->top;
	i = 0;
	while (i <= stack->size)
	{
		ft_printf("%d -> ", (int)print->number);
		print = print->next;
		i++;
	}
	ft_printf("\n");
}
