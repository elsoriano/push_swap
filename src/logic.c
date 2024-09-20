/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:59:09 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/20 20:02:53 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_update_reverse_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*aux;

	aux = *stack_b;
	size_b = ft_stack_size(stack_b);
	size_a = ft_stack_size(stack_a);
	while (aux)
	{
		aux->cost_a = aux->target_pos -1;
		aux->cost_b = aux->init_pos - 1;
		if (aux->cost_a > size_a / 2)
			aux->cost_a = (size_a / 2) - (aux->cost_a) + 2;
		if (aux->cost_b > size_b / 2)
			aux->cost_b = (size_b / 2) - (aux->cost_b);
		aux = aux->next;
	}
}

void	ft_update_init_pos(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*aux;

	i = 1;
	aux = *stack_a;
	while (aux)
	{
		aux->init_pos = i;
		i++;
		aux = aux->next;
	}
	i = 1;
	aux = *stack_b;
	while (aux)
	{
		aux->init_pos = i;
		i++;
		aux = aux->next;
	}
}

void	ft_update_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_b;
	t_stack	*aux_a;

	aux_b = *stack_b;
	aux_a = *stack_a;
	ft_update_init_pos(stack_a, stack_b);
	while (aux_b)
	{
		aux_b->target_pos = 1;
		while (aux_a->index > aux_b->index)
		{
			aux_b->target_pos += 1;
			aux_a = aux_a->next;
		}
		while (aux_a->next && aux_a->index < aux_b->index)
		{
			aux_b->target_pos += 1;
			aux_a = aux_a->next;
		}
		if (!aux_a->next && aux_b->index > aux_a->index)
			aux_b->target_pos += 1;
		aux_b = aux_b->next;
		aux_a = *stack_a;
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
		while ((*stack_a)->index <= size / 2)
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'a');
		i++;
	}
	return (stack_b);
}

void	ft_assign_index(t_stack **stack_a)
{
	int		i;
	t_stack	*temp;
	t_stack	*aux;

	i = 1;
	temp = *stack_a;
	while (temp)
	{
		aux = *stack_a;
		temp->index = 1;
		while (aux)
		{
			if (temp->number > aux->number)
				temp->index++;
			aux = aux->next;
		}
		temp = temp->next;
	}
}