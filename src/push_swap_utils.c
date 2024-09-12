/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:03:21 by rhernand          #+#    #+#             */
/*   Updated: 2024/09/11 14:53:45 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_lstnew_sw(int number, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = number;
	node->index = index;
	node->init_pos = -1;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

int	ft_atoi_sw(const char *str)
{
	int	sign;
	int	i;
	int	n;

	sign = 1;
	n = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] < 0 || str[i] > 9) && (str[i] != '+' && str[i] != '-'))
			ft_error_exit(NULL, NULL);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * sign);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	node = *lst;
	if (!new || !lst)
		return ;
	if (!node)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(node);
	node->next = new;
	return ;
}