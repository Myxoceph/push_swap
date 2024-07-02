/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:24:28 by abakirca          #+#    #+#             */
/*   Updated: 2023/12/20 12:34:39 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	final_string = malloc(((s1_len + s2_len + 1) * sizeof(char)));
	if (final_string == NULL)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		final_string[i] = s1[i];
	while (s2[j])
	{
		final_string[i] = s2[j];
		i++;
		j++;
	}
	final_string[i] = '\0';
	return (final_string);
}
