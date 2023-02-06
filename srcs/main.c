/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/06 19:59:33 by ezanotti         ###   ########.fr       */
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


int	ft_add_to_stack(t_args *args, char *current)
{
	char	**splited;
	t_stack	*new;
	int		i;

	splited = ft_split(current, ' ');
	if (!splited)
		return (-1); //TODO
	i = -1;
	while (splited[++i])
	{
		new = ft_stacknew(ft_atoi(splited[i]));
		if (!new)
			return (-1); //TODO
		ft_stackadd_back(&args->stack, new);

		printf("%s\n", splited[i]);
		
	}	




	(void)args;

	return (0);
}

int	ft_struct_init(t_args *args, char **argv)
{
	t_stack	*stack;
	int		i;
	int		current;

	stack = NULL;
	args->stack = stack;
	i = 0;
	while (argv[i])
	{
		current = ft_add_to_stack(args, argv[i++]);
		if (current == -1)
			return (2); //TODO
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc == 1)
		return (1);
	
	if (ft_struct_init(&args, argv))
		return (1); //TODO change to msg error

	return (0);
}
