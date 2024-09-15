/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:59:09 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/15 12:07:02 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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