/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:06:15 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/29 19:51:02 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	over_flow(unsigned long long s1, unsigned int s2, char sign)
{
	unsigned long long	ov_div;
	unsigned int		ov_mod;
	unsigned long long	un_div;
	unsigned int		un_mod;

	ov_div = INT_MAX / 10;
	ov_mod = INT_MAX % 10;
	un_div = INT_MIN / 10 * -1;
	un_mod = INT_MIN % 10 * -1;
	if (sign == '+' && (ov_div < s1 || (ov_div == s1 && ov_mod < s2)))
		return (1);
	if (sign == '-' && (un_div < s1 || (un_div == s1 && un_mod < s2)))
		return (1);
	return (0);
}

static int	check_over(char *str)
{
	size_t				i;
	unsigned long long	s1;
	unsigned int		s2;
	char				sign;

	i = 0;
	sign = '+';
	if (ft_strchr(SIGN, str[0]))
	{
		i = 1;
		if (str[0] == '-')
			sign = '-';
	}
	s1 = 0;
	while (str[i])
	{
		s2 = str[i] - '0';
		if (over_flow(s1, s2, sign) == 1)
			return (1);
		s1 = s1 * 10 + s2;
		i++;
	}
	return (0);
}

static int	check_num(char **str, size_t elem)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < elem)
	{
		j = 0;
		if (ft_strchr(SIGN, str[i][j]) && ft_isdigit(str[i][j + 1]))
			j = 1;
		while (str[i][j] != '\0')
		{
			if (ft_isdigit(str[i][j]) == 0)
				return (0);
			j++;
		}
		if (check_over(str[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicates(char **str, size_t elem)
{
	size_t		i;
	size_t		j;
	int			value[2];

	i = 0;
	while (i < elem)
	{
		j = i + 1;
		value[0] = ft_atoi(str[i]);
		while (j < elem)
		{
			value[1] = ft_atoi(str[j]);
			if (value[0] == value[1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_error(char **str, size_t elem)
{
	if (elem == 1 && check_num(str, elem))
		return (0);
	if (!check_num(str, elem) || !check_duplicates(str, elem))
		return (-1);
	return (1);
}
