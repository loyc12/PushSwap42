/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:11 by llord             #+#    #+#             */
/*   Updated: 2022/08/11 15:33:59 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(struct s_bank *bank_a, struct s_bank *bank_b, int type)
{
	if (type == 0)			// Type: (0) = sa
	{
		write(1, "\nsa", 3);
		swap(bank_a);
	}
	else if (type == 1)		// Type: (1) = sb
	{
		write(1, "\nsb", 3);
		swap(bank_b);
	}
	else if (type == 2)		// Type: (2) = ss
	{
		write(1, "\nss", 3);
		swap(bank_a);
		swap(bank_b);
	}
	else
		write(1, "\n - Bad input (ss)", 18);	// For debugging only
}

void	pp(struct s_bank *bank_a, struct s_bank *bank_b, int type)
{							// Swapped for convenience
	if (type == 0)			// Type: (0) = pb
	{
		write(1, "\npb", 3);
		push(bank_a, bank_b);
	}
	else if (type == 1)		// Type: (1) = pa
	{
		write(1, "\npa", 3);
		push(bank_b, bank_a);
	}
	else
		write(1, "\n - Bad input (pp)", 18);	// For debugging only
}

void	rr(struct s_bank *bank_a, struct s_bank *bank_b, int type)
{
	if (type == 0)			// Type: (0) = ra
	{
		write(1, "\nra", 3);
		rotate(bank_a, 1);
	}
	else if (type == 1)		// Type: (1) = rb
	{
		write(1, "\nrb", 3);
		rotate(bank_b, 1);
	}
	else if (type == 2)		// Type: (2) = rr
	{
		write(1, "\nrr", 3);
		rotate(bank_a, 1);
		rotate(bank_b, 1);
	}
	else
		write(1, "\n - Bad input (rr)", 18);	// For debugging only
}

void	rrr(struct s_bank *bank_a, struct s_bank *bank_b, int type)
{
	if (type == 0)			// Type: (0) = rra
	{
		write(1, "\nrra", 4);
		rotate(bank_a, 0);
	}
	else if (type == 1)		// Type: (1) = rrb
	{
		write(1, "\nrb", 4);
		rotate(bank_b, 0);
	}
	else if (type == 2)		// Type: (2) = rrr
	{
		write(1, "\nrrr", 4);
		rotate(bank_a, 0);
		rotate(bank_b, 0);
	}
	else
		write(1, "\n - Bad input (rrr)", 18);	// For debugging only
}