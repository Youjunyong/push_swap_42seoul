/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:23:23 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 10:25:39 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	*ft_strdup(const char *str, size_t str_len)
{
	char *arr;
	size_t i;

	i = 0;
	arr = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!arr)
		return (0);
	while (i < str_len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

size_t	ft_str_len(char const *str)
{
	size_t i;

	i = 0;
	while (*str && *str++ != ' ')
		i++;
	return (i);
}

int			ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == 'r' ||
	c == '\t' || c == '\v' || c == ' ');
}

int			ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


char **ft_split(char const *str)
{
	char **arr;
	size_t i;
	size_t str_cnt;
	size_t str_len;

	str_cnt = ft_str_count(str);
	if (!(arr = (char **)malloc(sizeof(char *) * (str_cnt + 1))))
		return (0);
	i = 0;
	while (i < str_cnt)
	{
		while (*str && *str == ' ')
			str++;
		str_len = ft_str_len(str);
		arr[i] = ft_strdup(str, str_len);
		i++;
		str += str_len;
	}
	arr[str_cnt] = 0;
	return (arr);
}



