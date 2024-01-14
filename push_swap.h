/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:20:26 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/14 15:47:38 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	data;
	int	abov_median;
	int	current_pos;
	int	price;
	int	is_cheapest;
	struct	s_stack *prev;
	struct	s_stack *next;
	struct	s_stack *target_node;
} t_stack;

int	check_dupplicate(t_stack *a);
void print_stack_bis(t_stack **stack);
void	biggy_s(t_stack **a, t_stack **b);
t_stack	*return_cheap(t_stack *b);
void	finish_the_job(t_stack **stack, t_stack *node, char stack_name);

int	ft_isdigit_(int c);
int	check_digit(char **array);
int	len_array(char **array);

int	len_stack(t_stack const *stack);
int	is_sorted(t_stack const *stack);
t_stack	*find_last(t_stack *stack);
t_stack	*find_smallest_node(t_stack *stack);

void	reset_nodes(t_stack *a, t_stack *b);
void	set_current_pos(t_stack *stack);

void	sort_s(t_stack **a, t_stack **b);
t_stack	*find_biggest_node(t_stack *stack);
void sort_three(t_stack **a);

int	main(int argc, char *argv[]);
void	exit_error();
void	fill_stack_a(t_stack **a, char **array);
t_stack	*stack_new(int value);
void print_stack(t_stack *stack);
int	check_args(char **array);


void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
#endif
