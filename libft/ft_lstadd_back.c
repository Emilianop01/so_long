/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:18:53 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/13 22:17:34 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*del;

	if (!lst)
		return ;
	if (*lst)
	{
		del = ft_lstlast(*lst);
		del->next = new;
	}
	else
		(*lst) = new;
}
