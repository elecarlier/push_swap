/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:04:34 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/05 15:06:41 by ecarlier         ###   ########.fr       */
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
	if(!stack)
		return (1);
	while(stack->next)
	{
		if(stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
t_stack	*find_last(t_stack *stack)
{
	if(!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
