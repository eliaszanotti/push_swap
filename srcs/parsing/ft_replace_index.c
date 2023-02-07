/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:26:51 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 15:48:11 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_get_tab(t_args *args)
{
	t_stack	*stack;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * ft_stacksize(args->stack));
	if (!tab)
		return (NULL);
	i = 0;
	stack = args->stack;
	while (stack)
	{
		tab[i++] = stack->content;
		stack = stack->next;
	}
	return (tab);
}

int	ft_replace_index(t_args *args)
{
	t_stack	*stack;
	int		*tab;
	int		size;
	int		i;

	tab = ft_get_tab(args);
	if (!tab)
		return (1);
	size = ft_stacksize(args->stack);
	ft_sort_int_tab(tab, size);
	stack = args->stack;
	while (stack)
	{
		i = 0;
		while (i < size && tab[i] != stack->content)
			i++;
		if (tab[i] == stack->content)
			stack->content = i;
		stack = stack->next;
	}
	return (free(tab), 0);
}
