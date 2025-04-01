/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:52:01 by mcecchel          #+#    #+#             */
/*   Updated: 2024/12/15 17:28:15 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t	ft_strlen(const char *s);
int		ft_counter(int nbr);
int		ft_hex_counter(unsigned int nbr);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_percent(void);

int		ft_putdecimal(int nbr);
int		ft_putunsign(unsigned int nbr);
int		ft_puthexamin(unsigned int nbr);
int		ft_puthexamai(unsigned int nbr);
int		ft_putptr(void *ptr);

int		ft_printf(const char *str, ...);

#endif