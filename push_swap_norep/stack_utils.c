/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:04:34 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/09 22:26:41 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*Est-ce que le plus petit est pas toujours le premier ? */
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
