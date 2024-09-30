/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:11:29 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/30 11:41:40 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_f_rotate(t_stack **stack_a)
{
	t_stack	*aux;

	aux = *stack_a;
	ft_update_init_pos(stack_a, NULL);
	while (aux->index != 1 && aux)
	{
		aux = aux->next;
	}
	if (aux->init_pos > ft_stack_size(stack_a) / 2)
	{
		while ((*stack_a)->index != 1)
			ft_reverse_rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != 1)
			ft_rotate(stack_a, 'a');
	}
}

void	ft_set_stacks(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	int	i;

	i = 0;
	if (!target)
		return ;
	while (i != ft_abs_val(target->cost_b))
	{
		if (target->cost_b > 0)
			ft_rotate(stack_b, 'b');
		else
			ft_reverse_rotate(stack_b, 'b');
		i++;
	}
	i = 0;
	while (i != ft_abs_val(target->cost_a))
	{
		if (target->cost_a > 0)
			ft_rotate(stack_a, 'a');
		else
			ft_reverse_rotate(stack_a, 'a');
		i++;
	}
}

int	ft_abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_stack	*ft_calc_best(t_stack **stack_b)
{
	t_stack	*best;
	t_stack	*aux_b;

	if (!stack_b || !*stack_b)
		return (NULL);
	if (!(*stack_b)->next)
		return (*stack_b);
	best = *stack_b;
	aux_b = (*stack_b)->next;
	while (aux_b)
	{
		if ((ft_abs_val(aux_b->cost_a) + ft_abs_val(aux_b->cost_b)) \
				< (ft_abs_val(best->cost_a) + ft_abs_val(best->cost_b)))
			best = aux_b;
		aux_b = aux_b->next;
	}
	return (best);
}
