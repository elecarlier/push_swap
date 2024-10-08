/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggy_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:24:52 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/14 18:38:01 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_nodes(t_stack **a, t_stack **b);

void	biggy_s(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;
	int		len_a;

	len_a = len_stack(*a);
	while (len_a-- > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		reset_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_pos(*a);
	smallest_node = find_smallest_node(*a);
	if (smallest_node->abov_median)
	{
		while (*a != smallest_node)
			ra(a);
	}
	else
	{
		while (*a != smallest_node)
			rra(a);
	}
}

void	finish_the_job(t_stack **stack, t_stack *node, char stack_name)
{
	t_stack	*first;

	while (*stack != node)
	{
		first = *stack;
		if (stack_name == 'a')
		{
			if (node->abov_median)
				ra(stack);
			else if (!(node->abov_median))
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (node->abov_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = return_cheap(*b);
	if (cheapest->target_node->abov_median && cheapest->abov_median)
	{
		while (*a != cheapest->target_node && *b != cheapest)
		{
			rr(a, b);
			set_current_pos(*a);
			set_current_pos(*b);
		}
	}
	else if (!(cheapest->target_node->abov_median) && !(cheapest->abov_median))
	{
		while (*a != cheapest->target_node && *b != cheapest)
		{
			rrr(a, b);
			set_current_pos(*a);
			set_current_pos(*b);
		}
	}
	finish_the_job(b, cheapest, 'b');
	finish_the_job(a, cheapest->target_node, 'a');
	pa(a, b);
}

t_stack	*return_cheap(t_stack *b)
{
	if (!b)
		return (NULL);
	while (b)
	{
		if (b->is_cheapest)
			return (b);
		b = b->next;
	}
	return (NULL);
}
