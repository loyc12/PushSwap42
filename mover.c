/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:11 by llord             #+#    #+#             */
/*   Updated: 2022/08/16 09:43:56 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void shuffle(struct s_stack *stack, int type)
{							// Makes / remove a space in the list (for push)
	int i;
	
	if (type == 0)			// Type : (0) = down
	{
		i = (*stack).max_lenght;
		while ((*stack).pos < i--)
			(*stack).list[i + 1] = (*stack).list[i];
		(*stack).list[(*stack).pos] = 0;
	}
	else if (type == 1)		// Type : (1) = up
	{
		i = (*stack).pos;
		while (++i < (*stack).max_lenght)
			(*stack).list[i - 1] = (*stack).list[i];
		(*stack).list[i - 1] = 0;
	}
	else
		write(1, " - Bad input (shuffle)", 20);	// For debugging only
}

void	push(struct s_stack *src_stack, struct s_stack *dst_stack)
{
	if ((*dst_stack).lenght < (*dst_stack).max_lenght && 0 < (*src_stack).lenght)
	{
		shuffle(dst_stack, 0);
		(*dst_stack).list[(*dst_stack).pos] = (*src_stack).list[(*src_stack).pos];
		shuffle(src_stack, 1);
		(*dst_stack).lenght++;
		(*src_stack).lenght--;
		if ((*src_stack).pos == (*src_stack).lenght)
			(*src_stack).pos = 0;
	}
	else
		write(1, " - Unable to push", 17);		// For debugging only
}

void	swap(struct s_stack *stack)
{
	int	temp;

	if (1 < (*stack).lenght && (*stack).pos != (*stack).lenght - 1)
	{											// General case
		temp = (*stack).list[(*stack).pos];
		(*stack).list[(*stack).pos] = (*stack).list[(*stack).pos + 1];
		(*stack).list[(*stack).pos + 1] = temp;
	}
	else if (1 < (*stack).lenght && (*stack).pos == (*stack).lenght - 1)
	{											// End-of-list case
		temp = (*stack).list[(*stack).pos];
		(*stack).list[(*stack).pos] = (*stack).list[0];
		(*stack).list[0] = temp;
	}
	else
		write(1, " - Unable to swap", 17);		// For debugging only
}

void	rotate(struct s_stack *stack, int type)
{
	if (type == 0)			// Type : (0) = down
	{
		if (0 < (*stack).pos)
			(*stack).pos--;
		else				// Start-of-list case
			(*stack).pos = (*stack).lenght - 1;
	}
	else if (type == 1)		// Type : (1) = up
	{
		if ((*stack).pos < (*stack).lenght - 1)
			(*stack).pos++;
		else				// End-of-list case
			(*stack).pos = 0;
	}
	else
		write(1, " - Bad input (rotate)", 21);	// For debugging only
}												// DOES NOT WARN FOR USELESS ROTATES !!!
