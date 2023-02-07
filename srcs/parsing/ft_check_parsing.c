/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:25:59 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 15:28:13 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
