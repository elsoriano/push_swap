/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:59:09 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/24 18:23:59 by rhernand         ###   ########.fr       */
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
		if (aux->cost_a == size_a)
			aux->cost_a = 0;
		else if (aux->cost_a > size_a / 2)
			aux->cost_a = aux->cost_a - size_a;
		if (aux->cost_b > size_b / 2)
			aux->cost_b = aux->cost_b - size_b - 1;
		aux = aux->next;
	}
}

void	ft_find_target_pos(t_stack *aux_a, t_stack *aux_b)
{
	while (aux_a->index > aux_b->index && aux_a->next \
				&& aux_a->index < aux_a->next->index)
	{
		aux_b->target_pos += 1;
		aux_a = aux_a->next;
	}
	aux_b->target_pos += 1;
	if (aux_a->next && aux_a->index > aux_a->next->index \
			&& (aux_b->index > aux_a->index \
			|| aux_b->index < aux_a->next->index))
		return ;
	aux_a = aux_a->next;
	while (aux_a && aux_a->next && aux_a->index < aux_b->index \
			&& aux_a->index < aux_a->next->index)
	{
		aux_b->target_pos += 1;
		aux_a = aux_a->next;
	}
	if (aux_a && aux_b->index > aux_a->index)
		aux_b->target_pos += 1;
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
	if (!stack_b || !*stack_b)
		return ;
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
		ft_find_target_pos(aux_a, aux_b);
		aux_b = aux_b->next;
		aux_a = *stack_a;
	}
}

void	ft_assign_index(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*aux;

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