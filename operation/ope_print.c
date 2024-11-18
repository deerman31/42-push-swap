/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:51:22 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/18 20:03:16 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ope_print(int sign, char type)
{
	if (sign == 1)
		ft_printf("s%c\n", type);
	else if (sign == 2)
		ft_printf("p%c\n", type);
	else if (sign == 3)
		ft_printf("r%c\n", type);
	else if (sign == 4)
		ft_printf("rr%c\n", type);
	else if (sign == 11)
		ft_printf("ss\n");
	else if (sign == 33)
		ft_printf("rr\n");
	else if (sign == 44)
		ft_printf("rrr\n");
	return (1);
}
