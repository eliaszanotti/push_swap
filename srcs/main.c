/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 18:16:51 by ezanotti         ###   ########.fr       */
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

int	ft_push(t_stack **src, t_stack **dest, char *instruction)
{
	t_stack	*current;

	current = *src;
	if (!current)
		return (0);
	*src = current->next;
	current->next = NULL;
	ft_stackadd_front(dest, current);
	write(1, instruction, 2);
	write(1, "\n", 1);
	return (0);
}

int	ft_rotate(t_stack **stack, char *instruction)
{
	t_stack	*current;

	current = *stack;
	*stack = current->next;
	current->next = NULL;
	ft_stackadd_back(stack, current);
	write(1, instruction, 2);
	write(1, "\n", 1);
	return (0);
}

int	ft_radix_sort(t_args *args)
{
	t_stack	*temp;

	temp = NULL;
	args->tmp = temp;
	
	ft_log(args);
	ft_push(&args->stack, &args->tmp, "pb");
	ft_log(args);
	ft_rotate(&args->stack, "ra");
	ft_log(args);


	return (0);
}

int	ft_sort_stack(t_args *args)
{
	int	size;

	size = ft_stacksize(args->stack);
	printf("size=  %d\n", size);
	if (size > 5)
	{
		if (ft_radix_sort(args))
			return (1);
	}
	

	return (0);
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

	return (0);
}
