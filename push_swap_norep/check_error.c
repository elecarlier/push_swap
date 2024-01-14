/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:49:11 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/14 20:35:04 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dupplicate(t_stack *a)
{
	t_stack	*temp;
	int		nb;

	if (!a)
		return (0);
	while (a && (a)->next)
	{
		nb = a->data;
		temp = a->next;
		while (temp)
		{
			if (nb == temp->data)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ft_isdigit_(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	len_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

int	check_args(char **array)
{
	int	i;
	int	j;
	int	l_array;

	l_array = len_array(array);
	i = 0;
	while (i < l_array && array[i] != NULL)
	{
		if ((array[i][0] == 43 || array[i][0] == 45) && (!array[i][1]))
			return (1);
		j = 0;
		if (!ft_isdigit_(array[i][0]) && array[i][0] != 43 && array[i][0] != 45)
			return (1);
		j++;
		while (array[i][j])
		{
			if (!ft_isdigit_(array[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	exit_error(char **array, t_stack *stack, int flag)
{
	if (stack)
		free_stack(stack);
	if (array && flag)
		free_array(array, flag);
	write(1, "Error\n", 6);
	exit(1);
}
