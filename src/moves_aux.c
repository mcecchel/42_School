/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:55:33 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/03 15:50:11 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_moves(t_moves *moves, t_list *target)
{
	moves->a_rotations = -1;
	moves->a_rev_rotations = -1;
	moves->b_rotations = -1;
	moves->b_rev_rotations = -1;
	moves->total_rotations = 0;
	moves->target = target;
}

void	calc_a_rotations(t_list *stack_a, t_moves *moves, int target_pos)
{
	if (target_pos <= list_size(stack_a) / 2 + 1)
	{
		moves->a_rotations = target_pos;
		moves->total_rotations += target_pos;
	}
	else
	{
		moves->a_rev_rotations = list_size(stack_a) - target_pos;
		moves->total_rotations += list_size(stack_a) - target_pos;
	}
}

void	calc_b_rotations(t_list *stack_b, t_moves *moves, int current_b_pos)
{
	if (current_b_pos <= list_size(stack_b) / 2 + 1)
	{
		moves->b_rotations = current_b_pos;
		moves->total_rotations += current_b_pos;
	}
	else
	{
		moves->b_rev_rotations = list_size(stack_b) - current_b_pos;
		moves->total_rotations += list_size(stack_b) - current_b_pos;
	}
}

void	count_moves(t_list *stack_a, t_list *stack_b, t_list *current_b)
{
	int	target_pos;
	int	current_b_pos;

	target_pos = find_position(stack_a, current_b->moves.target->content);
	current_b_pos = find_position(stack_b, current_b->content);
	initialize_moves(&current_b->moves, current_b->moves.target);
	calc_a_rotations(stack_a, &current_b->moves, target_pos);
	calc_b_rotations(stack_b, &current_b->moves, current_b_pos);
}
