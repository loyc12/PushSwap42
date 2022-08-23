/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_test_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/23 14:28:06 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_range(int lenght)
{						// Finds the optimal range lenght mathematically
	int i;

	i = -1;
	if (lenght > 5)
		while (++i < lenght)
			if ((i) * (i) <= lenght && lenght < (i + 1) * (i + 1))
				return (i);
	return (1);
}

static int	find_step(t_stack *stack, int range, int type)
{						// Finds the closest value in range
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
		write(1, "\n - Bad input (find_step)", 25);
		step = 0;
	}
	return (step);
}

static void	take_step(t_stack *stack_a, t_stack *stack_b, int range)
{						// Goes to a location and pushes
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

static int	is_neighbour(t_stack *stack, int value)
{						// Pushes a value if its next to the wanted value
	if ((*stack).list[(*stack).pos] == value - 1)
		return (1);
	else
		return (0);
}

static void	triple_swap(t_stack *stack_a, t_stack *stack_b)
{						// Sorts the 3 first values of stack_a
	if (1 < (*stack_a).lenght)
	{
		if ((*stack_a).list[1] < (*stack_a).list[0])
			ss(stack_a, stack_b, 0);
		//if ((*stack_a).list[2] < (*stack_a).list[1] && 2 < (*stack_a).lenght)
		//	ss(stack_a, stack_b, 0);
		//if ((*stack_a).list[1] < (*stack_a).list[0] && 2 < (*stack_a).lenght)
		//	ss(stack_a, stack_b, 0);
	}
}

static void	final_sort(t_stack *stack_a, t_stack *stack_b)
{						// Algo to put values back in stack_a
	int	step;
	int	flag;
	int	i;

	flag = 0;
	i = (*stack_a).max_lenght + 1;
	while (0 < --i)
	{
		if (flag)
		{
			flag = 0;
			i--;
		}
		step = find_step(stack_b, i, 1);
		if (0 < step)
			while (0 < step--)
			{
				rr(stack_a, stack_b, 1);
				if (is_neighbour(stack_b, i))
				{
					pp(stack_a, stack_b, 1);
					flag = 1;
					step--;
				}
			}
		else if (step < 0)
			while (step++ < 0)
			{
				rrr(stack_a, stack_b, 1);
				if (is_neighbour(stack_b, i))
				{
					pp(stack_a, stack_b, 1);
					flag = 1;
				}
			}
		pp(stack_a, stack_b, 1);
		triple_swap(stack_a, stack_b);
	}
}

void	sort_test(t_stack *stack_a, t_stack *stack_b)
{						// First sorting algo test
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
	final_sort(stack_a, stack_b);
}
