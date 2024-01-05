/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:37:14 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/05 17:07:07 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_s(t_stack **a, t_stack **b)
{
	if(len_stack(*a) == 2)
		sa(a);
	else if(len_stack(*a) == 3)
	{
		sort_three(*a);
	}

}
void sort_three(t_stack **a)
{
	printf("en construction");
}


