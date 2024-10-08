/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:23:55 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/15 10:33:45 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_three(t_stack **stack_a, int el)
{
	if (el == 1)
		return ;
	else if (el == 2)
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			ft_rotate(stack_a, 'a');
		return ;
	}
	else
	{
		if ((*stack_a)->number > (*stack_a)->next->number && \
			(*stack_a)->number > (*stack_a)->next->next->number)
			ft_rotate(stack_a, 'a');
		else if ((*stack_a)->next->number > (*stack_a)->next->next->number)
			ft_reverse_rotate(stack_a, 'a');
		if ((*stack_a)->number > (*stack_a)->next->number)
			ft_swap(stack_a, 'a');
	}
}
