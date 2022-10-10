/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biglo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/10/10 14:54:11 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Finds the optimal range from a given list range
static int	find_range(int lenght)
{
	int	i;

	i = -1;
	if (lenght > 5)
	{
		while (++i <= (lenght / 2))
		{
			if ((i) * (i) <= lenght && lenght <= (i) * (i + 1))
				return (i + 1);
			if ((i) * (i + 1) < lenght && lenght < (i + 1) * (i + 1))
				return (i + 2);
		}
	}
	return (1);
}

// Goes to a location and pushes
static void	take_step(t_stack *stack_a, t_stack *stack_b, int range)
{
	int	step;

	step = find_step(stack_a, range, 0);
	if (0 < step)
		while (0 < step--)
			rr(stack_a, stack_b, 0);
	else if (step < 0)
		while (step++ < 0)
			rrr(stack_a, stack_b, 0);
	if (0 < range)
	{
		pp(stack_a, stack_b, 0);
		if (((*stack_b).max_lenght / 2) + 1 < (*stack_b).list[(*stack_b).pos] \
		&& (*stack_a).list[0] && (*stack_b).list[1])
			rr(stack_a, stack_b, 1);
	}
}

// Presorts the values (by range) into stack_b
void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	range_step;
	int	range;
	int	i;

	i = -1;
	range = 0;
	range_step = find_range((*stack_a).lenght);
	if ((*stack_a).max_lenght % 2)
		i++;
	while ((*stack_a).list[0] != 0)
	{
		range += range_step;
		while (++i < range * 2 && (*stack_a).list[0] != 0)
			take_step(stack_a, stack_b, range);
		i--;
	}
	end_sort(stack_a, stack_b);
}
