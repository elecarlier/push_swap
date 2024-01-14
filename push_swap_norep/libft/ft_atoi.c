/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:55:36 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/14 20:53:46 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			error();
		else
			result = result * 10 + str[i++] - '0';
	}
	if ((sign * result < -2147483648) || (sign * result > 2147483647))
		error();
	return (sign * result);
}
