/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:20:26 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/05 17:01:21 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int data;
	int index;
	struct s_stack *prev;
	struct s_stack *next;
	//int	push_cost;
	//bool	abov_median;
	//bool	median;
	//struct s_stack *target_mode;
} t_stack;

int	len_stack(t_stack const *stack);
int	is_sorted(t_stack const *stack);
t_stack	*find_last(t_stack *stack);

void	sort_s(t_stack **a, t_stack **b);

int	ft_isdigit(int c);
int	check_digit(char **array);
int	len_array(char **array);



void	exit_error(char **array);
void	fill_stack_a(t_stack **a, char **array);
t_stack	*stack_new(int value);
void	print_stack(t_stack *stack);

int	check_args(char **array);

int	main(int argc, char *argv[]);

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
