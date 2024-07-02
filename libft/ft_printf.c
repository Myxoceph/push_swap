/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:02:11 by abakirca          #+#    #+#             */
/*   Updated: 2024/01/10 18:02:20 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printer(char *str, va_list args, int count)
{
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'c' || *(str + 1) == 's' || *(str + 1) == '%')
				count += firstpart(args, str);
			else if (*(str + 1) == 'd' || *(str + 1) == 'i'
				|| *(str + 1) == 'u')
				count += secondpart(args, str);
			else
				count += thirdpart(args, str);
			str++;
			if (count == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(*str) == -1)
				return (-1);
			count++;
		}
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, str);
	counter += ft_printer((char *)str, args, 0);
	va_end(args);
	if (counter == -1)
		return (-1);
	return (counter);
}
