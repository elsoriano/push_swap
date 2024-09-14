/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:27:44 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/14 12:27:47 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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