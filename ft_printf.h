/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:24:49 by vmakarya          #+#    #+#             */
/*   Updated: 2025/02/03 23:24:50 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		hex(unsigned long num, int flag);
char	*ft_strdup(const char *s);
int		ft_printf(const char *ptr, ...);
int		usd(unsigned int num);

#endif
