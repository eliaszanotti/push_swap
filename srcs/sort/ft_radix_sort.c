/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:08:03 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 19:08:24 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_radix_sort(t_args *args)
{
	int	bit;
	int	size;

	bit = 1;
	while (!ft_is_sorted(args->stack))
	{
		size = ft_stacksize(args->stack);
		while (size-- > 0)
		{
			if ((args->stack->content & bit) == 0)
				ft_push(&args->stack, &args->tmp, "pb");
			else
				ft_rotate(&args->stack, "ra");
		}
		size = ft_stacksize(args->tmp);
		while (size-- > 0)
			ft_push(&args->tmp, &args->stack, "pa");
		bit *= 2;
	}
	return (0);
}
