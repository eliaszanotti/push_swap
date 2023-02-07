/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_secure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:56:42 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/07 14:40:10 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	int	ft_overflow(long int nb)
{
	if (nb > 2147483647)
		return (2147483648);
	if (nb < -2147483648)
		return (2147483648);
	return (nb);
}

long int	ft_atoi_secure(const char *str)
{
	int			negatif;
	long int	total;

	negatif = 1;
	total = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negatif *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{	
		if (total != ((total * 10) + *str - '0') / 10)
			return (2147483648);
		total = (total * 10) + *str - '0';
		str++;
	}
	return (ft_overflow(negatif * total));
}
