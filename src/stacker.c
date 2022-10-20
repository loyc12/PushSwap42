/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:13 by llord             #+#    #+#             */
/*   Updated: 2022/10/20 12:04:53 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Initializes stack_a
t_stack	stacker_a(int *flag, long *list)
{
	t_stack	stack_a;
	int		i;

	i = 0;
	while (list[i])
		i++;
	stack_a.list = malloc((i + 1) * sizeof(int));
	stack_a.pos = 0;
	stack_a.lenght = i;
	stack_a.max_lenght = i++;
	while (0 < i--)
		stack_a.list[i] = (int)(list[i]);
	*flag *= 3;
	return (stack_a);
}

// Initializes stack_b (from stack_a)
t_stack	stacker_b(int *flag, int lenght)
{
	t_stack	stack_b;

	stack_b.list = ft_calloc(lenght + 1, sizeof(int));
	stack_b.pos = 0;
	stack_b.lenght = 0;
	stack_b.max_lenght = lenght;
	*flag *= 5;
	return (stack_b);
}
