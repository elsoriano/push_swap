/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:48:49 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/12 17:33:20 by rhernand         ###   ########.fr       */
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
t_stack	*ft_lstnew_sw(int number, int index);
int		ft_atoi_sw(const char *str, t_stack **stack_a);
t_stack	*ft_lstlast_sw(t_stack *lst);
void	ft_lstadd_back_sw(t_stack **lst, t_stack *new);
void	ft_error_exit(t_stack **stack_a, t_stack **stack_b);
#endif