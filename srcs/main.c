/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 13:41:04 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	*ft_get_tab(t_args *args)
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
	stack = args->stack;
	while (stack)
	{
		printf("content = %d\n", stack->content);
		stack = stack->next;
	}
	free(tab);
	return (0);
}

int	ft_add_to_stack(t_args *args, char *current)
{
	char	**splited;
	t_stack	*new;
	int		i;

	splited = ft_split(current, ' ');
	if (!splited)
		return (1); //TODO
	i = -1;
	while (splited[++i])
	{
		new = ft_stacknew(ft_atoi(splited[i]));
		if (!new)
			return (ft_free_str(splited), 1); //TODO
		ft_stackadd_back(&args->stack, new);
	}	
	ft_free_str(splited);
	return (0);
}

int	ft_struct_init(t_args *args, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	args->stack = stack;
	i = 0;
	while (argv[++i])
		if (ft_add_to_stack(args, argv[i]))
			return (2); //TODO
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc == 1)
		return (1);
	if (ft_struct_init(&args, argv))
		return (1); //TODO change to msg error
	if (ft_replace_index(&args))
		return (1);

	return (0);
}
