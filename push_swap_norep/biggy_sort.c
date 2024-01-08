/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggy_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:24:52 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/08 20:10:39 by ecarlier         ###   ########.fr       */
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

	len_a = len_stack(*a);
	while (len_a-- > 3)
		pb(b, a);
	sort_three(a);
	print_stack_bis(a);
	print_stack_bis(b);
	while (*b)
	{

		reset_nodes(*a, *b);
		move_nodes(a,b);
		pa(a, b);
	}
}



static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = return_cheap(*b);

	printf("Cheapest Node Parameters:\n");
    // printf("Data: %d\n", cheapest->data);
    // printf("Above Median: %d\n", cheapest->abov_median);
    // printf("Current Position: %d\n", cheapest->current_pos);
    // printf("Price: %d\n", cheapest->price);
    // printf("Is Cheapest: %d\n", cheapest->is_cheapest);

	if (cheapest->target_node->abov_median && cheapest->abov_median) //both above the median
	{
		printf("1\n");
		while (*a != cheapest->target_node || *b != cheapest)
			rrr(a,b);
		while (*a != cheapest->target_node)
			rra(a);
		while (*b != cheapest)
			rrb(b);
	}
	else if (!(cheapest->target_node->abov_median) && !(cheapest->abov_median)) //both under the median
	{
		printf("2\n");
		while (*a != cheapest->target_node || *b != cheapest)
			rr(a,b);
		while (*a != cheapest->target_node)
			ra(a);
		while (*b != cheapest)
			rb(b);
	}
	else
		special_cases(a,b, cheapest);
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
			return (b);
		b = b->next;
	}

	return (NULL);
}
