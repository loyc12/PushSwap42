/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:11 by llord             #+#    #+#             */
/*   Updated: 2022/09/15 15:21:56 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if a value is inside a given range
static int	is_in_range(int value, int range_min, int range_max)
{
	if (range_min <= value && value <= range_max)
		return (1);
	else
		return (0);
}

// finds the closest value (to given range of values) bellow the position
static int	look_down(t_stack *stack, int range_min, int range_max)
{
	int	i;
	int	distance;

	i = (*stack).pos;
	distance = 0;
	while (1)
	{
		i++;
		distance++;
		if ((*stack).lenght - 1 < i)
			i = 0;
		if (is_in_range((*stack).list[i], range_min, range_max))
			break ;
		if (i == (*stack).pos)
			break ;
	}
	return (distance);
}

// Finds the closest value (to given range of values) above the position
static int	look_up(t_stack *stack, int range_min, int range_max)
{
	int	i;
	int	distance;

	i = (*stack).pos;
	distance = 0;
	while (1)
	{
		i--;
		distance--;
		if (i < 0)
			i = (*stack).lenght - 1;
		if (is_in_range((*stack).list[i], range_min, range_max))
			break ;
		if (i == (*stack).pos)
			break ;
	}
	return (distance);
}

// Finds the closest value )to given range of values) in the stack
// and returns the relative location (steps)
int	look_for(t_stack *stack, int range_min, int range_max)
{						
	int	distance_down;
	int	distance_up;
	int	value;

	value = (*stack).list[(*stack).pos];
	if (range_min <= value && value <= range_max)
		return (0);
	distance_down = look_down(stack, range_min, range_max);
	distance_up = look_up(stack, range_min, range_max);
	if (-distance_up < distance_down)
		distance_down = distance_up;
	return (distance_down);
}
