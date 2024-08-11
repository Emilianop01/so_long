/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:20:32 by epiacent          #+#    #+#             */
/*   Updated: 2024/01/31 21:53:45 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	divisore(int n)
{
	int	div;
	int	cont;

	cont = 0;
	div = 1000000000;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		cont++;
	}
	while (n / div == 0)
		div = div / 10;
	while (div > 0)
	{
		div = div / 10;
		cont++;
	}
	return (cont);
}

void	scpy(char *s, long l, int mas, int d)
{
	if (l < 0)
	{
		l = -l;
		s[d++] = '-';
	}
	while (mas > 0)
	{
		s[d++] = l / mas + '0';
		l = l % mas;
		mas = mas / 10;
	}
	s[d] = '\0';
}

char	*ft_itoa(int n)
{
	char	*s;
	int		d;
	int		mas;
	long	l;

	l = n;
	mas = 1;
	d = divisore(l);
	s = (char *)malloc(sizeof(char) * d + 1);
	if (!s)
		return (NULL);
	if (l < 0)
		d--;
	while (--d)
		mas = mas * 10;
	scpy(s, l, mas, d);
	return (s);
}
