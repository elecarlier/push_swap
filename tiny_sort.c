/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:37:14 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/07 16:02:45 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_s(t_stack **a, t_stack **b)
{
	if (len_stack(*a) == 2)
		sa(a);
	else if (len_stack(*a) == 3)
	{
		sort_three(a);
	}
	else
		biggy_sort(a);
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
