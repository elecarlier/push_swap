/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:55:36 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/08 20:10:19 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift up all elements of stack a by 1.
The first element becomes the last one */
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
