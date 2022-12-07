/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:19:26 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/07 16:29:24 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(char **argv)
{
	t_stack	*stack;
	int		len;

	stack = malloc(sizeof(t_stack));
	len = 0;
	while (argv[len])
		len++;
	stack->bit = 1;
	stack->size = len - 1;
	stack->tab = malloc(sizeof(int) * len);
	stack->tab_temp = malloc(sizeof(int) * len);
	len = 0;
	while (*argv)
	{
		stack->tab[len] = ft_atoi(*argv);
		stack->tab_temp[len++] = ft_atoi(*argv++);
	}
	return (stack);
}

void	ft_sort_int_tab(t_stack *stack)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < stack->size + 1)
	{
		j = i;
		while (j > 0 && stack->tab_temp[j - 1] > stack->tab_temp[j])
		{
			temp = stack->tab_temp[j];
			stack->tab_temp[j] = stack->tab_temp[j - 1];
			stack->tab_temp[j - 1] = temp;
			j--;
		}
		i++;
	}
}

void	ft_replace_index(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack->size)
	{
		j = 0;
		while (j <= stack->size && stack->tab[i] != stack->tab_temp[j])
			j++;
		stack->tab[i++] = j;
	}
	i = 0;
	while (i <= stack->size)
		stack->tab_temp[i++] = 0;
	stack->size_temp = -1;
}
