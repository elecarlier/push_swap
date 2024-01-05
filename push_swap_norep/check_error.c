/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:49:11 by ecarlier          #+#    #+#             */
/*   Updated: 2024/01/05 16:11:03 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

/*int	check_dupplicate(char **array)
{

} */

int	ft_isdigit(int c)
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
	while(array[i])
	{
		i++;
	}
	return (i);
}

int	check_digit(char **array)
{
	int	i;
	int	j;
	int	l_array;

	l_array = len_array(array);
	i = 0;
	while(i < l_array && array[i] != NULL)
	{
		j = 0;
		if (!ft_isdigit(array[i][0]) && array[i][0]!= 43 && array[i][0]!= 45)
			 return (1);//si le premier char n'est pas un digit ou un signe
		j++;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
int main()
{
    char *valid_numbers[] = {"123", "-45", "678", "+9123", NULL};
    char *invalid_numbers[] = {"abc", "12a3", "45.6", "-+"};

    printf("Checking valid numbers:\n");
    if (check_digit(valid_numbers))
    {
        printf("At least one invalid number found.\n");
    }
    else
    {
        printf("All numbers are valid.\n");
    }

    printf("Checking invalid numbers:\n");
    if (check_digit(invalid_numbers))
    {
        printf("At least one invalid number found.\n");
    }
    else
    {
        printf("All numbers are valid.\n");
    }
    return 0;
}
*/

