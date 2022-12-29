/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:01:09 by elias             #+#    #+#             */
/*   Updated: 2022/12/29 14:25:30 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free_stack(t_stack *stack)
{
	free(stack->tab);
	free(stack->tab_temp);
	free(stack);
	return (NULL);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}
