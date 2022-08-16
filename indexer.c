/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/08/16 09:18:29 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(int *list, int value, int lenght)
{							// Finds the indexed number of a given value
	int	i;
	int	count;

	i = -1;
	count = 1;
	while (++i < lenght)
		if (list[i] < value)
			count += 1;
	return (count);
}

int	*indexer(int *list, int lenght)
{							// Converts the ints into indexed values
	int	i;
	int	*output;

	output = ft_calloc(lenght, sizeof(int));
	i = -1;
	while (++i < lenght)
		output[i] = count_smaller(list, list[i], lenght);
	free(list);
	return (output);
}
