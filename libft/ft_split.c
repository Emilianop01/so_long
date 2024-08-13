/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:18:17 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/13 22:19:04 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conta(char const *str, char c)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != c && str[i])
			i++;
		if (i > 0)
			num++;
		while (str[i] == c && str[i])
			i++;
	}
	return (num);
}

void	ft_copia(const char *s, char **frase, char c, int i)
{
	int	j;
	int	k;
	int	l;

	l = 0;
	while (s[i])
	{
		k = i;
		while (s[k] != c && s[k])
			k++;
		if (k > 0)
		{
			frase[l] = (char *)malloc(k - i + 1);
			j = 0;
			while (i < k)
				frase[l][j++] = s[i++];
			frase[l++][j] = '\0';
		}
		while (s[i] == c && s[i])
			i++;
	}
	frase[l] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**frase;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	frase = (char **)malloc(sizeof(char *) * (conta(s, c) + 1));
	if (!frase)
		return (NULL);
	ft_copia(s, frase, c, i);
	return (frase);
}
