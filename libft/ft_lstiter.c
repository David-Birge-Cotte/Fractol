/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:55:53 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/13 10:55:55 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction
** f.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *current_lst;

	current_lst = lst;
	while (current_lst)
	{
		f(current_lst);
		current_lst = current_lst->next;
	}
}
