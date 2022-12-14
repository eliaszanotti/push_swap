/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:40:27 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/14 18:51:12 by event01          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack *stack)
{
	stack->tab[stack->size + 1] = stack->tab_temp[stack->size_temp];
	stack->size++;
	stack->size_temp--;
	ft_printf("pa\n");
}

void	ft_push_b(t_stack *stack)
{
	stack->tab_temp[stack->size_temp + 1] = stack->tab[stack->size];
	stack->size--;
	stack->size_temp++;
	ft_printf("pb\n");
}

void	ft_reverse_a(t_stack *stack)
{
	int	last;
	int	i;

	last = stack->tab[stack->size];
	i = stack->size + 1;
	while (--i > 0)
		stack->tab[i] = stack->tab[i - 1];
	stack->tab[i] = last;
	ft_printf("ra\n");
}

int	ft_is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
