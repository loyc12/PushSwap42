/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:11 by llord             #+#    #+#             */
/*   Updated: 2022/08/23 11:28:46 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_in_range(int value, int range_min, int range_max)
{						// ...
	if (range_min <= value && value <= range_max)
		return (1);
	else
		return (0);
}

int	look_down(t_stack *stack, int range_min, int range_max)
{						// Finds the closest value bellow
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
		if (is_in_range((*stack).list[i], range_min, range_max) || i == (*stack).pos)
			break ;
	}
	return (distance);
}

static int	look_up(t_stack *stack, int range_min, int range_max)
{						// Finds the closest value above
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
		if (is_in_range((*stack).list[i], range_min, range_max) || i == (*stack).pos)
			break ;
	}
	return (distance);
}

int	look_for(t_stack *stack, int range_min, int range_max)
{						// Finds the closest value in the stack from a given range of values
	int	distance_down;
	int	distance_up;

	if (range_min <= (*stack).list[(*stack).pos] && (*stack).list[(*stack).pos] <= range_max)
		return (0);
	distance_down = look_down(stack, range_min, range_max);
	distance_up = look_up(stack, range_min, range_max);

	//debug_print_dist(distance_down, distance_up);	// Prints the distances (duh)

	if (-distance_up < distance_down)
		distance_down = distance_up;
	return (distance_down);
}