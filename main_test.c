/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:13:20 by llord             #+#    #+#             */
/*   Updated: 2022/08/11 15:34:05 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)						// Tests the general initialization
{
	struct s_bank bank_a;
	struct s_bank bank_b;
	int	*list;

	debug_print_str(argv + 1, argc - 1, " Argv");	// Prints the inputs

	if (!format_filter(argc, argv))					// Error handler 1
		return (1);

	list = lister(argc, argv, list);				// Converts the inputs in ints

	debug_print_int(list, argc - 1, " Raw ");		// Prints the raw list

	list = indexer(list, argc - 1);					// Indexes the list

	debug_print_int(list, argc - 1, " List");		// Prints the indexed list

	if (!value_filter(list, argc - 1))				// Error handler 2
		return (1);

	bank_a = banker_a(list);						// Initializes both banks (stacks)
	bank_b = banker_b(bank_a.max_lenght);			//

	debug_moves(&bank_a, &bank_b);					// Tries moves

	return (0);
}
