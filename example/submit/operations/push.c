/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:31:08 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 11:55:18 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_push_first(t_stack *head, int data)
{
	t_stack *new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		error(0);
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
		new_node->next = head->next;
		head->next->prev = new_node;
		new_node->prev = head;
		head->next = new_node;
	}
}

void	ft_pop_first(t_stack *head)
{
	t_stack *element;

	element = head->next;
	if (element == NULL)
		return ;
	if (element->next == NULL)
	{
		head->next = element->next;
		free(element);
	}
	else
	{
		element->next->prev = head;
		head->next = element->next;
		free(element);
	}
}

void	pa(t_stack *a, t_stack *b, int *pa_cnt)
{
	int b_size;
	int b_data;

	b_size = ft_linked_len(b);
	if (b_size < 1)
		return ;
	b_data = b->next->data;
	ft_pop_first(b);
	ft_push_first(a, b_data);
	*pa_cnt += 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int *pb_cnt)
{
	int a_size;
	int a_data;

	a_size = ft_linked_len(a);
	if (a_size < 1)
		return ;
	a_data = a->next->data;
	ft_pop_first(a);
	ft_push_first(b, a_data);
	*pb_cnt += 1;
	write(1, "pb\n", 3);
}