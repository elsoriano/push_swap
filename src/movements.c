/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:41:16 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/15 10:59:33 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*aux;

	if (!stack || !*stack)
		return ;
	aux = (*stack)->next;
	ft_lstadd_back_sw(stack, *stack);
	*stack = aux;
	if (c != 'r')
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_reverse_rotate(t_stack **stack, char c)
{
	t_stack	*aux;
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	last = ft_lstlast_sw(*stack);
	last->next = *stack;
	*stack = last;
	aux = *stack;
	while ((aux)->next != *stack)
		aux = aux->next;
	aux->next = NULL;
	if (c != 'r')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	aux = (*stack)->next;
	tmp = aux->next;
	aux->next = *stack;
	(*stack)->next = tmp;
	*stack = aux;
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




