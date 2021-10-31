/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:06:17 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 11:55:08 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int		ft_linked_len(t_stack *head)
{
	t_stack *tmp;
	int		i;

	i = 0;
	tmp = head->next;
	while (tmp)
	{
		tmp = tmp->next;
		i += 1;
	}
	return (i);
}
void	sa(t_stack *a)
{
	int	data;
	int	size;

	size = ft_linked_len(a);
	if (size < 2)
		return ;
	data = a->next->next->data;
	a->next->next->data = a->next->data;
	a->next->data = data;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	data;
	int	size;

	size = ft_linked_len(b);
	if (size < 2)
		return ;
	data = b->next->next->data;
	b->next->next->data = b->next->data;
	b->next->data = data;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}