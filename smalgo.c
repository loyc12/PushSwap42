/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/09/06 13:45:22 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts the 3 first values of stack_a (used karnaugh map)
void	sort_three_a(t_stack *stack_a, t_stack *stack_b)
{
	int	*lst;	// !!!\ Copy list over so it doesn't change midway !!!

	lst = (*stack_a).list;
	if (((lst[2] < lst[1]) && !(lst[2] < lst[0])) || \
		((lst[1] < lst[0]) && !(lst[2] < lst[0])) || \
		((lst[1] < lst[0]) && (lst[2] < lst[1])))
		ss(stack_a, stack_b, 0);
	if ((!(lst[2] < lst[1]) && (lst[2] < lst[0])) || \
		((lst[2] < lst[1]) && !(lst[2] < lst[0])))
		rr(stack_a, stack_b, 0);
	else if (((lst[2] < lst[1]) && (lst[2] < lst[0])))
		rrr(stack_a, stack_b, 0);
}

// Sorts the 3 first values of stack_b (used karnaugh map)
void	sort_three_b(t_stack *stack_a, t_stack *stack_b)
{
	int	*lst;	// !!!\ Copy list over so it doesn't change midway !!!

	lst = (*stack_a).list;
	if (((lst[2] < lst[1]) && !(lst[2] < lst[0])) || \
		((lst[1] < lst[0]) && !(lst[2] < lst[0])) || \
		((lst[1] < lst[0]) && (lst[2] < lst[1])))
		ss(stack_a, stack_b, 1);
	if ((!(lst[2] < lst[1]) && (lst[2] < lst[0])) || \
		((lst[2] < lst[1]) && !(lst[2] < lst[0])))
		rr(stack_a, stack_b, 1);
	else if (((lst[2] < lst[1]) && (lst[2] < lst[0])))
		rrr(stack_a, stack_b, 1);
}

// Types : (0) = a : (1) = b : (2) = both
// Sorts the 3 first values of (a) stack(s)
void	sort_three(t_stack *stack_a, t_stack *stack_b, int type)
{
	int	*lst_a;
	int	*lst_b;

	lst_a = (*stack_a).list;
	lst_b = (*stack_a).list;
	if (0 <= type && type <= 2)
	{
		if (type != 1)
			sort_three_a(stack_a, stack_b);
		if (type != 0)
			sort_three_b(stack_a, stack_b);
	}
	else
		write(1, "\n - Bad input (sort3)", 20);	// For debugging only
}
/*
// Sorts the 3 first values (using karnaugh maps)
void	merge_sorted(t_stack *stack_a, t_stack *stack_b)
{

}
*/