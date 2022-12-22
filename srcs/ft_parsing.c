/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:19:26 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/22 15:09:20 by elias            ###   ########.fr       */
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
	int j;
	
	i = -1;
	while (stack->tab[++i])
	{
		j = i;
		while (stack->tab[++j])
			if (stack->tab[i] == stack->tab[j])
				return (1);
	}	
	return (0);
}

t_stack	*ft_init_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		len;

	stack = malloc(sizeof(t_stack));
	if (argc == 2)
	{
		argv = ft_split(argv[0], ' ');
		if (!argv)
			return (NULL);
	}
	if (ft_int_checker(argv))
		return (NULL);
	len = 0;
	while (argv[len])
		len++;
	stack->bit = 1; // peut etre def apres pour les 25 lignes
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
