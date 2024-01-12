/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggy_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:24:52 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/12 15:54:49 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_nodes(t_stack **a, t_stack **b);

void print_stack_bis(t_stack **stack) {
	t_stack *temp;

	temp = *stack;
	printf("Stack contents: ");
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void	biggy_s(t_stack **a, t_stack **b)
{
	int	len_a;
	t_stack	*smallest_node;

	len_a = len_stack(*a);
	while (len_a-- > 3)
		pb(a, b);
	sort_three(a);
	print_stack_bis(a);
	while (*b)
	{
		reset_nodes(*a, *b);
		move_nodes(a, b);
		print_stack_bis(a);
		print_stack_bis(b);
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
	t_stack *first;

	while (*stack != node)
	{
		first = *stack;
		//printf("top node value %i \n", first->data);
		if (stack_name == 'a')
		{
			printf("cheapest : %i\n", node->data);
			print_stack_bis(stack);
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
	printf("cheapest value %i \n", cheapest->data);
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
	printf("cheapest target value %i \n", cheapest->target_node->data);

	finish_the_job(b, cheapest, 'b'); //rotate b until cheapest is at the top
	finish_the_job(a, cheapest->target_node, 'a'); //rotate a until the target node is at the top
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
