/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:39:25 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/14 11:58:41 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Retourne la taille de la liste.
*/

#include "libft.h"

size_t	ft_list_size(t_list *begin)
{
	t_list	*current;
	size_t	counter;

	counter = 0;
	current = begin;
	while (current)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}
