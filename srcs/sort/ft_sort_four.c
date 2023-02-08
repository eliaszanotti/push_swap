/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:47:33 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/08 14:47:52 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
