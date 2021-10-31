/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:12:12 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 13:42:35 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_ret_max_min(t_stack *a, t_stack *b, int pb_cnt, int max)
{
	int i;

	i = 0;
	while (pb_cnt > 0)
	{
		if (b->next->data == max)
		{
			pa(a, b, &i);
			ra(a, &i);
		}
		else
			pa(a, b, &i);
		pb_cnt -= 1;
	}
}

void	ft_case_five(t_stack *a, t_stack *b)
{
	int		max;
	int		min;
	int		pb_cnt;
	int		i;

	i = 0;
	max = ft_max(a);
	min = ft_min(a);
	pb_cnt = 0;
	while (ft_linked_len(a) > 3)
	{
		if (a->next->data == max ||
		a->next->data == min)
		{
			pb(a, b, &i);
			pb_cnt += 1;
		}
		else
			ra(a, &i);
	}
	ft_case_three(a);
	ft_ret_max_min(a, b, pb_cnt, max);
}

void	ft_case_three(t_stack *head)
{
	t_stack	*top;
	t_stack	*bot;
	int		idx;
	int		max;
	int		min;

	idx = 0;
	top = head->next;
	bot = head->next->next->next;
	max = ft_max(head);
	min = ft_min(head);
	if ((top->next->data == min
	&& bot->data == max) ||
	(top->data == max && bot->data == min)
	|| (top->data == min &&
	top->next->data == max))
		sa(head);
	if (top->next->data == max)
		rra(head);
	if (top->data == max
	&& top->next->data == min)
		ra(head, &idx);
}

void	ft_case_two(t_stack *head)
{
	t_stack	*top;
	t_stack	*bot;

	top = head->next;
	bot = head->next->next;
	if (top->data > bot->data)
		sa(head);
	else
		return ;
}

void	ft_sort_start(t_stack *a, t_stack *b, int num)
{
	if (num == 1)
		return ;
	else if (num == 2)
		ft_case_two(a);
	else if (2 < num && num < 6)
		ft_case_five(a, b);
	else
		ft_a_to_b(a, b, num);

}