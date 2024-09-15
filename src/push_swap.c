/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:41:23 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/15 13:04:24 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/push_swap.h"

void	ft_more_than_three(t_stack **stack_a, int size)
{
	t_stack	**stack_b;

	ft_find_target_pos(stack_a);
	stack_b = ft_stack_b(stack_a, stack_b, size);
	ft_three(stack_a, 3);
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