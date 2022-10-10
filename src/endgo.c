/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/10/10 14:54:11 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Sorts the first 2 values of stack_a if needed
static void	safety_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (1 < (*stack_a).lenght)
		if ((*stack_a).list[1] < (*stack_a).list[0])
			ss(stack_a, stack_b, 0);
}

// Rotates stack_b and pushes a value if its the next one needed
static int	roll_by_one(t_stack *stack_a, t_stack *stack_b, int value, int type)
{
	if (type == 0)
		rr(stack_a, stack_b, 1);
	else if (type == 1)
		rrr(stack_a, stack_b, 1);
	if ((*stack_b).list[(*stack_b).pos] == value - 1)
	{
		pp(stack_a, stack_b, 1);
		return (1);
	}
	return (0);
}

static void	take_end_step(t_stack *stack_a, t_stack *stack_b, int *val, int *i)
{
	int	step;

	step = find_step(stack_b, *val, 1);
	if (0 < step)
	{
		while (0 < step--)
		{
			if (roll_by_one(stack_a, stack_b, *val, 0))
			{
				(*i)++;
				step--;
			}
		}
	}
	else if (step < 0)
	{
		while (step++ < 0)
		{
			if (roll_by_one(stack_a, stack_b, *val, 1))
				(*i)++;
		}
	}
}

// Fully sorts the values back into stack_a
void	end_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	value;
	int	i;

	i = 0;
	value = (*stack_a).max_lenght + 1;
	while (0 < --value && 0 < (*stack_b).lenght)
	{
		if (i)
		{
			value -= i;
			i = 0;
		}
		take_end_step(stack_a, stack_b, &value, &i);
		pp(stack_a, stack_b, 1);
		safety_swap(stack_a, stack_b);
	}
}
