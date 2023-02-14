/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:34:30 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/14 18:40:16 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error(int error_code)
{
	if (error_code)
		write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc == 1)
		return (1);
	if (!argv[1][0])
		return (ft_error(1));
	if (ft_struct_init(&args, argv))
		return (ft_error(1));
	if (ft_check_double(&args))
		return (ft_free_args(&args), ft_error(1));
	if (ft_replace_index(&args))
		return (ft_error(1));
	if (ft_sort_stack(&args))
		return (1);
	ft_free_args(&args);
	return (0);
}
