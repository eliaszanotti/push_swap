/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:16:15 by elias             #+#    #+#             */
/*   Updated: 2022/12/28 17:54:36 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_checker(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ')
				return (1);
	}
	return (0);
}

int	ft_unique_checker(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= stack->size)
	{
		j = i;
		while (++j <= stack->size)
			if (stack->tab[i] == stack->tab[j])
				return (1);
	}
	return (0);
}

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	if (stack->size_temp != -1)
		return (0);
	while (++i < stack->size)
		if (stack->tab[i] < stack->tab[i + 1])
			return (0);
	return (1);
}
