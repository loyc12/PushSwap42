/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biglo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/09/14 16:31:58 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the optimal range from a given list range
int	find_range(int lenght)
{
	int i;

	i = -1;
	if (lenght > 5)
		while (++i <= (lenght / 2))
		{
			if ((i) * (i) <= lenght && lenght <= (i) * (i + 1))
				return (i + 1);
			if ((i) * (i + 1) < lenght && lenght < (i + 1) * (i + 1))
				return (i + 2);
		}
	return (1);
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
		step = look_for(stack, range, range); // + 1);
	else
	{
		write(1, "\n - Bad type (find_step)", 24);
		step = 0;
	}
	return (step);
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

// Pushes a value if its the next one needed
static int	processed_neighbor(t_stack *stack_a, t_stack *stack_b, int value)
{

	if ((*stack_b).list[(*stack_b).pos] == value - 1)
	{
		pp(stack_a, stack_b, 1);
		return (1);
	}
	return (0);
}

// Sorts the first 2 values of stack_a if needed
static void	safety_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (1 < (*stack_a).lenght)
		if ((*stack_a).list[1] < (*stack_a).list[0])
			ss(stack_a, stack_b, 0);
}

// Fully sorts the values back into stack_a
static void	final_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	step;
	int	offset;
	int	i;

	offset = 0;
	i = (*stack_a).max_lenght + 1;
	while (0 < --i && 0 < (*stack_b).lenght)
	{
		if (offset)
		{
			i -= offset;
			offset = 0;
		}
		step = find_step(stack_b, i, 1);
		if (0 < step)
			while (0 < step--)
			{
				rr(stack_a, stack_b, 1);
				if (processed_neighbor(stack_a, stack_b, i))
				{
					offset++;
					step--;
				}
			}
		else if (step < 0)
			while (step++ < 0)
			{
				rrr(stack_a, stack_b, 1);
				if (processed_neighbor(stack_a, stack_b, i))
					offset++;
			}
		pp(stack_a, stack_b, 1);
		safety_swap(stack_a, stack_b);
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
	final_sort(stack_a, stack_b);
}
