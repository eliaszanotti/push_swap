/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:46:53 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/08 14:47:23 by ezanotti         ###   ########.fr       */
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
