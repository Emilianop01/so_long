/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:00:20 by epiacent          #+#    #+#             */
/*   Updated: 2024/01/31 21:54:19 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mod;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	mod = (char *)malloc(ft_strlen(s) + 1);
	if (!mod)
		return (NULL);
	while (s[i])
	{
		mod[i] = f(i, s[i]);
		i++;
	}
	mod[i] = 0;
	return (mod);
}
