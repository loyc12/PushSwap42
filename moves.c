/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:11 by llord             #+#    #+#             */
/*   Updated: 2022/09/15 14:40:43 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Types : (0) = sa : (1) = sb : (3) = ss
void	ss(t_stack *stack_a, t_stack *stack_b, int type)
{
	if (type == 0)
	{
		write(1, "\nsa", 3);
		swap(stack_a);
	}
	else if (type == 1)
	{
		write(1, "\nsb", 3);
		swap(stack_b);
	}
	else if (type == 2)
	{
		write(1, "\nss", 3);
		swap(stack_a);
		swap(stack_b);
	}
}

// Types : (0) = pb : (1) = pa (swapped for convenience)
void	pp(t_stack *stack_a, t_stack *stack_b, int type)
{
	if (type == 0)
	{
		write(1, "\npb", 3);
		push(stack_a, stack_b);
	}
	else if (type == 1)
	{
		write(1, "\npa", 3);
		push(stack_b, stack_a);
	}
}

// Types : (0) = ra : (1) = rb : (3) = rr
void	rr(t_stack *stack_a, t_stack *stack_b, int type)
{
	if (type == 0)
	{
		write(1, "\nra", 3);
		rotate(stack_a, 1);
	}
	else if (type == 1)
	{
		write(1, "\nrb", 3);
		rotate(stack_b, 1);
	}
	else if (type == 2)
	{
		write(1, "\nrr", 3);
		rotate(stack_a, 1);
		rotate(stack_b, 1);
	}
}

// Types : (0) = rra : (1) = rrb : (3) = rrr
void	rrr(t_stack *stack_a, t_stack *stack_b, int type)
{
	if (type == 0)
	{
		write(1, "\nrra", 4);
		rotate(stack_a, 0);
	}
	else if (type == 1)
	{
		write(1, "\nrrb", 4);
		rotate(stack_b, 0);
	}
	else if (type == 2)
	{
		write(1, "\nrrr", 4);
		rotate(stack_a, 0);
		rotate(stack_b, 0);
	}
}
