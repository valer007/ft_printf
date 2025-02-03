/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:27:54 by vmakarya          #+#    #+#             */
/*   Updated: 2025/02/03 23:27:55 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	usd(unsigned int num)
{
	char	ptr[10];
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (num == 0)
		count += write(1, "0", 1);
	while (num > 0)
	{
		ptr[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	while (i--)
		count += write(1, &ptr[i], 1);
	return (count);
}
