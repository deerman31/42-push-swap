/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_n_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:19:43 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/27 19:19:45 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_n_free(t_stack *a, t_stack *b)
{
	int		n;

	if (a->size == 0)
	{
		free(a);
		free(b);
		return ;
	}
	n = pop(a);
	while (n)
		n = pop(a);
	free(a);
	free(b);
}
