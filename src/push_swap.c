/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:41:23 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/27 14:43:49 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/push_swap.h"

void	ft_check_ordered(t_stack **stack_a)
{
	t_stack	*aux;

	aux = *stack_a;
	while (aux->next && aux->index < aux->next->index)
	{
		aux = aux->next;
	}
	if (!aux->next)
	{
		while (*stack_a)
		{
			aux = *stack_a;
			*stack_a = (*stack_a)->next;
			free(aux);
		}
		free(stack_a);
		exit (EXIT_SUCCESS);
	}
}

void	ft_more_than_three(t_stack **stack_a, int size)
{
	t_stack	**stack_b;
	t_stack	*target;

	stack_b = NULL;
	ft_check_ordered(stack_a);
	stack_b = ft_stack_b_push(stack_a, stack_b, size);
	ft_three(stack_a, 3);
	while (*stack_b)
	{
		ft_update_pos(stack_a, stack_b);
		ft_update_reverse_cost(stack_a, stack_b);
		target = ft_calc_best(stack_b);
		ft_set_stacks(stack_a, stack_b, target);
		ft_push(stack_b, stack_a, 'a');
	}
	ft_f_rotate(stack_a);
	free(*stack_b);
	free(stack_b);
}

t_stack	**ft_stack_b_push(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;

	i = 0;
	stack_b = (t_stack **)malloc(sizeof (t_stack *));
	if (!stack_b)
		ft_error_exit(stack_a, NULL);
	*stack_b = NULL;
	while (i < ((size / 2) - 1 + (size % 2)) && size > 5)
	{
		while ((*stack_a)->index < (size / 2) + (size % 2))
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
		i++;
	}
	while (i < size - 3)
	{
		ft_push(stack_a, stack_b, 'b');
		i++;
	}
	return (stack_b);
}

t_stack	**ft_stack_gen(char **argv, t_stack **stack_a, int argc)
{
	long int	number;
	int			i;
	t_stack		*aux;

	stack_a = (t_stack **)malloc(sizeof (t_stack *));
	if (!stack_a)
		ft_error_exit(NULL, NULL);
	*stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		number = ft_atoi_sw(argv[i], stack_a);
		aux = ft_lstnew_sw(number, i);
		if (!aux)
			ft_error_exit(stack_a, NULL);
		ft_lstadd_back_sw(stack_a, aux);
		i++;
	}
	ft_check_repeated(stack_a);
	ft_assign_index(stack_a);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	*aux;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_a = ft_stack_gen(argv, stack_a, argc);
	if (argc <= 4)
		ft_three(stack_a, argc - 1);
	else
		ft_more_than_three(stack_a, argc - 1);
	while (*stack_a)
	{
		aux = (*stack_a)->next;
		free(*stack_a);
		*stack_a = aux;
	}
	free(stack_a);
	return (0);
}
