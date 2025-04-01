/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:36:52 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/08 16:31:17 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **head_list, bool is_a, bool is_print)
{
	t_list	*last;
	t_list	*second;

	if (*head_list == NULL || (*head_list)->next == NULL)
		return ;
	last = *head_list;
	second = *head_list;
	while (last->next != NULL)
		last = last->next;
	last->next = *head_list;
	*head_list = second->next;
	second->next = NULL;
	if (is_print)
	{
		if (is_a)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b, bool is_print)
{
	rotate(stack_a, true, false);
	rotate(stack_b, false, false);
	if (is_print)
		write(1, "rr\n", 3);
}
