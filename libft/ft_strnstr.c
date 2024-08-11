/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:48:23 by epiacent          #+#    #+#             */
/*   Updated: 2024/01/31 21:41:12 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *f, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (f[0] == '\0')
		return ((char *)s);
	if (l == 0)
		return (NULL);
	while (s[i] != '\0' && i < l)
	{
		j = 0;
		while (s[i + j] == f[j] && (i + j < l) && s[i + j] != '\0')
		{
			j++;
			if (f[j] == '\0')
				return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
