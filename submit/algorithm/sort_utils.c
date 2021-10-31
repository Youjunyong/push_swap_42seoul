/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:20:07 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 13:47:54 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_swap(long long *arr, int idx, int l_idx)
{
	int	tmp;

	tmp = arr[idx];
	arr[idx] = arr[l_idx];
	arr[l_idx] = tmp;
}

void	ft_sort_arr(long long *arr, int cnt)
{
	int idx;
	int	jdx;
	int least;
	int	least_idx;

	idx = 0;
	while (idx < cnt - 1)
	{
		least = arr[idx];
		least_idx = idx;
		jdx = idx + 1;
		while (jdx < cnt)
		{
			if (least > arr[jdx])
			{
				least = arr[jdx];
				least_idx = jdx;
			}
			jdx++;
		}
		ft_swap(arr, idx, least_idx);
		idx++;
	}
}

int		ft_find_pivot(t_stack *head, int cnt)
{
	t_stack		*tmp;
	long long	*arr;
	int			idx;
	int			ret;

	tmp = head->next;
	arr = (long long *)malloc(sizeof(long long) * cnt);
	idx = 0;
	while (idx < cnt)
	{
		arr[idx++] = tmp->data;
		tmp = tmp->next;
	}
	idx = 0;
	ft_sort_arr(arr, cnt);
	ret = arr[cnt / 2];
	free(arr);
	return (ret);
}

int		ft_max(t_stack *head)
{
	int	max;

	max = -2147483648;
	head = head->next;
	while (head)
	{
		if (max <= head->data)
			max = head->data;
		head = head->next;
	}
	return (max);
}

int		ft_min(t_stack *head)
{
	int	min_value;

	min_value = 2147483647;
	head = head->next;
	while (head)
	{
		if (min_value >= head->data)
			min_value = head->data;
		head = head->next;
	}
	return (min_value);
}