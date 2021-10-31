/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:27:59 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 12:10:08 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int 	error(int ret)
{
	write(1, "Error\n" , 6);
	exit(0);
	return ret;
}
void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		ft_free(char **s, int idx)
{
	while (idx--)
		free(s[idx]);
	free(s);
}

void	ft_free_stack(t_stack *a, t_stack *b)
{
	t_stack *nstack;

	while (a)
	{
		nstack = a->next;
		free(a);
		a->next = NULL;
		a->prev = NULL;
		a = nstack;
	}
	while (b)
	{
		nstack = b->next;
		free(b);
		b->next = NULL;
		b->prev = NULL;
		b = nstack;
	}
}