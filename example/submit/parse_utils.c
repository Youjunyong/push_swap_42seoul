/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:26:12 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 12:03:30 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

long long	ft_atoi(char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (ft_isalpha(*str))
		error(0);

	return (sign * num);
}

size_t	ft_str_count(char const *str)
{
	size_t cnt;

	cnt = 0;
	while (*str && *str == ' ')
		str++;
	while (*str)
	{
		if (*str && *str != ' ')
		{
			cnt ++;
			while (*str && *str != ' ')
				str++;
		}
		while (*str && *str == ' ')
			str++;
	}
	return (cnt);
}
int		ft_parse(char **argv, int argc)
{
	int	size;
	int i;
	int part_size;
	char **arr;

	size = 0;
	i = 0;
	while (i < argc)
	{	
		arr = ft_split(argv[i]);
		part_size = ft_arrlen(arr);
		size += part_size;

		free_str(arr);

		i++;
	}
	return (size - 1);
}