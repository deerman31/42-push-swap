/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation2_error_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:58:40 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/29 15:53:58 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**all_free(char **strs)
{
	size_t		i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

size_t	split_count(char **strs)
{
	size_t		i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

static int	space_check(char *str)
{
	size_t		i;

	if (str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	quotation2_error_check(char **argv)
{
	char	**strs;
	size_t	count;
	int		judge;

	if (!space_check(argv[0]))
		return (-1);
	strs = ft_split(argv[0], ' ');
	if (strs == NULL)
		return (-2);
	count = split_count(strs);
	judge = check_error(strs, count);
	all_free(strs);
	return (judge);
}
