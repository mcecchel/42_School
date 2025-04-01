/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:40:17 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/08 16:36:58 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **head_list, bool is_a, bool is_print)
{
	t_list	*last;
	t_list	*second_last;

	if (*head_list == NULL || (*head_list)->next == NULL)
		return ;
	last = *head_list;
	second_last = *head_list;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *head_list;
	second_last->next = NULL;
	*head_list = last;
	if (is_print)
	{
		if (is_a)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, bool is_print)
{
	reverse_rotate(stack_a, true, false);
	reverse_rotate(stack_b, false, false);
	if (is_print)
		write(1, "rrr\n", 4);
}
