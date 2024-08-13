/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:42:14 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/13 22:19:00 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newn;

	newn = (t_list *)malloc(sizeof(t_list));
	if (!newn)
		return (NULL);
	newn->content = content;
	newn->next = NULL;
	return (newn);
}
