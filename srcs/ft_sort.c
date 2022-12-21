/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:28:28 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/21 14:49:12 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack)
{
	int	i;
	int	index;

	index = -1;
	while (!ft_is_sorted(stack->tab, stack->size))
	{
		index++;
		i = stack->size;
		while (i-- >= 0)
		{
			if (((stack->tab[stack->size] >> index) & 1) == 0)
				ft_push_b(stack);
			else
				ft_reverse_a(stack);
		}
		i = stack->size_temp;
		while (i-- >= 0)
			ft_push_a(stack);
		stack->bit *= 2;
	}
}
