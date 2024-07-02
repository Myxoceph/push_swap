/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:02:39 by abakirca          #+#    #+#             */
/*   Updated: 2024/01/10 18:02:39 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putchargs(va_list args)
{
	char	c;

	c = va_arg(args, unsigned int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(va_list args)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	str = va_arg(args, char *);
	if (str == 0)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
}
