/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:02:53 by abakirca          #+#    #+#             */
/*   Updated: 2024/01/10 18:02:53 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr(int c)
{
	int	count;
	int	tmp;

	count = 0;
	if (c == 0)
		return (write(1, "0", 1));
	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	if (c < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		c *= -1;
	}
	if (c >= 10)
	{
		tmp = ft_putnbr(c / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (write(1, &"0123456789"[c % 10], 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putunbr(unsigned int c)
{
	unsigned int	count;
	int				tmp;

	count = 0;
	if (c >= 10)
	{
		tmp = ft_putunbr(c / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (write(1, &"0123456789"[c % 10], 1) == -1)
		return (-1);
	return (count + 1);
}
