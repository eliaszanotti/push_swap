/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:19:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 12:56:09 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(char **argv)
{
	t_stack	*stack;
	int		len;

	if (ft_int_checker(argv))
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	len = 0;
	while (argv[len])
		len++;
	stack->size = len - 1;
	stack->tab = malloc(sizeof(int) * len);
	stack->tab_temp = malloc(sizeof(int) * len);
	len = 0;
	while (*argv)
	{
		stack->tab[len] = ft_atoi_secure(*argv);
		if (stack->tab[len] == 0 && ft_strcmp(*argv, "0"))
			return (ft_free_stack(stack));
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
			stack->tab_temp[j-- - 1] = temp;
		}
		i++;
	}
}

void	ft_replace_index(t_stack *stack)
{
	int	i;
	int	j;
	int	temp;

	i = stack->size;
	while (i >= 0)
	{
		j = 0;
		while (j <= stack->size && stack->tab[i] != stack->tab_temp[j])
			j++;
		stack->tab[i--] = j;
	}
	i = stack->size;
	while (i >= 0)
		stack->tab_temp[i--] = 0;
	stack->size_temp = -1;
	i = 0;
	j = stack->size;
	while (i < j)
	{
		temp = stack->tab[i];
		stack->tab[i++] = stack->tab[j];
		stack->tab[j--] = temp;
	}
}
