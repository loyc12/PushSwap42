/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lister.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/09/06 11:28:59 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Converts the args into ints
int	*lister(int *list, char **args, int lenght)
{
	int	i;
	int	value;

	list = ft_calloc(lenght + 1, sizeof(int));
	i = -1;
	while (args[++i])
	{
		value = ft_atoi(args[i]);
		list[i] = value;
	}
	return (list);
}
