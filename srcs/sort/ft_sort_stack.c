/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:08:45 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 19:08:59 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_stack(t_args *args)
{
	int	size;

	size = ft_stacksize(args->stack);
	if (size > 5 && ft_radix_sort(args))
		return (1);
	return (0);
}
