/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:28:28 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/14 19:03:41 by event01          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack)
{
	int	i;

	while (!ft_is_sorted(stack->tab, stack->size))
	{
		i = stack->size;
		while (i >= 0)
		{
			if ((stack->bit & stack->tab[stack->size]) == 0)
				ft_push_b(stack);
			else
				ft_reverse_a(stack);
			i--;
		}
		i = stack->size_temp;
		while (i >= 0)
		{
			ft_push_a(stack);
			i--;
		}
		stack->bit *= 2;
	}
}
