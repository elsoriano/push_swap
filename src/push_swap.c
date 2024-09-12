/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:41:23 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/12 18:23:26 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/push_swap.h"

t_stack	**ft_stack_gen(char **argv, t_stack **stack_a, int argc)
{
	long int	number;
	int			i;

	i = 1;
	while (i < argc)
	{
		number = ft_atoi_sw(argv[i], stack_a);
		ft_lstadd_back_sw(stack_a, ft_lstnew_sw(number, i));
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;

	stack_a = (t_stack **)malloc(sizeof (t_stack *));
	if (!stack_a)
		return (0);
	if (argc <= 1)
		return (0);
	stack_a = ft_stack_gen(argv, stack_a, argc);
	while (*stack_a)
	{
		printf("%d", (*stack_a)->number);
		*stack_a = (*stack_a)->next;
	}
	return (0);
}