/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/15 14:02:47 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)						// Tests the general initialization
{
	struct s_bank bank_a;
	struct s_bank bank_b;
	int	*list = NULL;		// FORMAT ME BITCH

	argv += 1; argc -= 1;	// FORMAT ME BITCH

	debug_print_str(argv, argc, " Args");		// Prints the inputs (Debug)

	if (!format_filter(argv, argc))				// Error handler 1
		return (1);

	list = lister(list, argv, argc);			// Converts the inputs in ints
	list = indexer(list, argc);					// Indexes the list

	debug_print_int(list, argc, " List");		// Prints the indexed list (Debug)

	if (!value_filter(list, argc))				// Error handler 2
		return (2);

	bank_a = banker_a(list);					// Initializes both banks (stacks)
	bank_b = banker_b(bank_a.max_lenght);		//

	debug_moves(&bank_a, &bank_b);				// Tries moves (Debug)

	return (0);
}
