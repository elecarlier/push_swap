/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggy_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:24:52 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/09 23:29:45 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_nodes(t_stack **a, t_stack **b);
static void	special_cases(t_stack **a, t_stack **b, t_stack *cheapest);


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
	print_stack_bis(b);
	while (*b)
	{

		reset_nodes(*a, *b);
		move_nodes(a,b);
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
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->abov_median)
				ra(stack);
			else
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
	if (cheapest->target_node->abov_median && cheapest->abov_median) //both above the median
	{
		while (*a != cheapest->target_node && *b != cheapest)
		{
			rr(a,b);
			set_current_pos(*a);
			set_current_pos(*b);
		}
	}
	else if (!(cheapest->target_node->abov_median) && !(cheapest->abov_median)) //both under the median
	{
		while (*a != cheapest->target_node && *b != cheapest)
		{
			rrr(a,b);
			set_current_pos(*a);
			set_current_pos(*b);
		}
	}
	finish_the_job(b, cheapest, 'b');
	finish_the_job(a, cheapest->target_node, 'a');
	pa(a,b);
}


static void	special_cases(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while(*a != cheapest->target_node && *b != cheapest)
	{
		printf("3\n");
		if (cheapest->target_node->abov_median && *a != cheapest->target_node)
			ra(a);
		else if (!(cheapest->target_node->abov_median) && *a != cheapest->target_node)
			rra(a);
		if (cheapest->abov_median && *b != cheapest)
			rb(b);
		else if (!(cheapest->abov_median) && *b != cheapest)
			rrb(b);
	}
}

t_stack	*return_cheap(t_stack *b)
{
	if (!b)
		return (NULL);

	while (b)
	{
		if (b->is_cheapest)
		{
			return (b);
			printf("Value of the cheapest : %i", b->data);
		}

		b = b->next;
	}

	return (NULL);
}
