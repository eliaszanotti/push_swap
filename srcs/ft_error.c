/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:11:39 by elias             #+#    #+#             */
/*   Updated: 2022/12/29 13:57:48 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int error_code)
{
	if (error_code)
		ft_printf("\e[1;31m[ERROR]\e[0m ");
	if (error_code == 1)
		ft_printf("Incorrect arguments (arguments are not valid integers)\n");
	if (error_code == 2)
		ft_printf("Arguments are not unique\n");
	return (error_code);
}
