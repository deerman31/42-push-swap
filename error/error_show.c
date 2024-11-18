/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:58:33 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/23 17:11:07 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_show(int sign)
{
	if (sign == 1)
		return ;
	else if (sign == 0)
		exit(EXIT_FAILURE);
	else if (sign == -1)
	{
		ft_printf("%s\n", ERROR);
		exit(EXIT_FAILURE);
	}
	else if (sign == -2)
	{
		ft_printf("%s\n", MALLOC_E);
		exit(EXIT_FAILURE);
	}
}
