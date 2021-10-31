/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:47:07 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 11:52:39 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_insert_num(char **arr, long long *num_arr, 
					int *j, int arr_len)
{


	int part_size;
	int i;
	long long temp;

	part_size = ft_arrlen(arr);
	if (part_size > 1) // 따옴표로 묶인것들
	{
		i = 0;
		while (i < part_size) 
		{
			temp = ft_atoi(arr[i++]);

			num_arr[arr_len - 1 - *j] = temp;
			*j += 1;
		}
	}
	else
	{
		temp = ft_atoi(*arr);

		num_arr[arr_len - 1 - *j] = temp;
		*j += 1;
	}
}

void	ft_arr_atoi(char **argv, long long *num_arr, int argc, int arr_len)
{
	int	i;
	int j;
	char **arr;

	i = 1;
	j = 0;

	while (i < argc)
	{
		arr = ft_split(argv[i]);
		ft_insert_num(arr, num_arr, &j, arr_len);
		free_str(arr);
		i++;
	}
}



int			ft_validate_limit(long long *arr, int arr_len) // int 범위 및 중복체크
{
	int i;
	int j;

	i = 0;
	while (i < arr_len - 1)
	{
		j = i + 1;
		while (j < arr_len)
		{
			if (arr[i] == arr[j])
				error(0);
			j++;
		}
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
			error(0);
		i++;
	}
	return (1);
}

void	ft_validate_order(long long *int_arr, int arr_len)
{
	int i;

	i = arr_len - 1;
	while (i > 0)
	{
		if (int_arr[i] > int_arr[i - 1])
			return ;
		i--;
	}
	exit(0);
}