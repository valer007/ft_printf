// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_printf.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/03 22:29:21 by vmakarya          #+#    #+#             */
// /*   Updated: 2025/02/05 13:19:54 by vmakarya         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "ft_printf.h"

int ft_print_string(char *str)
{
	int count;

	if (!str)
		return (write(1, "(null)", 6));
	count = write(1, str, ft_strlen(str));
	return (count);
}

int ft_handle_specifier(char spec, va_list* args, int count, char c)
{
	if (spec == 's')
		count = ft_print_string(va_arg(*args, char *));
	else if (spec == 'd' || spec == 'i')
		count = ft_putnbr(va_arg(*args, int));
	else if (spec == 'c')
	{
		c = (char)va_arg(*args, int);
		count = write(1, &c, 1);
	}
	else if (spec == 'p')
		count = write(1, "0x", 2) + hex(va_arg(*args, unsigned long), 0);
	else if (spec == '%')
		count = write(1, "%", 1);
	else if (spec == 'u')
		count = usd(va_arg(*args, unsigned int));
	else if (spec == 'x')
		count = hex(va_arg(*args, unsigned int), 0);
	else if (spec == 'X')
		count = hex(va_arg(*args, unsigned int), 1);
	else
		count = write(1, &spec, 1);
	return (count);
}

int ft_printf(const char *ptr, ...)
{
	va_list args;
	int count;
	char ch;
	int num;
	
	num = 0;
	ch = 0;
	va_start(args, ptr);
	count = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			while (*ptr == ' ')
			{
				ptr++;
			}
			count += ft_handle_specifier(*ptr, &args, num, ch);
		}
		else
			count += write(1, ptr, 1);
		ptr++;
	}
	va_end(args);
	return (count);
}