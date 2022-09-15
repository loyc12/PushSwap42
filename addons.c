/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addons.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/09/15 14:54:51 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// copies the first 3 values of a stack int a malloc'd array
int	*get_three(t_stack *stack)
{
	int	*truple;
	int	pos;
	int	i;

	truple = ft_calloc(4, sizeof(int));
	if (!truple)
		return (NULL);
	i = 0;
	pos = (*stack).pos;
	while (i < 3)
	{
		truple[i++] = (*stack).list[pos++];
		if (2 < pos)
			pos = 0;
	}
	return (truple);
}

// rotates stack_a to the demanded value
void	go_to(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	step;

	step = find_step(stack_a, value, 1);
	if (0 < step)
		while (0 < step--)
			rr(stack_a, stack_b, 0);
	else if (step < 0)
		while (step++ < 0)
			rrr(stack_a, stack_b, 0);
}

// Finds the closest value in range and gives its relative location
int	find_step(t_stack *stack, int range, int type)
{
	int	middle;
	int	step;
	int	add;

	if (type == 0)
	{
		add = 0;
		middle = ((*stack).max_lenght + 1) / 2;
		if ((*stack).max_lenght % 2)
			add++;
		step = look_for(stack, middle - range + 1, middle + range - add);
	}
	else if (type == 1)
		step = look_for(stack, range, range);
	else
	{
		write(1, "\n - Bad type (find_step)", 24);
		step = 0;
	}
	return (step);
}
