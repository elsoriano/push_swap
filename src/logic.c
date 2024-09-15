/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:59:09 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/15 13:53:20 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_costs(t_stack **stack_b, int size)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = *stack_b;
	while (i <= size / 2)
	{
		aux->cost_b = i;
		aux = aux->next;
		i++;
	}
	if (size % 2)
		i--;
	while (aux)
	{
		aux->cost_b = i;
		aux = aux->next;
		i--;
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
		while ((*stack_a)->target_pos < size / 2)
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'a');
		i++;
	}
	return (stack_b);
}

void	ft_find_target_pos(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*comp;

	aux = *stack_a;
	while (aux)
	{
		comp = *stack_a;
		aux->target_pos = 1;
		while (comp)
		{
			if (aux->number > comp->number)
				aux->target_pos++;
			comp = comp->next;
		}
		aux = aux->next;
	}
}