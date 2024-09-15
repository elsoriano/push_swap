/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:37 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/15 11:41:35 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void	ft_error_exit(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (stack_a && *stack_a)
	{
		while (*stack_a)
		{
			aux = *stack_a;
			*stack_a = (*stack_a)->next;
			free(aux);
		}
		free(stack_a);
	}
	if (stack_b && *stack_b)
	{
		while (*stack_b)
		{
			aux = *stack_b;
			*stack_b = (*stack_b)->next;
			free(aux);
		}
		free(stack_b);
	}
	write(1, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}
