/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:54:01 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 11:43:35 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack *ft_create_stack(void)
{
	t_stack *temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		exit(0);
	temp->data = 0;
	temp->prev = NULL;
	temp->next = NULL;
	return (temp);
}

t_stack	*ft_get_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	ft_create_linked(t_stack *head, long long *arr, int cnt)
{
	int		idx;
	t_stack	*new_node;

	idx = 0;
	while (idx < cnt)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			error(0);
			
		if (idx == 0)
		{
			new_node->data = arr[idx++];
			new_node->next = NULL;
			new_node->prev = head;
			head->next = new_node;
		}
		else
		{
			new_node->data = arr[idx++];
			new_node->next = head->next;



			new_node->next->prev = new_node;
			new_node->prev = head;
			head->next = new_node;
		}
	}
}