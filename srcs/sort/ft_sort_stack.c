/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:08:45 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/08 14:51:54 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
