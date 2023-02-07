/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:06:08 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 19:06:39 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
