/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:12:17 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/28 21:45:06 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decision_sort(t_stack *a, t_stack *b)
{
	if (check_sort(a) == 1)
		return ;
	if (a->size <= 3)
		three_below(a);
	else if (a->size <= 6)
		six_below(a, b);
	else
		super_sort(a, b);
}
