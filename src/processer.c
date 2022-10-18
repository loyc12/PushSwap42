/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/10/18 13:58:57 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Converts the args into ints
long	*lister(long *list, char **args, int lenght)
{
	int	i;

	list = ft_calloc(lenght + 1, sizeof(long));
	i = -1;
	while (args[++i])
		list[i] = ft_atoi(args[i]);
	return (list);
}

// Finds the indexed number of a given value in the list
static int	count_smaller(long *list, long value, int lenght)
{
	int	count;
	int	i;

	i = -1;
	count = 1;
	while (++i < lenght)
		if (list[i] < value)
			count += 1;
	return (count);
}

// Converts the ints into indexed values
long	*indexer(long *list, int lenght)
{
	long	*output;
	int		i;

	output = ft_calloc(lenght, sizeof(int));
	i = -1;
	while (++i < lenght)
		output[i] = count_smaller(list, list[i], lenght);
	free(list);
	return (output);
}
