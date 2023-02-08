/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/08 14:45:42 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static int	ft_error(int error_code)
{
	if (error_code)
		write(1, "Error\n", 6);
	return (1);
}

void	ft_log(t_args *args)
{
	t_stack	*stack;
	t_stack	*temp;

	stack = args->stack;
	temp = args->tmp;
	while (temp && stack)
	{
		printf("[%d]\t[%d]\n", stack->content, temp->content);
		stack = stack->next;
		temp = temp->next;
	}
	while (temp)
	{
		printf("[ ]\t[%d]\n", temp->content);
		temp = temp->next;
	}
	while (stack)
	{
		printf("[%d]\t[ ]\n", stack->content);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc == 1)
		return (1);
	if (ft_struct_init(&args, argv))
		return (ft_error(1));
	if (ft_check_double(&args))
		return (ft_error(1));
	if (ft_replace_index(&args))
		return (ft_error(1));
	if (ft_sort_stack(&args))
		return (1);
	ft_free_args(&args);
	return (0);
}
