/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:41:16 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/12 20:10:17 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_rotate(t_stack **stack, char c)
{
	t_stack	*aux;

	if (!stack || *stack)
		return (-1);
	aux = (*stack)->next;
	ft_lstadd_back_sw(stack, *stack);
	*stack = *aux;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}