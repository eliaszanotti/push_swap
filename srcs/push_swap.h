/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:24:58 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/22 15:53:02 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int	*tab;
	int	*tab_temp;
	int	size;
	int	size_temp;
	int	bit;
}	t_stack;

t_stack	*ft_init_stack(char **argv);
int		ft_int_checker(char **argv);
int		ft_unique_checker(t_stack *stack);
void	ft_sort_int_tab(t_stack *stack);
void	ft_replace_index(t_stack *stack);
int		ft_is_sorted(t_stack *stack);

void	ft_push_a(t_stack *stack);
void	ft_push_b(t_stack *stack);
void	ft_reverse_a(t_stack *stack);
void	ft_sort(t_stack *stack);

void	ft_log(t_stack *stack);

#endif
