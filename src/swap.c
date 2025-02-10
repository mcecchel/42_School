/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:31:45 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/08 16:31:49 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*swap(t_list *head_list, bool is_a, bool is_print)
{
	int	tmp;

	if (head_list == NULL || head_list->next == NULL)
		return (head_list);
	tmp = head_list->content;
	head_list->content = head_list->next->content;
	head_list->next->content = tmp;
	if (is_print)
	{
		if (is_a)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
	return (head_list);
}

void	ss(t_list **stack_a, t_list **stack_b, bool is_print)
{
	swap(*stack_a, true, false);
	swap(*stack_b, false, false);
	if (is_print)
		write(1, "ss\n", 3);
}
