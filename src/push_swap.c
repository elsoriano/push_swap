/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:41:23 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/11 13:38:26 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/push_swap.h"

int	ft_stack_gen(char **argv, t_stack **stack, int argc)
{
	long int	number;
	int			i;

	i = 1;
	while (i < argc)
	{
		number = ft_atoi_sw(argv[i]);
		ft_lstadd_back(stack, ft_lstadd_new(number, i));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	if (!ft_stack_gen(argv, &stack_a, argc))
		return (write(1, "ERROR\n", 6), 0);
	return (0);
}