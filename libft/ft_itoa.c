/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:13:02 by abakirca          #+#    #+#             */
/*   Updated: 2023/12/21 16:39:08 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static	int	digitcount(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	if (n >= 0 && n <= 9)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	void	placement(char *final, int digits, long int nb)
{
	final[digits] = '\0';
	while (digits)
	{
		final[--digits] = ((nb % 10) + 48);
		if (nb >= 0 && nb <= 9)
			digits = 0;
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char		*final;
	int			digits;
	long int	nb;

	nb = n;
	digits = digitcount(n);
	if (n < 0)
	{
		final = (char *)malloc(digits++ * sizeof(char) + 2);
		if (final == NULL)
			return (0);
		final[0] = '-';
		nb *= -1;
	}
	else
	{
		final = (char *)malloc(digits * sizeof(char) + 1);
		if (final == NULL)
			return (0);
	}
	placement(final, digits, nb);
	return (final);
}
