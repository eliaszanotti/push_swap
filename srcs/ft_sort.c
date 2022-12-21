/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:28:28 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/21 14:12:28 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_sort(t_stack *stack)
{
	int	i;
    int index;

    index = -1;
	while (!ft_is_sorted(stack->tab, stack->size))
	{

        index++;

		i = stack->size;
		//i = 0;
		while (i >= 0)
		{
            //printf("%d\n", stack->bit & stack->tab[stack->size]);
			if (((stack->tab[stack->size] >> index) & 1) == 0)
            {
				ft_push_b(stack);
                //ft_log(stack);
			}
            else
            {
				ft_reverse_a(stack);
                //ft_log(stack);
            }
			i--;
		}
        //ft_log(stack);
		i = stack->size_temp;
		//i = 0;
		while (i >= 0)
        {
			ft_push_a(stack);
            //ft_log(stack);
            i--;
        }
		stack->bit *= 2;
	}
}
