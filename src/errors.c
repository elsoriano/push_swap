/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:37 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/12 17:34:26 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void	ft_error_exit(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	aux = *stack_a;
	if (stack_a && *stack_a)
	{
		while (aux)
		{
			aux = (*stack_a)->next;
			free(*stack_a);
		}
	}
	aux = *stack_b;
	if (stack_b && *stack_b)
	{
		while (aux)
		{
			aux = (*stack_b)->next;
			free(*stack_b);
		}
	}
	write(1, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}
