/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/10/11 16:47:43 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			validity = 0;
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
	if (!validity || lenght == 0)
		write(1, "ERROR\n", 6);
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
		write(1, "ERROR\n", 6);
	return (validity);
}

// Checks if the values are already sorted
int	is_sorted(int *list, int lenght)
{
	int	i;
	
	i = 0;
	while (++i < lenght)
	{
		if (list[i] < list[i - 1])
			return (0);
	}
	free(list);
	return (1);
}