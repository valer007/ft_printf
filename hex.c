/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:55:00 by vmakarya          #+#    #+#             */
/*   Updated: 2025/02/03 21:17:28 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex(unsigned long num, int flag)
{
	char		address[17];
	char		*buffer;
	int			i;
	int			count;

	i = 0;
	count = 0;
	if (flag == 1)
		buffer = "0123456789ABCDEF";
	else
		buffer = "0123456789abcdef";
	if (num == 0)
		address[i++] = '0';
	while (num > 0)
	{
		address[i] = buffer[num % 16];
		num /= 16;
		i++;
	}
	while (i--)
		count += write(1, &address[i], 1);
	return (count);
}
