/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:37:14 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/14 21:00:23 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_s(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = len_stack(*a);
	if (len_a == 2)
		sa(a);
	else if (len_a == 3)
	{
		sort_three(a);
	}
	else
	{
		biggy_s(a, b);
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest_node(*a);
	if ((*a) == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
	{
		rra(a);
	}
	if ((*a)->data > (*a)->next->data)
		sa(a);
	return ;
}

t_stack	*find_biggest_node(t_stack *stack)
{
	t_stack	*biggest_node;

	if (!stack)
		return (NULL);
	biggest_node = stack;
	while (stack)
	{
		if (biggest_node->data < stack->data)
			biggest_node = stack;
		stack = stack->next;
	}
	return (biggest_node);
}

int	check_int(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
		else
			result = result * 10 + str[i++] - '0';
	}
	if ((sign * result < -2147483648) || (sign * result > 2147483647))
		return (1);
	return (0);
}

