/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/06 18:58:30 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

t_stack	*ft_init_stack(char **argv)
{
	t_stack	*stack;
	size_t	len;

	stack = malloc(sizeof(t_stack));
	len = 0;
	while (argv[len])
		len++;
	stack->size = len;
	stack->tab = malloc(sizeof(int) * len);
	len = 0;
	while (*argv)
		stack->tab[len++] = ft_atoi(*argv++);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc <= 1)
		return (0);
	stack = ft_init_stack(argv + 1);
	/*while (stack->size > 0)
		printf("%d\n", stack->tab[stack->size-- - 1]);*/
}
