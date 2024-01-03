/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:20:26 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/03 17:24:58 by ecarlier         ###   ########.fr       */
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

#endif
