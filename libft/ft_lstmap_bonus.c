/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:42:26 by bsamzun           #+#    #+#             */
/*   Updated: 2024/11/17 13:20:13 by bsamzun          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*start;
	void	*buf;

	if (!lst || !f || !del)
		return (NULL);
	buf = f(lst->content);
	map = ft_lstnew(buf);
	if (!map)
		return (del(buf), NULL);
	start = map;
	while (lst->next)
	{
		lst = lst->next;
		buf = f(lst->content);
		map->next = ft_lstnew(buf);
		if (!map->next)
			return (del(buf), ft_lstclear(&start, del), NULL);
		map = map->next;
	}
	return (start);
}
