/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:04:34 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/12 13:25:10 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns the lenght of the stack */
int	len_stack(t_stack const *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
/* Check if the stack is sorted, if not sorted returns 0*/
int	is_sorted(const t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Return the last node of the stack */
t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/* Return the node of the smallest value */
t_stack	*find_smallest_node(t_stack *stack)
{
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest_node = stack;
	while (stack)
	{
		if (smallest_node->data > stack->data)
			smallest_node = stack;
		stack = stack->next;
	}
	return (smallest_node);
}
