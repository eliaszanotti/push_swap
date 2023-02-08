/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:08:45 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/08 14:41:42 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_three(t_args *args)
{
	int	i0;
	int	i1;
	int	i2;

	i0 = args->stack->content;
	i1 = args->stack->next->content;
	i2 = args->stack->next->next->content;
	if (i0 < i1 && i1 > i2 && i2 > i0)
	{
		ft_swap(&args->stack, "sa");
		ft_rotate(&args->stack, "ra");
	}
	else if (i0 > i1 && i1 < i2 && i2 > i0)
		ft_swap(&args->stack, "sa");
	else if (i0 < i1 && i1 > i2 && i2 < i0)
		ft_reverse_rotate(&args->stack, "rra");
	else if (i0 > i1 && i1 < i2 && i2 < i0)
		ft_rotate(&args->stack, "ra");
	else if (i0 > i1 && i1 > i2)
	{
		ft_swap(&args->stack, "sa");
		ft_reverse_rotate(&args->stack, "rra");
	}
	return (0);
}

int	ft_sort_four(t_args *args)
{
	int	first;

	first = args->stack->content;
	ft_push(&args->stack, &args->tmp, "pb");
	ft_sort_three(args);
	ft_push(&args->tmp, &args->stack, "pa");
	if (first == 1)
		ft_swap(&args->stack, "sa");
	else if (first == 2)
	{
		ft_swap(&args->stack, "sa");
		ft_rotate(&args->stack, "ra");
		ft_swap(&args->stack, "sa");
		ft_reverse_rotate(&args->stack, "rra");
	}
	else if (first == 3)
		ft_rotate(&args->stack, "ra");
	return (0);
}

int	ft_sort_five(t_args *args)
{
	int	size;
	int	i;
	int	first_a;
	int	first_b;

	size = ft_stacksize(args->stack);
	i = -1;
	while (++i < size)
	{
		first_a = args->stack->content;
		if (first_a < 2)
			ft_push(&args->stack, &args->tmp, "pb");
		else
			ft_rotate(&args->stack, "ra");
	}
	first_b = args->tmp->content;
	if (first_b == 0)
		ft_swap(&args->tmp, "sb");
	ft_sort_three(args);
	while (ft_stacksize(args->tmp))
		ft_push(&args->tmp, &args->stack, "pa");
	return (0);
}

int	ft_sort_stack(t_args *args)
{
	int	size;

	size = ft_stacksize(args->stack);
	if (ft_is_sorted(args->stack))
		return (0);
	if (size > 5 && ft_radix_sort(args))
		return (1);
	if (size == 5 && ft_sort_five(args))
		return (1);
	if (size == 4 && ft_sort_four(args))
		return (1);
	if (size == 3 && ft_sort_three(args))
		return (1);
	if (size == 2)
		ft_swap(&args->stack, "sa");
	return (0);
}
