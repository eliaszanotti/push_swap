/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:25:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 15:48:30 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_add_to_stack(t_args *args, char *current)
{
	t_stack		*new;
	long int	atoi;

	if (!ft_is_valid_digit(current))
		return (1);
	atoi = ft_atoi_secure(current);
	if (atoi == 2147483648)
		return (1);
	new = ft_stacknew(atoi);
	if (!new)
		return (1);
	ft_stackadd_back(&args->stack, new);
	return (0);
}

int	ft_struct_init(t_args *args, char **argv)
{
	char	**splited;
	t_stack	*stack;
	int		i;
	int		j;

	stack = NULL;
	args->stack = stack;
	i = 0;
	while (argv[++i])
	{
		splited = ft_split(argv[i], ' ');
		if (!splited)
			return (1);
		j = -1;
		while (splited[++j])
			if (ft_add_to_stack(args, splited[j]))
				return (ft_free_str(splited), 1);
		ft_free_str(splited);
	}
	return (0);
}
