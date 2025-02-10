/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:21:53 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/08 17:55:18 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H	
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

# define MAX_NUMBERS 500

typedef struct s_moves
{
	int				a_rotations;
	int				a_rev_rotations;
	int				b_rotations;
	int				b_rev_rotations;
	int				total_rotations;
	struct s_list	*target;
}				t_moves;

typedef struct s_list
{
	int				content;
	t_moves			moves;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

// Operations
void	push_a(t_list **stack_a, t_list **stack_b, bool is_print);
void	push_b(t_list **stack_a, t_list **stack_b, bool is_print);
void	*swap(t_list *head_list, bool is_a, bool is_print);
void	ss(t_list **stack_a, t_list **stack_b, bool is_print);
void	rotate(t_list **head_list, bool is_a, bool is_print);
void	rr(t_list **stack_a, t_list **stack_b, bool is_print);
void	reverse_rotate(t_list **head_list, bool is_a, bool is_print);
void	rrr(t_list **stack_a, t_list **stack_b, bool is_print);

// List aux
void	add_node(t_list **stack, int nbr);
int		list_size(t_list *stack);
void	free_stack(t_list **head);
bool	check_sorted(t_list *stack);
void	print_list(t_list *head);

// Initialization
void	error_exit(const char *message);
int		ft_atoi(const char *nptr);
int		valid_number(const char *str);
int		is_duplicate(t_list *head, int num);
t_list	*stack_initialize(char **argv, int size);

// Find utils
int		find_average(t_list *stack_b);
int		find_position(t_list *stack, int value);
void	find_best_node(t_list *stack_a, t_list *stack_b, t_list *current_b);
t_list	*find_cheapest_node(t_list *stack);
void	find_cost(t_list *stack_a, t_list *stack_b);

// Moves aux
void	initialize_moves(t_moves *moves, t_list *target);
void	calc_a_rotations(t_list *stack_a, t_moves *moves, int target_pos);
void	calc_b_rotations(t_list *stack_b, t_moves *moves, int current_b_pos);
void	count_moves(t_list *stack_a, t_list *stack_b, t_list *current_b);

// Execute moves
void	synchro_r(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);
void	individual_r(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);
void	exec_moves(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);

// Sorting
t_list	*find_min(t_list *stack_a);
void	sort_three(t_list **stack_a);
void	move_and_sort_initial(t_list **stack_a, t_list **stack_b);
void	sort_general(t_list **stack_a, t_list **stack_b);

int		main(int argc, char **argv);

#endif