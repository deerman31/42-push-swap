/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:05:54 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/27 19:39:13 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = create_stack('a');
	if (a == NULL)
		error_show(-2);
	b = create_stack('b');
	if (b == NULL)
	{
		free(a);
		error_show(-2);
	}
	if (add(a, argc - 1, &argv[1]) == -1)
	{
		s_n_free(a, b);
		error_show(-2);
	}
	decision_sort(a, b);
	s_n_free(a, b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		error_show(0);
	else if (argc == 2)
		error_show(quotation2_error_check(&argv[1]));
	else
		error_show(check_error(&argv[1], (size_t)argc - 1));
	push_swap(argc, argv);
	return (0);
}
