/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:53:32 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/13 22:18:51 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < len)
		i++;
	while (src[j] != '\0' && (i + j) < len - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < len)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
