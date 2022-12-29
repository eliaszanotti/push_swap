/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_secure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:10:18 by elias             #+#    #+#             */
/*   Updated: 2022/12/29 14:11:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(int signe)
{
	if (signe < 0)
		return (0);
	return (-1);
}

int	ft_atoi_secure(const char *str)
{
	int				negatif;
	long long int	total;

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
			return (ft_overflow(negatif));
		total = (total * 10) + *str - '0';
		str++;
	}
	if (negatif * total > 2147483647 || negatif * total < -2147483648)
		return (0);
	return (negatif * total);
}
