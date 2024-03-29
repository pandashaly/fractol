/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:08:02 by ssottori          #+#    #+#             */
/*   Updated: 2023/12/07 21:57:20 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(const char *str, va_list args)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*str == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (*str == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbrbase(va_arg(args, int), 10, "0123456789"));
	else if (*str == 'u')
		return (ft_unbase(va_arg(args, unsigned int), 10, "0123456789"));
	else if (*str == 'x')
		return (ft_unbase(va_arg(args, unsigned int), 16, "0123456789abcdef"));
	else if (*str == 'X')
		return (ft_unbase(va_arg(args, unsigned int), 16, "0123456789ABCDEF"));
	else if (*str == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, arg);
	count = 0;
	while (*arg != '\0')
	{
		if (*arg == '%')
			count += ft_format(++arg, ap);
		else
			count += write(1, arg, 1);
		++arg;
	}
	va_end(ap);
	return (count);
}

/*int	main(void)
{
	ft_printf("hello i am %s!!\n", "Shaly");
	ft_printf("%s %s\n", "Today is", __DATE__);
	ft_printf("%s \n", "abc");
	ft_printf("%s %s\n", "The time is", __TIME__);
	ft_printf("%c is for %s!\n", 'c', "Choombas");
	ft_printf("%c%c is for %d!\n", 'f', 't', 42);
	ft_printf("%d %i \n", 42, 42);
	ft_printf("%x %X \n", 42, 42);
	ft_printf("%% \n");
	ft_printf("%x \n", 31);
	ft_printf("%u \n", 42);
	//ft_printf(");
	return (0);
}*/
