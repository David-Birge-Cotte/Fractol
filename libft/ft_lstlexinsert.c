/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlexinsert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:15:26 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/13 14:15:27 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ajoute l’élément new dans la liste a sa place dans l'ordre alphabetique.
*/

#include "libft.h"

void	ft_lstlexinsert(t_list **begin, t_list *new)
{
	t_list *prev;
	t_list *current;
	t_list *tmp;

	prev = NULL;
	current = *begin;
	while (current)
	{
		if (ft_strcmp(current->content, new->content) >= 0)
		{
			if (prev != NULL)
			{
				tmp = prev;
				prev->next = new;
				new->next = current;
			}
			else
				ft_lstadd(begin, new);
			return ;
		}
		prev = current;
		current = current->next;
	}
	prev->next = new;
}
