/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/08/11 15:33:50 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(char *string)
{
	int	validity;
	int	i;

	i = -1;
	validity = 1;
	if (string[0] == '-' || string[0] == '+')
		++i;
	while (string[++i])
		if (!('0' <= string[i] && string[i] <= '9'))
			validity = 0;
	return (validity);
}

int format_filter(int argc, char **argv)
{
	int	validity;
	int	i; 

	i = 0;
	validity = 1;
	while (++i < argc)
	{
		if (!is_valid(argv[i]))
			validity = 0;
	}
	if (!validity)
		write(1, "ERROR\n", 6);
	return (validity);
}

int value_filter(int *list, int len)
{
	int	validity;
	int	i;
	int	j;

	i = -1;
	validity = 1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			if (list[i] == list[j] && i != j)
				validity = 0;
	}
	if (!validity)
		write(1, "ERROR\n", 6);
	return (validity);
}
