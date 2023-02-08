/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:24:58 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/08 14:50:30 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_args
{
	t_stack	*stack;
	t_stack	*tmp;
}	t_args;

//	PARSING
//	ft_check_parsing.c
int			ft_is_valid_digit(char *current);
int			ft_check_double(t_args *args);
//	ft_replace_index.c
int			ft_replace_index(t_args *args);
//	ft_struct_init.c
int			ft_struct_init(t_args *args, char **argv);

//	SORT
//	ft_radix_sort.c
int			ft_radix_sort(t_args *args);
//	ft_sort_five.c
int			ft_sort_five(t_args *args);
//	ft_sort_four.c
int			ft_sort_four(t_args *args);
//	ft_sort_stack.c
int			ft_sort_stack(t_args *args);
//	ft_sort_three.c
int			ft_sort_three(t_args *args);

//	UTILS
//	ft_atoi_secure.c
long int	ft_atoi_secure(const char *str);
//	ft_free.c
void		ft_free_str(char **str);
void		ft_free_args(t_args *args);
//	ft_instructions.c
int			ft_swap(t_stack **src, char *instruction);
int			ft_push(t_stack **src, t_stack **dest, char *instruction);
int			ft_reverse_rotate(t_stack **stack, char *instruction);
int			ft_rotate(t_stack **stack, char *instruction);
//	ft_sort_int_tab.c
void		ft_sort_int_tab(int *tab, int size);
//	ft_stack_utils.c
int			ft_stacksize(t_stack *stack);
t_stack		*ft_stacknew(int content);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
void		ft_stackadd_back(t_stack **lst, t_stack *new);
//	ft_utils.c
int			ft_is_sorted(t_stack *stack);

#endif
