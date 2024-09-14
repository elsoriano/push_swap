/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:41:16 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/14 11:28:36 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_rotate(t_stack **stack_a, char c)
{
	t_stack	*aux;

	if (!stack || *stack)
		return ;
	aux = (*stack)->next;
	ft_lstadd_back_sw(stack, *stack);
	*stack = aux;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*aux;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	aux = (*stack)->next;
	aux->next = *stack;
	(*stack)->next = (*stack)->next->next;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return ;
}