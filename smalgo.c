/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/09/14 16:34:51 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_three(t_stack *stack)
{
	int	*truple;
	int	pos;
	int	i;

	truple = ft_calloc(4, sizeof(int));
	if (!truple)
		return (NULL);
	i = 0;
	pos = (*stack).pos;
	while (i < 3)
	{
		truple[i++] = (*stack).list[pos++];
		if (2 < pos)
			pos = 0;
	}
	return (truple);
}

// Sorts the 3 first values of stack_a (used karnaugh map)
static void	sort_three_a(t_stack *stack_a, t_stack *stack_b)
{
	int	*lst;

	lst = get_three(stack_a);
	if (((lst[2] < lst[1]) && !(lst[2] < lst[0])) || \
		((lst[1] < lst[0]) && !(lst[2] < lst[0])) || \
		((lst[1] < lst[0]) && (lst[2] < lst[1])))
		ss(stack_a, stack_b, 0);
	if ((!(lst[2] < lst[1]) && (lst[2] < lst[0])) || \
		((lst[2] < lst[1]) && !(lst[2] < lst[0])))
		rr(stack_a, stack_b, 0);
	else if (((lst[2] < lst[1]) && (lst[2] < lst[0])))
		rrr(stack_a, stack_b, 0);
	free(lst);
}

// Sorts the 3 first values of stack_b (used karnaugh map)
static void	sort_three_b(t_stack *stack_a, t_stack *stack_b)
{
	int	*lst;

	lst = get_three(stack_b);
	if (((lst[2] < lst[1]) && !(lst[2] < lst[0])) || \
		((lst[1] < lst[0]) && !(lst[2] < lst[0])) || \
		((lst[1] < lst[0]) && (lst[2] < lst[1])))
		ss(stack_a, stack_b, 1);
	if ((!(lst[2] < lst[1]) && (lst[2] < lst[0])) || \
		((lst[2] < lst[1]) && !(lst[2] < lst[0])))
		rr(stack_a, stack_b, 1);
	else if (((lst[2] < lst[1]) && (lst[2] < lst[0])))
		rrr(stack_a, stack_b, 1);
	free(lst);
}

// rotates stack_a to the demanded value
void	go_to(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	step;

	step = find_step(stack_a, value, 1);
	if (0 < step)
		while (0 < step--)
			rr(stack_a, stack_b, 0);
	else if (step < 0)
		while (step++ < 0)
			rrr(stack_a, stack_b, 0);
}

//split superfluous values into stack_b
static void	unmerge(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	while (3 < (*stack_a).lenght)
	{
		value = (*stack_a).list[(*stack_a).pos];
		if (value < (*stack_a).max_lenght - 2)
			pp(stack_a, stack_b, 0);
		else
			rr(stack_a, stack_b, 0);
	}
}

//merges stack_a and stack_b back together
static void	merge(t_stack *stack_a, t_stack *stack_b)
{
	if (2 < (*stack_b).lenght)
	{
		rrr(stack_a, stack_b, 1);
		pp(stack_a, stack_b, 1);
	}
	if (1 < (*stack_b).lenght)
	{
		if ((*stack_b).list[(*stack_b).pos] == 1)
			ss(stack_a, stack_b, 1);
		pp(stack_a, stack_b, 1);
	}
	pp(stack_a, stack_b, 1);
}

// Sorts up to 6 values in stack_a
void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (3 < (*stack_a).max_lenght)
		unmerge(stack_a, stack_b);
	sort_three_a(stack_a, stack_b);
	if ((*stack_b).lenght == 3)
		sort_three_b(stack_a, stack_b);
	if (3 < (*stack_a).max_lenght)
	{
		merge(stack_a, stack_b);
		go_to(stack_a, stack_b, 1);
	}
}
