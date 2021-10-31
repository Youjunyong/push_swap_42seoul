/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:17:58 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 14:41:37 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"
#include <stdio.h> ///////DELDELDELDE
void print_a(t_stack *a, t_stack *b)
{

	a = a->next;
	if (b->next != NULL)
		b = b->next;
	int data = a->data;
		printf("########################\n");

	printf("a: %d, \n" , data );

	int data_b = b->data;
	printf("b: %d, \n" , data_b );


	while (a->next )
	{
		a = a->next;
		data = a->data;
		printf("a: %d, \n" , data );
	}
		while ( b->next )
	{
		b = b->next;
		data_b = b->data;
		printf(" b: %d\n" , data_b);

	}
}


void	ft_rr(t_stack *a, t_stack *b, int cnt, int type)
{
	int	idx;

	idx = 0;
	if (type == 0)
	{
		while (idx++ < cnt)
			rra(a);
	}
	else
	{
		while (idx++ < cnt)
			rrb(b);
	}
}

void	ft_a_to_b(t_stack *a, t_stack *b, int cnt)
{
	int	a_pivot;
	int	pb_cnt;
	int ra_cnt;
							print_a(a,b);

	if (cnt == 1)
		return ;
	else if (cnt == 2)
	{
		ft_case_two(a);
		return ;
	}
	ra_cnt = 0;
	pb_cnt = 0;
	a_pivot = ft_find_pivot(a, cnt);
	while (cnt-- > 0)
	{

		if (a->next->data > a_pivot)
			ra(a, &ra_cnt);
		else
			pb(a, b, &pb_cnt);

	}
	ft_rr(a, b, ra_cnt, 0);
	ft_a_to_b(a, b, ra_cnt);
	ft_b_to_a(a, b, pb_cnt);
}
void	ft_b_to_a(t_stack *a, t_stack *b, int cnt)
{
	int	b_pivot;
	int rb_cnt;
	int pa_cnt;

	if (cnt == 1)
	{
		pa(a, b, &pa_cnt);
		pa_cnt -= 1;
		return ;
	}
	pa_cnt = 0;
	rb_cnt = 0;
	b_pivot = ft_find_pivot(b, cnt);
	while (cnt-- > 0)
	{
		if (b->next->data < b_pivot)
			rb(b, &rb_cnt);
		else
			pa(a, b, &pa_cnt);
	}
	ft_rr(a, b, rb_cnt, 1);
	ft_a_to_b(a, b, pa_cnt);
	ft_b_to_a(a, b, rb_cnt);
}