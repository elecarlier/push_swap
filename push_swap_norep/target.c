/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:21:06 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/08 20:13:29 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>


void print_stack_values(const char *label, t_stack *stack);
static void	set_current_pos(t_stack **stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = len_stack(*stack) / 2;
	while (*stack)
	{
		(*stack)->current_pos = i;
		if (i <= median)
			(*stack)->abov_median = 1;
		else
			(*stack)->abov_median = 0;
		(*stack) = (*stack)->next;
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
	t_stack *cheap_node;

	cheap_node = NULL;
	cheap = INT_MAX; //Ppour garantir que la premiere iteration soit toujours vraie
	if (!stack)
	{
		printf("askip le stack est vide dans set cheapest\n");
		return ;
	}

	while (stack)
	{

		if (cheap > stack->price)
			cheap_node = stack;
		stack = stack->next;
	}
	if (cheap_node)
		cheap_node->is_cheapest = 1;
	printf("is_cheapest %d", cheap_node->is_cheapest);
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
		best_friend = NULL;
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
	printf(";li\n");


	printf("before set_current_pos(&a); \n");
	set_current_pos(&a);
	printf("before	set_current_pos(&b);\n");

	set_current_pos(&b);

	if (!b)
		printf("b is empty in reset_mode\n");
	else
		printf("b is not empty in reset_mode");

	//printf("before set target;");
	set_target(a, b);

	//printf("before set price \n");
	set_price(a, b);
	//printf("before set cheapest \n");

	set_cheapest(b);
	//printf("after set cheapest \n");
}

