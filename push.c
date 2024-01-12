/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:00 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/12 16:08:07 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	push(t_stack **dest, t_stack **src)
{
	t_stack	*to_push;

	if (!*src)
		return ;
	else
	{
		to_push = *src; //pointe vers le premier elem de src
		*src = (*src)->next; //met a jour la tete de src
		if (*src) //si pas videm met a jour le pointeur
			(*src)->prev = NULL;
		// to_push->prev = NULL;
		if (*dest == NULL)
		{
			*dest = to_push;
			to_push->next = NULL;
		}
		else
		{
			to_push->next = *dest;
			to_push->next->prev = to_push;
			*dest = to_push;
		}
	}
}


/*Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty*/
void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}
/*Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
