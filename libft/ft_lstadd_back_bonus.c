/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:09:25 by bsamzun           #+#    #+#             */
/*   Updated: 2024/11/16 00:26:08 by bsamzun          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_end)
{
	t_list	*end;

	if (!*lst)
		*lst = new_end;
	else
	{
		end = *lst;
		while (end->next)
			end = end->next;
		end->next = new_end;
	}
}
