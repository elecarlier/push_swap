/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:47:17 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/12 16:25:36 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Shift down all elements of stack a by 1.
The last element becomes the first one.*/

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	//print_stack_bis(stack);
	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	first->prev = last;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	*stack = last;
	//set_current_pos(*stack);
	// printf("Inside reverse rotation\n");
	print_stack_bis(stack);
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1,"rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
