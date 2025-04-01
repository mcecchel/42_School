/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:15:46 by mcecchel          #+#    #+#             */
/*   Updated: 2025/02/08 14:25:17 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(const char *message)
{
	write(2, message, 6);
	exit(1);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;
	long	tmp;

	sign = 1;
	result = 0;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr)
	{
		tmp = result;
		result = result * 10 + (*nptr - '0');
		if (result / 10 != tmp || result * sign > INT_MAX
			|| result * sign < INT_MIN)
			return (0);
		nptr++;
	}
	return ((int)result * sign);
}

int	valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	if ((ft_atoi(str) == 0)
		&& ft_strncmp(&str[i], "0", ft_strlen(&str[i])) != 0)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_list *head, int num)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		if (current->content == num)
			return (1);
		current = current->next;
	}
	return (0);
}

t_list	*stack_initialize(char **argv, int size)
{
	t_list	*stack_a;
	int		num;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < size)
	{
		if (!valid_number(argv[i]))
		{
			free_stack(&stack_a);
			error_exit("Error\n");
		}
		num = ft_atoi(argv[i]);
		if (is_duplicate(stack_a, num))
		{
			free_stack(&stack_a);
			error_exit("Error\n");
		}
		add_node(&stack_a, num);
		i++;
	}
	return (stack_a);
}
