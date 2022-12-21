/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:16:33 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/20 11:32:59 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_printaddress(void *address);
int	ft_base(char *base, long int nbr);

int	ft_printf(const char *s, ...);

#endif
