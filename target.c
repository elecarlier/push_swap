/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:21:06 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/07 17:57:12 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	set_current_pos(t_stack **stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	median = len_stack(stack) / 2;
	while (stack)
	{
		stack->current_pos = i;
		if (i <= median)
			stack->abov_median = 1;
		else
			stack->abov_median = 0;
		stack = stack->next;
		i++;
	}
}

static void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = len_stack(a);
	len_b = len_stack(b);
	while (b)
	{
		if (b->abov_median)
			b->price = len_b - b->current_pos;
		else
			b->price = b->current_pos;
		if (b->target_node->abov_median)
			b->price += len_a - b->target_node->current_pos;
		else
			b->price += b->target_node->current_pos;
		b = b->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	int cheap;
	t_stack cheap_node;

	cheap = INT_MAX; //Ppour garantir que la premiere iteration soit toujours vraie
	if (!stack)
		return ;
	while (stack)
	{
		if (cheap > stack->price)
			cheap_node = stack;
		stack = stack->next;
	}
	if (cheap_node)
		cheap_node->is_cheapest = 1;
}

static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*best_friend;
	int	biggest_target_value;

	while (b)
	{
		biggest_target_value = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data
				&& current_a->data < biggest_target_value)
			{
				biggest_target_value = current_a->data;
				best_friend = current_a;
			}
			current_a = current_a->next;
		}
		if (biggest_target_value == INT_MAX)
			b->target_node = find_smallest_node(a);
		else
			b->target_node = best_friend;
	}
}

void	reset_nodes(t_stack *a, t_stack *b)
{
	set_current_pos(a);
	set_current_pos(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}


