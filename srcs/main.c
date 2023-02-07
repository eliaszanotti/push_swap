/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 15:13:56 by ezanotti         ###   ########.fr       */
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
	free(tab);
	return (0);
}

int	ft_is_valid_digit(char *current)
{
	while (*current)
	{
		if ((*current < '0' || *current > '9') && *current != '-')
			return (0);
		current++;
	}
	return (1);
}

int	ft_add_to_stack(t_args *args, char *current)
{
	t_stack		*new;
	long int	atoi;

	if (!ft_is_valid_digit(current))
		return (1);
	atoi = ft_atoi_secure(current);
	if (atoi == 2147483648)
		return (1);
	



	new = ft_stacknew(atoi);
	if (!new)
		return (1); //TODO
	ft_stackadd_back(&args->stack, new);
	return (0);
}

int	ft_struct_init(t_args *args, char **argv)
{
	char	**splited;
	t_stack	*stack;
	int		i;
	int		j;

	stack = NULL;
	args->stack = stack;
	i = 0;
	while (argv[++i])
	{
		splited = ft_split(argv[i], ' ');
		if (!splited)
			return (1); //TODO
		j = -1;
		while (splited[++j])
			if (ft_add_to_stack(args, splited[j]))
				return (ft_free_str(splited), 1); //TODO
		ft_free_str(splited);
	}
	return (0);
}

int	ft_check_double(t_args *args)
{
	t_stack	*stack;
	t_stack	*temp;

	stack = args->stack;
	temp = args->stack;
	while (stack)
	{
		temp = stack->next;
		while (temp && stack->content != temp->content)
			temp = temp->next;
		if (temp && (stack->content == temp->content))
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc == 1)
		return (1);
	if (ft_struct_init(&args, argv))
		return (1); //TODO change to msg error
	if (ft_check_double(&args))
		return (1);
	if (ft_replace_index(&args))
		return (1);

	return (0);
}
