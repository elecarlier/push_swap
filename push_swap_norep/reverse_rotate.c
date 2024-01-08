/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:47:17 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/08 15:17:33 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Shift down all elements of stack a by 1.
The last element becomes the first one.*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
