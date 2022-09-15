/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/09/15 14:28:37 by llord            ###   ########.fr       */
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

// Finds the indexed number of a given value in the list
static int	count_smaller(int *list, int value, int lenght)
{
	int	i;
	int	count;

	i = -1;
	count = 1;
	while (++i < lenght)
		if (list[i] < value)
			count += 1;
	return (count);
}

// Converts the ints into indexed values
int	*indexer(int *list, int lenght)
{
	int	i;
	int	*output;

	output = ft_calloc(lenght, sizeof(int));
	i = -1;
	while (++i < lenght)
		output[i] = count_smaller(list, list[i], lenght);
	free(list);
	return (output);
}

// Initializes stack_a
t_stack	stacker_a(int *list)
{
	t_stack	stack_a;
	int		i;

	i = 0;
	while (list[i])
		i++;
	stack_a.list = list;
	stack_a.pos = 0;
	stack_a.lenght = i;
	stack_a.max_lenght = i;
	return (stack_a);
}

// Initializes stack_b (from stack_a)
t_stack	stacker_b(int lenght)
{
	t_stack	stack_b;
	int		*empty_list;

	empty_list = ft_calloc(lenght + 1, sizeof(int));
	stack_b.list = empty_list;
	stack_b.pos = 0;
	stack_b.lenght = 0;
	stack_b.max_lenght = lenght;
	return (stack_b);
}
