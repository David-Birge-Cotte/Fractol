/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:59:07 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/13 10:59:08 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction
** f et crée une nouvelle liste “fraiche” avec malloc(3) ré-
** sultant des applications successives. Si une allocation échoue,
** la fonction renvoie NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin;
	t_list *tmp;
	t_list *current;

	if (!lst)
		return (NULL);
	current = lst;
	tmp = f(current);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin = new;
	current = current->next;
	while (current)
	{
		tmp = f(current);
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		current = current->next;
		new = new->next;
	}
	return (begin);
}
