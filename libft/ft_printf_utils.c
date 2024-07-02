/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:01:38 by abakirca          #+#    #+#             */
/*   Updated: 2024/01/10 18:01:38 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	firstpart(va_list args, char *str)
{
	int	count;

	count = 0;
	if (*str == '%' && *(str + 1) == 'c')
	{
		if (ft_putchargs(args) == -1)
			return (-1);
		count++;
	}
	else if (*str == '%' && *(str + 1) == 's')
	{
		count += ft_putstr(args);
		if (count == -1)
			return (-1);
	}
	else if (*str == '%' && *(str + 1) == '%')
	{
		if (ft_putchar('%') == (-1))
			return (-1);
		count++;
	}
	return (count);
}

int	secondpart(va_list args, char *str)
{
	unsigned long	nb;
	int				count;

	count = 0;
	if (*str == '%' && (*(str + 1) == 'd' || *(str + 1) == 'i'))
	{
		nb = va_arg(args, int);
		count += ft_putnbr(nb);
		if (count == -1)
			return (-1);
	}
	else if (*str == '%' && *(str + 1) == 'u')
	{
		nb = va_arg(args, unsigned int);
		count += ft_putunbr(nb);
		if (count == -1)
			return (-1);
	}
	return (count);
}

int	thirdpart(va_list args, char *str)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (*str == '%' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
	{
		nb = va_arg(args, unsigned int);
		if (*(str + 1) == 'x')
			count += ft_hexprint(nb, 'x');
		else
			count += ft_hexprint(nb, 'X');
	}
	else if (*str == '%' && *(str + 1) == 'p')
		count += ptrout(args);
	else
		count += ft_putchar(*(str + 1));
	return (count);
}
