/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:48:02 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/08 14:48:23 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
