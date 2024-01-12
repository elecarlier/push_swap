/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:08:18 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/12 13:27:30 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (*stack && (*stack)->next)
	{	//check if there is at least 2 elements
		first = *stack; //pointe vers le premier element
		second = first->next; //pointe vers le deuxieme
		first->next = second->next;
		second->next = first;
		first->prev = second;
		second->prev = NULL;
		*stack = second;
	}
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}


void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}


void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
