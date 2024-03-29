/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:58:09 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/05 14:12:52 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putptr(void	*ptr)
{
	uintptr_t	cast;
	char		*base;

	cast = (uintptr_t)ptr;
	base = "0123456789abcdef";
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_unbase(cast, 16, base) + 2);
}

int	ft_putnbrbase(long n, int base, char *c)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbrbase(-n, base, c) + 1);
	}
	if (n < base)
		return (ft_putchar(c[n]));
	else
	{
		count = ft_putnbrbase(n / base, base, c);
		return (ft_putnbrbase(n % base, base, c) + count);
	}
}

int	ft_unbase(unsigned long n, unsigned int base, char *c)
{
	int	count;

	if (n < base)
		return (ft_putchar(c[n]));
	else
	{
		count = ft_putnbrbase(n / base, base, c);
		return (ft_putnbrbase(n % base, base, c) + count);
	}
}
