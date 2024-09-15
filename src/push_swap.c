/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:41:23 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/15 11:25:48 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/push_swap.h"

void	ft_check_repeated(t_stack **stack_a, int size)
{
	t_stack	*aux;
	t_stack	*first;

	first = *stack_a;
	while (first)
	{
		aux = first->next;
		while (aux)
		{
			if (first->number == aux->number)
				ft_error_exit(stack_a, NULL);
			aux = aux->next;
		}
		first = first->next;
	}
}

t_stack	**ft_stack_gen(char **argv, t_stack **stack_a, int argc)
{
	long int	number;
	int			i;

	stack_a = (t_stack **)malloc(sizeof (t_stack *));
	if (!stack_a)
		return (0);
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
	t_stack	**stack_b;

	if (argc <= 1)
		return (0);
	stack_a = ft_stack_gen(argv, stack_a, argc);
	if (argc <= 4)
		ft_three(stack_a, argc - 1);
	return (0);
}