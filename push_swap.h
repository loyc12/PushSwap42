/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:20:01 by llord             #+#    #+#             */
/*   Updated: 2022/10/17 12:40:18 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>		// For printf(?)
# include <unistd.h>

// struct def
typedef struct s_stack
{
	int	*list;
	int	pos;
	int	lenght;
	int	max_lenght;
}		t_stack;

// From libft_imports
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

// From spliter
char	**ft_split(char *s, char c, int *argc, int *flag);

// From filter
int		format_filter(char **args, int lenght);
int		value_filter(int *list, int lenght);
int		is_sorted(int *list, int lenght);

// From processer
int		*lister(int *list, char **args, int lenght);
int		*indexer(int *list, int lenght);
t_stack	stacker_a(int *flag, int *list);
t_stack	stacker_b(int *flag, int lenght);

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

// From addons
int		*get_three(t_stack *stack);
void	go_to(t_stack *stack_a, t_stack *stack_b, int value);
int		find_step(t_stack *stack, int range, int type);

// From smalgo
void	small_sort(t_stack *stack_a, t_stack *stack_b);

// From biglo
void	big_sort(t_stack *stack_a, t_stack *stack_b);

// From endsort
void	end_sort(t_stack *stack_a, t_stack *stack_b);

#endif
