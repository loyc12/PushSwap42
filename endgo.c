/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/09/15 15:00:59 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts the first 2 values of stack_a if needed
static void	safety_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (1 < (*stack_a).lenght)
		if ((*stack_a).list[1] < (*stack_a).list[0])
			ss(stack_a, stack_b, 0);
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

// Fully sorts the values back into stack_a
void	end_sort(t_stack *stack_a, t_stack *stack_b)
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
		{
			while (0 < step--)
			{
				rr(stack_a, stack_b, 1);
				if (processed_neighbor(stack_a, stack_b, i))
				{
					offset++;
					step--;
				}
			}
		}
		else if (step < 0)
		{
			while (step++ < 0)
			{
				rrr(stack_a, stack_b, 1);
				if (processed_neighbor(stack_a, stack_b, i))
					offset++;
			}
		}
		pp(stack_a, stack_b, 1);
		safety_swap(stack_a, stack_b);
	}
}
