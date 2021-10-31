/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:27:25 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 13:13:46 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(int argc, char *argv[])
{

	long long *num_arr;
	int arr_len;

	if (argc < 2)
		exit(0);

	arr_len = ft_parse(argv, argc);
	num_arr = (long long *)malloc(sizeof(long long) * arr_len);
	if (!num_arr)
		error(0);
	ft_arr_atoi(argv, num_arr, argc, arr_len);
	ft_validate_limit(num_arr,  arr_len);
	ft_validate_order(num_arr, arr_len);


	
	t_stack *a;
	t_stack *b;
	a = ft_create_stack();
	b = ft_create_stack();

	ft_create_linked(a, num_arr, arr_len);

	ft_sort_start(a, b, arr_len);
	ft_free_stack(a, b);


	return (0);

}