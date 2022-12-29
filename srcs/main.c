/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/29 13:56:52 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

/*void	ft_log(t_stack *stack)
{
	int	i;

	printf("-- LOG |SIZE=%d| |TEMP=%d| --\n" \
            , stack->size + 1, stack->size_temp +1);
	i = 0;
    printf("|1| : ");
	while (i <= stack->size)
		printf("[%d]", stack->tab[i++]);
	printf("\n");
	i = 0;
    printf("|2| : ");
	while (i <= stack->size_temp)
		printf("[%d]", stack->tab_temp[i++]);
	printf("\n");
	printf("-- END --\n");
}*/

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**new_argv;

	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		new_argv = ft_split(argv[1], ' ');
		stack = ft_init_stack(new_argv);
		ft_free_argv(new_argv);
	}
	else
		stack = ft_init_stack(argv + 1);
	if (!stack)
		return (ft_error(1));
	if (ft_unique_checker(stack))
	{
		ft_free_stack(stack);
		return (ft_error(2));
	}
	ft_sort_int_tab(stack);
	ft_replace_index(stack);
	ft_sort(stack);
	ft_free_stack(stack);
	return (0);
}
