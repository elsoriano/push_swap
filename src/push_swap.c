/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:41:23 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/21 12:41:07 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/push_swap.h"

void	ft_more_than_three(t_stack **stack_a, int size)
{
	t_stack	**stack_b;
	t_stack	*target;

	stack_b = ft_stack_b_push(stack_a, stack_b, size);
	ft_three(stack_a, 3);
	while (*stack_b)
	{
		ft_update_pos(stack_a, stack_b);
		ft_update_reverse_cost(stack_a, stack_b);
		target = ft_calc_best(stack_b);
		ft_set_stacks(stack_a, stack_b, target);
		ft_push(stack_b, stack_a, 'b');
	}
}

t_stack	**ft_stack_b_push(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;

	i = 0;
	stack_b = (t_stack **)malloc(sizeof (t_stack *));
	if (!stack_b)
		ft_error_exit(stack_a, NULL);
	while (i < size - 3)
	{
		while ((*stack_a)->index <= (ft_stack_size(stack_a) / 2) \
				|| (*stack_a)->index < 4)
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'a');
		i++;
	}
	return (stack_b);
}

t_stack	**ft_stack_gen(char **argv, t_stack **stack_a, int argc)
{
	long int	number;
	int			i;

	stack_a = (t_stack **)malloc(sizeof (t_stack *));
	if (!stack_a)
		ft_error_exit(NULL, NULL);
	i = 1;
	while (i < argc)
	{
		number = ft_atoi_sw(argv[i], stack_a);
		ft_lstadd_back_sw(stack_a, ft_lstnew_sw(number, i));
		i++;
	}
	ft_check_repeated(stack_a, argc - 1);
	ft_assign_index(stack_a);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;

	if (argc <= 1)
		return (0);
	stack_a = ft_stack_gen(argv, stack_a, argc);
	if (argc <= 4)
		ft_three(stack_a, argc - 1);
	else
		ft_more_than_three(stack_a, argc - 1);
	return (0);
}
