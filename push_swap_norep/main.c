/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:55:07 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/14 21:02:54 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void	fill_stack_a(t_stack **a, char **array);
t_stack	*stack_new(int value);
void	print_stack(t_stack *stack);
int	check_args(char **array);

char	**init_array(t_stack **a, char **argv, int argc, int *flag)
{
	char	**array;
	int	i;

	i = 0;
	*flag = 0;
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		*flag = 1;
	}
	else
		array = argv + 1;
	if (check_args(array))
		exit_error(array, *a, *flag);
	while (array[i])
	{
		if (check_int(array[i]))
			exit_error(array, *a, *flag);
		i++;
	}
	fill_stack_a(a, array);

	if (check_dupplicate(*a))
		exit_error(array, *a, *flag);
	return (array);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**array;
	int	flag;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	array = init_array(&a, argv, argc, &flag);
	print_stack(a); //delete
	if (!is_sorted(a))
		sort_s(&a, &b);
	free_array(array, flag);
	free_stack(a);
	return (0);
}

void	fill_stack_a(t_stack **a, char **array)
{
	long	nb;
	int		i;
	t_stack *new_node;
	t_stack *tmp;

	i = 0;
	while (array[i])
	{
		nb = ft_atoi(array[i]);
		new_node = stack_new((int)nb);
		if (*a)
		{
			tmp = *a;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_node;
			new_node->prev = tmp;
		}
		else
		{
			*a = new_node;
			new_node->prev = NULL;
		}
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
	new_node->abov_median = 0;
	new_node->current_pos = 0;
	new_node->price = 0;
	new_node->is_cheapest = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->target_node = NULL;
	return (new_node);
}



void	free_array(char **array, int flag)
{
	size_t	i;

	i = 0;
	if (flag == 1)
	{
		while (array[i])
			free(array[i++]);
		free(array);
	}
}

void print_stack(t_stack *stack) {
	printf("Stack contents: ");
	while (stack) {
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

