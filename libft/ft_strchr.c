/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:05:00 by epiacent          #+#    #+#             */
/*   Updated: 2024/01/31 21:38:51 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (NULL);
}
