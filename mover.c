/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:11 by llord             #+#    #+#             */
/*   Updated: 2022/08/15 10:57:16 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void shuffle(struct s_bank *bank, int type)
{
	int i;
	
	if (type == 0)			// Type: (0) = down
	{
		i = (*bank).max_lenght;
		while ((*bank).pos < i--)
			(*bank).list[i + 1] = (*bank).list[i];
		(*bank).list[(*bank).pos] = 0;
	}
	else if (type == 1)		// Type: (1) = up
	{
		i = (*bank).pos;
		while (++i < (*bank).max_lenght)
			(*bank).list[i - 1] = (*bank).list[i];
		(*bank).list[i - 1] = 0;
	}
	else
		write(1, " - Bad input (shuffle)", 20);	// For debugging only
}

void	push(struct s_bank *src_bank, struct s_bank *dst_bank)
{
	if ((*dst_bank).lenght < (*dst_bank).max_lenght && 0 < (*src_bank).lenght)
	{
		shuffle(dst_bank, 0);
		(*dst_bank).list[(*dst_bank).pos] = (*src_bank).list[(*src_bank).pos];
		shuffle(src_bank, 1);
		(*dst_bank).lenght++;
		(*src_bank).lenght--;
		if ((*src_bank).pos == (*src_bank).lenght)
			(*src_bank).pos = 0;
	}
	else
		write(1, " - Unable to push", 17);		// For debugging only
}

void	swap(struct s_bank *bank)
{
	int	temp;

	if (1 < (*bank).lenght && (*bank).pos != (*bank).lenght - 1)
	{											// General case
		temp = (*bank).list[(*bank).pos];
		(*bank).list[(*bank).pos] = (*bank).list[(*bank).pos + 1];
		(*bank).list[(*bank).pos + 1] = temp;
	}
	else if (1 < (*bank).lenght && (*bank).pos == (*bank).lenght - 1)
	{											// End-of-list case
		temp = (*bank).list[(*bank).pos];
		(*bank).list[(*bank).pos] = (*bank).list[0];
		(*bank).list[0] = temp;
	}
	else
		write(1, " - Unable to swap", 17);		// For debugging only
}

void	rotate(struct s_bank *bank, int type)
{
	if (type == 0)			// Type: (0) = down
	{
		if (0 < (*bank).pos)
			(*bank).pos--;
		else
			(*bank).pos = (*bank).lenght - 1;
	}
	else if (type == 1)		// Type: (1) = up
	{
		if ((*bank).pos < (*bank).lenght - 1)
			(*bank).pos++;
		else
			(*bank).pos = 0;
	}
	else
		write(1, " - Bad input (rotate)", 21);	// For debugging only
}												// DOES NOT WARN FOR USELESS ROTATES
