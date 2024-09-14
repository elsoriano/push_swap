/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:41:16 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/14 12:22:32 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate(t_stack **stack_a, char c)
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
	if (c != 's')
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	return ;
}

void	ft_push(t_stack **src, t_stack **dst, char c)
{
	t_stack	*aux;
	t_stack	*first_src;

	if (!src || !*src || dst || *dst)
		return ;
	aux = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = aux;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return ;
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, 's');
	ft_swap(stack_b, 's');
	write(1, "ss\n", 3);
}
void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 'r');
	ft_rotate(stack_b, 'r');
	write(1, "rr\n", 3);
}