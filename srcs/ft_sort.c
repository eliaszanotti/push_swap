/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:28:28 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/22 15:13:22 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack)
{
	int	i;

	stack->bit = 1;
	while (!ft_is_sorted(stack))
	{
		i = stack->size;
		while (i-- >= 0)
		{
			if ((stack->tab[stack->size] & stack->bit) == 0)
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

/*void	ft_get_sort(stack *stack)
{
	if (stack->size > 3)
		ft_sort(stack);	
	else
		ft_sort_three(stack);


}*/
