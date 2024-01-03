/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:55:07 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/03 20:18:14 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void exit_error(char **array);
void fill_stack_a(t_stack **a, char **array);
t_stack *stack_new(int value);
void print_stack(t_stack *stack);

int	main(int argc,char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**array;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		exit_error(NULL);
		return (1);
	}
	else if (argc == 2)
	{
		array = ft_split(argv[1], ' '); //don't forget to free it
	}
	else
		array = argv + 1;
	fill_stack_a(&a, array);
	print_stack(a);
	return (0);
}

void	exit_error(char **array)
{
	write(1, "Error\n", 7);
	if (array)
		free(array);
	exit(EXIT_FAILURE);
	//CAN WE USE EXIT?
}

void	fill_stack_a(t_stack **a, char **array)
{
	long	nb;
	int		i;
	t_stack *new_node;

	i = 0;
	while (array[i])
	{
		nb = atol(array[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(array);
		new_node = stack_new((int)nb);
		if (!new_node)
			exit_error(array);
		if (*a)
		{
			new_node->next = *a;
			(*a)->prev = new_node;
		}
		*a = new_node;
		i++;
	}

}

/* Creates/allocate memory for a new_node*/
t_stack	*stack_new(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->index = 0;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

void print_stack(t_stack *stack) {
    printf("Stack contents: ");
    while (stack) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}
