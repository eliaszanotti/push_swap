/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:24:58 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/06 19:22:48 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_args
{
	int	*tab;
	int	*tab_temp;
	int	size;
	int	size_temp;
	int	bit;
}	t_stack;

/*//ft_checker.c
int		ft_int_checker(char **argv);
int		ft_unique_checker(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
//ft_error.c
int		ft_error(int error_code);
//ft_free.c
void	*ft_free_stack(t_stack *stack);
void	ft_free_argv(char **argv);
//ft_instructions.c
void	ft_push_a(t_stack *stack);
void	ft_push_b(t_stack *stack);
void	ft_reverse_a(t_stack *stack);
//ft_parsing.c
t_stack	*ft_init_stack(char **argv);
void	ft_sort_int_tab(t_stack *stack);
void	ft_replace_index(t_stack *stack);
//ft_sort.c
void	ft_sort(t_stack *stack);

void	ft_log(t_stack *stack);*/

#endif
