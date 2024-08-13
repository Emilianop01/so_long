/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:51:34 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/13 22:18:20 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(s2, s1[i]))
		i++;
	while (s1[--j] && ft_strchr(s2, s1[j]) && j > i)
		;
	str = (char *)malloc(j - i + 2);
	if (!str)
		return (NULL);
	while (k <= j - i)
	{
		str[k] = s1[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}
