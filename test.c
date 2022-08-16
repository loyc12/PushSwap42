/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/16 15:10:14 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_range(int lenght)
{
	int i;

	i = 0;
	if (lenght > 9)
		while (++i < lenght + 1)
			if ((i - 1) * (i - 1) < lenght && lenght <= i * i)
				return (2 * i);
	return (1);
}

int	find_step(t_stack *stack_a, int range)
{
	int	r_range;
	int	min_step;
	int max_step;

	r_range = (*stack_a).lenght - 1 - range;
	min_step = look_for(stack_a, 0, range);
	max_step = look_for(stack_a, r_range, (*stack_a).lenght - 1);
	if (min_step * min_step < max_step * max_step)
		min_step = max_step;
	return (min_step);
}

void	take_step(t_stack *stack_a, t_stack *stack_b, int range)
{
	int	step;

	step = find_step(stack_a, range);
	if (0 < step)
		while (0 < step--)
			rr(stack_a, stack_b, 0);
	else if (step < 0)
		while (step++ < 0)
			rrr(stack_a, stack_b, 0);
	pp(stack_a, stack_b, 0);
	if (range < (*stack_b).list[(*stack_b).pos] && (*stack_b).list[1])
		rr(stack_a, stack_b, 1);
}

void	sort_test(t_stack *stack_a, t_stack *stack_b)
{
	int	range_step;
	int	range;
	int	i;

	i = -1;
	range = 1; //find_range((*stack_a).lenght);
	range_step = range;
	while (++i < (*stack_a).lenght)
	{
		if (i % (2 * range_step) == 0)
			range += range_step;
		take_step(stack_a, stack_b, range);
	}
}
