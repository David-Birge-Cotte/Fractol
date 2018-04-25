/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:31:50 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/13 14:31:51 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ajoute l’élément new en tête de la liste.
*/

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*current;

	current = *alst;
	while (current->next)
		current = current->next;
	current->next = new;
}
