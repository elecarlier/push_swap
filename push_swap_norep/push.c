/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:00 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/04 21:35:59 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void static	push(t_stack **dst, t_stack **src)
{
	t_stack *first_src;
	t_stack *first_dst;

	if(*src) //if src not empty
	{
		first_src = *src; //pointe vers le premier elem de src
		*src = first_src->next; //met a jour la tete de src

		first_src->next = *dst; //premier elem de src pointe vers la tete de a
		first_src->prev = NULL;

	if(*dst)
		(*dst)->prev = first_src; //si dst pas vide, met a jour prev du second
	*dst = first_src;
	}
}

/*Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty*/
void	pa(t_stack **a, t_stack **b)
{

	push(a,b);
	//printf("pa");
}
/*Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
void	pb(t_stack **b, t_stack **a)
{
	push(b,a);
	//printf("pa");
}
