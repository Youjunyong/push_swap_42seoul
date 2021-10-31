/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:12:12 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 11:56:42 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_pop_last(t_stack *head)
{
	t_stack *last;

	last = head->next;
	if (last == NULL)
		return ;
	else
	{
		last = ft_get_last(head);
		last->prev->next = NULL;
		free(last);
	}
}

void	rra(t_stack *a)
{
	t_stack *last_a;
	int		adata;

	last_a = ft_get_last(a);
	adata = last_a->data;
	ft_pop_last(a);
	ft_push_first(a, adata);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_stack *last_b;
	int		bdata;

	last_b = ft_get_last(b);
	bdata = last_b->data;
	ft_pop_last(b);
	ft_push_first(b, bdata);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}