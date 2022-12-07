/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/07 13:17:51 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_sort_int_tab(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (i < stack->size)
	{
		j = i;
		while (j > 0 && stack->tab_copy[j - 1] > stack->tab_copy[j])
		{
			temp = stack->tab_copy[j];
			stack->tab_copy[j] = stack->tab_copy[j - 1];
			stack->tab_copy[j - 1] = temp;
			j--;
		}
		i++;
	}
}

t_stack	*ft_init_stack(char **argv)
{
	t_stack	*stack;
	size_t	len;

	stack = malloc(sizeof(t_stack));
	len = 0;
	while (argv[len])
		len++;
	stack->size = len;
	stack->tab = malloc(sizeof(int) * len);
	stack->tab_copy = malloc(sizeof(int) * len);
	len = 0;
	while (*argv)
	{
		stack->tab[len] = ft_atoi(*argv);
		stack->tab_copy[len++] = ft_atoi(*argv++);
	}
	return (stack);
}

void	ft_replace_index(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->size - 1;
	while (i >= 0)
	{
		j = stack->size - 1;
		while (j >= 0 && stack->tab[i] != stack->tab_copy[j])
			j--;
		stack->tab[i] = j;
		i--;
	}
}



int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc <= 1)
		return (0);
	stack = ft_init_stack(argv + 1);

	
	ft_sort_int_tab(stack);
	ft_replace_index(stack);
	ft_printf("\n\n\n");

	int i = stack->size - 1;
	while (i >= 0)
		printf("%d\n", stack->tab[i--]);
}
