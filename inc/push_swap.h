/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:48:49 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/27 14:31:58 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				init_pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_index
{
	t_stack	stack_a;
	t_stack	stack_b;
}			t_index;

t_stack	**ft_stack_gen(char **argv, t_stack **stack_a, int argc);
t_stack	*ft_lstnew_sw(int number, int i);
int		ft_atoi_sw(const char *str, t_stack **stack_a);
t_stack	*ft_lstlast_sw(t_stack *lst);
void	ft_lstadd_back_sw(t_stack **lst, t_stack *new);
void	ft_error_exit(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack, char c);
void	ft_reverse_rotate(t_stack **stack, char c);
void	ft_swap(t_stack **stack, char c);
void	ft_push(t_stack **src, t_stack **dst, char c);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_three(t_stack **stack_a, int el);
t_stack	**ft_stack_b_push(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_update_pos(t_stack **stack_a, t_stack **stack_b);
void	ft_update_init_pos(t_stack **stack_a, t_stack **stack_b);
void	ft_cost_a(t_stack **stack_a, t_stack **stack_b);
void	ft_assign_index(t_stack **stack_a);
void	ft_update_reverse_cost(t_stack **stack_a, t_stack **stack_b);
int		ft_stack_size(t_stack **stack);
t_stack	*ft_calc_best(t_stack **stack_b);
int		ft_abs_val(int n);
void	ft_set_stacks(t_stack **stack_a, t_stack **stack_b, t_stack *target);
void	ft_find_target_pos(t_stack *aux_a, t_stack *aux_b);
void	ft_f_rotate(t_stack **stack_a);
void	ft_check_repeated(t_stack **stack_a);
void	ft_check_ordered(t_stack **stack_a);
#endif