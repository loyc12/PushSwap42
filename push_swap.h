/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:20:01 by llord             #+#    #+#             */
/*   Updated: 2022/09/14 16:33:37 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>		// For printf(?)
# include <unistd.h>

// struct def
typedef struct	s_stack
{
	int	*list;
	int	pos;
	int	lenght;
	int	max_lenght;
}		t_stack;

// From debug_tests						REMOVE BEFORE CLOSING
void	debug_print_stacks(t_stack *stack_a, t_stack *stack_b, int type);
void	debug_print_end(t_stack *stack);
void	debug_print_str(char **list, int len, char *name);
void	debug_print_int(int*list, int len, char *name);
void	debug_print_dist(int distance_down, int distance_up);
void	debug_looks(t_stack *stack);
void	debug_moves(t_stack *stack_a, t_stack *stack_b);
void	prints_random(int n);

// From libft_imports
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		*array_cpy(int *srclst, int n);

// From filter / lister / indexer
int		format_filter(char **args, int lenght);
int		value_filter(int *list, int lenght);
int		*lister(int *list, char **args, int lenght);
int		*indexer(int *list, int lenght);

// From stacker
t_stack	stacker_a(int *list);
t_stack	stacker_b(int lenght);

// From mover
void	push(t_stack *src_stack, t_stack *dst_stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack, int type);

// From moves
void	ss(t_stack *stack_a, t_stack *stack_b, int type);
void	pp(t_stack *stack_a, t_stack *stack_b, int type);
void	rr(t_stack *stack_a, t_stack *stack_b, int type);
void	rrr(t_stack *stack_a, t_stack *stack_b, int type);

// From looker
int		look_for(t_stack *stack, int range_min, int range_max);

// From smalgo
void	small_sort(t_stack *stack_a, t_stack *stack_b);

// From biglo
int		find_range(int lenght);
int		find_step(t_stack *stack, int range, int type);
void	big_sort(t_stack *stack_a, t_stack *stack_b);

#endif
