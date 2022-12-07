/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/07 17:31:43 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_log(t_stack *stack)
{
	int	i;

	printf("-- LOG |SIZE=%d| |TEMP=%d| --\n", stack->size, stack->size_temp);
	i = stack->size;
	while (i >= 0)
		printf("1 : %d\n", stack->tab[i--]);
	printf("\n");
	i = stack->size_temp;
	while (i >= 0)
		printf("2 : %d\n", stack->tab_temp[i--]);
	printf("-- END --\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc <= 1)
		return (0);
	stack = ft_init_stack(argv + 1);
	ft_sort_int_tab(stack);
	ft_replace_index(stack);
	ft_sort(stack);
	ft_log(stack);

	/*ft_log(stack);
	ft_sort(stack);
	ft_log(stack);*/

	/*int a = 10, b = 2;
    printf("a = %d, b = %d\n", a, b);
    printf("a & b = %d\n", a & b);*/
}
