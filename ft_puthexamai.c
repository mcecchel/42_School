/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamai.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:44:53 by mcecchel          #+#    #+#             */
/*   Updated: 2024/12/14 16:04:10 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexamai(unsigned int nbr)
{
	if (nbr >= 16)
	{
		ft_puthexamai(nbr / 16);
		ft_puthexamai(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr + 'A' - 10);
	}
	return (ft_hex_counter(nbr));
}
