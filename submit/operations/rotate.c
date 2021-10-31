/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:09:49 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 11:19:35 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_push_last(t_stack *head, int data)
{
	t_stack *new_node;
	t_stack *tmp_last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		error(0);
	tmp_last = ft_get_last(head);
	if (head->next == NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = head;
		head->next = new_node;
	}
	else
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = tmp_last;
		tmp_last->next = new_node;
	}
}

void	ra(t_stack *a, int *cnt)
{
	int a_data;

	if (a->next == NULL)
		return ;
	a_data = a->next->data;
	ft_pop_first(a);
	ft_push_last(a, a_data);
	*cnt += 1;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b, int *cnt)
{
	int b_data;

	if (b->next == NULL)
		return ;
	b_data = b->next->data;
	ft_pop_first(b);
	ft_push_last(b, b_data);
	*cnt += 1;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int idx;

	idx = 0;
	ra(a, &idx);
	rb(b, &idx);
	write(1, "rr\n", 3);
}