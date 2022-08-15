/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/08/11 14:00:29 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(int *list, int value, int len)
{
	int	i;
	int	count;

	i = -1;
	count = 1;
	while (++i < len)
		if (list[i] < value)
			count += 1;
	return (count);
}

int	*indexer(int *list, int len)
{
	int	i;
	int	*output;

	output = ft_calloc(len, sizeof(int));
	i = -1;
	while (++i < len)
		output[i] = count_smaller(list, list[i], len);
	free(list);
	return (output);
}
