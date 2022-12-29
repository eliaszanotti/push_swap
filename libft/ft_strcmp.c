/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:33:15 by elias             #+#    #+#             */
/*   Updated: 2022/12/29 13:34:25 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;

	copy_s1 = (unsigned char *)s1;
	copy_s2 = (unsigned char *)s2;
	while (*copy_s1 && *copy_s2 && *copy_s1 == *copy_s2)
	{
		copy_s1++;
		copy_s2++;
	}
	return (*copy_s1 - *copy_s2);
}
