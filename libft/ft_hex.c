/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:01:51 by abakirca          #+#    #+#             */
/*   Updated: 2024/01/10 18:01:51 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexprint(unsigned long nb, char base)
{
	char	*hex;
	int		count;

	count = 0;
	if (base == 'X')
		hex = "0123456789ABCDEF";
	if (base == 'x')
		hex = "0123456789abcdef";
	if (nb > 15)
		count += ft_hexprint(nb / 16, base);
	if (count == -1)
		return (-1);
	if (ft_putchar(hex[nb % 16]) == -1)
		return (-1);
	count++;
	return (count);
}

int	ptrout(va_list args)
{
	unsigned long	ptr;
	int				count;

	count = 0;
	ptr = va_arg(args, unsigned long);
	if (ft_putchar('0') == -1)
		return (-1);
	count++;
	count += ft_putchar('x');
	count += ft_hexprint(ptr, 'x');
	return (count);
}
