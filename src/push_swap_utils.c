/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:03:21 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/27 14:44:38 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_stack_size(t_stack **stack)
{
	int		size;
	t_stack	*aux;

	size = 0;
	aux = *stack;
	while (aux)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

t_stack	*ft_lstnew_sw(int number, int i)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = number;
	node->index = -1;
	node->init_pos = i;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

int	ft_atoi_sw(const char *str, t_stack **stack_a)
{
	int			sign;
	int			i;
	long int	n;

	sign = 1;
	n = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		ft_error_exit(stack_a, NULL);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	n = n * sign;
	if (str[i] || n < -2147483648 || n > 2147483647)
		ft_error_exit(stack_a, NULL);
	return (n);
}

t_stack	*ft_lstlast_sw(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_sw(t_stack **lst, t_stack *new)
{
	t_stack	*aux;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new || !lst)
		return ;
	aux = ft_lstlast_sw(*lst);
	if (aux)
	{
		aux->next = new;
		new->next = NULL;
	}
	return ;
}
