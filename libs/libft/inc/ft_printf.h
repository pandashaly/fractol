/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:00:08 by ssottori          #+#    #+#             */
/*   Updated: 2024/03/01 16:59:00 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include "libft.h"

int		ft_printf(const char *arg, ...);
int		ft_format(const char *str, va_list args);
int		ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_printstr(char *s);
int		ft_putptr(void *ptr);
int		ft_putnbrbase(long n, int base, char *c);
int		ft_unbase(unsigned long n, unsigned int base, char *c);

#endif
