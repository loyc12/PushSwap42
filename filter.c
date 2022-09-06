/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/09/06 11:30:32 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks if a string is numerical
static int	is_valid(char *string)
{
	int	validity;
	int	i;

	i = -1;
	validity = 1;
	if (string[0] == '-' || string[0] == '+')
	{
		if (!('0' <= string[1] && string[1] <= '9'))
			validity = 0;	// Avoids "-" and "+" being numerical values
		++i;
	}
	while (string[++i])
		if (!('0' <= string[i] && string[i] <= '9'))
			validity = 0;
	return (validity);
}

// Checks if the args are entirely numerical
int	format_filter(char **args, int lenght)
{
	int	validity;
	int	i;

	i = -1;
	validity = 1;
	while (++i < lenght)
	{
		if (!is_valid(args[i]))
			validity = 0;
	}
	if (!validity)
		write(1, "ERROR : Non-numerical values\n", 29);	// Despecify the warning(?)
	return (validity);
}

// Checks if the values are all unique
int	value_filter(int *list, int lenght)
{
	int	validity;
	int	i;
	int	j;

	i = -1;
	validity = 1;
	while (++i < lenght)
	{
		j = -1;
		while (++j < lenght)
			if (list[i] == list[j] && i != j)
				validity = 0;
	}
	if (!validity)
		write(1, "ERROR : Repeated values\n", 24);	// Despecify the warning(?)
	return (validity);
}
