/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/22 16:34:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_log(t_stack *stack)
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
}

char	**ft_get_argv(char *str)
{
	char	**new_argv;

	new_argv = ft_split(str, ' ');
	if (!new_argv)
		return (NULL);
	return (new_argv);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**new_argv;

	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		new_argv = ft_get_argv(argv[1]);
		stack = ft_init_stack(new_argv);
	}
	else
		stack = ft_init_stack(argv + 1);
	if (!stack)
		return (1);
	if (ft_unique_checker(stack))
		return (1);
	ft_sort_int_tab(stack);
	ft_replace_index(stack);
	ft_sort(stack);
	free(stack->tab);
	free(stack->tab_temp);
	free(stack);
	return (0);
}
