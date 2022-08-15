/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lister.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/08/11 14:01:44 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lister(int argc, char **argv, int *list)
{
	int	i;
	int	value;
	
	list = ft_calloc(argc, sizeof(int));
	i = -1;
	while (argv[++i + 1])
	{
		value = ft_atoi(argv[i + 1]);
		list[i] = value;
	}
	return (list);
}
