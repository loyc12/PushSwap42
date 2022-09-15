/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:11 by llord             #+#    #+#             */
/*   Updated: 2022/09/15 14:46:27 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Types : (0) = down : (1) = up
// Makes or removes a space in the list (for push)
static void	shuffle(t_stack *stack, int type)
{
	int	i;

	if (type == 0)
	{
		i = (*stack).max_lenght;
		while ((*stack).pos < i--)
			(*stack).list[i + 1] = (*stack).list[i];
		(*stack).list[(*stack).pos] = 0;
		(*stack).lenght++;
	}
	else if (type == 1)
	{
		i = (*stack).pos;
		while (++i < (*stack).max_lenght)
			(*stack).list[i - 1] = (*stack).list[i];
		(*stack).list[i - 1] = 0;
		(*stack).lenght--;
	}
}

void	push(t_stack *src_stack, t_stack *dst_stack)
{
	if ((*dst_stack).lenght < (*dst_stack).max_lenght \
	&& 0 < (*src_stack).lenght)
	{
		shuffle(dst_stack, 0);
		(*dst_stack).list[(*dst_stack).pos] = \
		(*src_stack).list[(*src_stack).pos];
		shuffle(src_stack, 1);
		if ((*src_stack).pos >= (*src_stack).lenght)
			(*src_stack).pos = 0;
	}
}

void	swap(t_stack *stack)
{
	int	temp;

	if (1 < (*stack).lenght && (*stack).pos != (*stack).lenght - 1)
	{
		temp = (*stack).list[(*stack).pos];
		(*stack).list[(*stack).pos] = (*stack).list[(*stack).pos + 1];
		(*stack).list[(*stack).pos + 1] = temp;
	}
	else if (1 < (*stack).lenght && (*stack).pos == (*stack).lenght - 1)
	{
		temp = (*stack).list[(*stack).pos];
		(*stack).list[(*stack).pos] = (*stack).list[0];
		(*stack).list[0] = temp;
	}
}

// Types : (0) = down : (1) = up
void	rotate(t_stack *stack, int type)
{
	if ((*stack).lenght < 2)
		write(1, " - Unable to rotate", 21);
	else if (type == 0)
	{
		if (0 < (*stack).pos)
			(*stack).pos--;
		else
			(*stack).pos = (*stack).lenght - 1;
	}
	else if (type == 1)
	{
		if ((*stack).pos < (*stack).lenght - 1)
			(*stack).pos++;
		else
			(*stack).pos = 0;
	}
}
