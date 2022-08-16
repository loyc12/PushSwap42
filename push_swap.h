/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:20:01 by llord             #+#    #+#             */
/*   Updated: 2022/08/16 09:38:32 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>		// For printf(?)
#include <unistd.h>

// struct def
typedef struct	s_stack
{
	int	*list;
	int	pos;
	int	lenght;
	int	max_lenght;
}		t_stack;

struct s_stack	*stack_pointer;

// From debug_tests											REMOVE BEFORE CLOSING
void	debug_print_stacks(struct s_stack *stack_a, struct s_stack *stack_b, int type);
void	debug_print_str(char **list, int len, char *name);
void	debug_print_int(int*list, int len, char *name);
void	debug_moves(struct s_stack *stack_a, struct s_stack *stack_b);

// From libft_imports
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

// From filter / lister / indexer
int format_filter(char **args, int lenght);
int value_filter(int *list, int lenght);
int	*lister(int *list, char **args, int lenght);
int	*indexer(int *list, int lenght);

// From stacker
struct s_stack	stacker_a(int *list);
struct s_stack	stacker_b(int lenght);

// From mover
void	push(struct s_stack *src_stack, struct s_stack *dst_stack);
void	swap(struct s_stack *stack);
void	rotate(struct s_stack *stack, int type);

// From moves
void	ss(struct s_stack *stack_a, struct s_stack *stack_b, int type);
void	pp(struct s_stack *stack_a, struct s_stack *stack_b, int type);
void	rr(struct s_stack *stack_a, struct s_stack *stack_b, int type);
void	rrr(struct s_stack *stack_a, struct s_stack *stack_b, int type);

#endif
