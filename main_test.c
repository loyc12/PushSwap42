/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/23 13:52:14 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)				// Tests the general initialization
{
	t_stack	stack_a;
	t_stack	stack_b;
	int	*list = NULL;		// FORMAT ME BITCH

	argv += 1;				// FORMAT ME BITCH
	argc -= 1;

	//debug_print_str(argv, argc, " Args");	// Prints the inputs (Debug)

	if (!format_filter(argv, argc))			// Error handler 1
		return (1);

	list = lister(list, argv, argc);		// Converts the inputs in ints
	list = indexer(list, argc);				// Indexes the list

	//debug_print_int(list, argc, " List");	// Prints the indexed list (Debug)

	if (!value_filter(list, argc))			// Error handler 2
		return (2);

	stack_a = stacker_a(list);				// Initializes both stacks (stacks)
	stack_b = stacker_b(stack_a.max_lenght);

	//debug_looks(&stack_a);				// Prints the distances (Debug)

	//debug_moves(&stack_a, &stack_b);		// Tries moves (Debug)

	sort_test(&stack_a, &stack_b);

	debug_print_end(&stack_a);			// Prints the end stack (Debug)

	return (0);
}
