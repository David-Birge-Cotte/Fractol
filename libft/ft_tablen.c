/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:30:00 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/05 10:30:02 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_tablen(char **tab)
** takes an array of char* finished by a NULL (0)
** returns -1 when the tab is not malloc
** returns 0 when the tab is empty
** returns the numbers of elements in the tab
*/

#include "libft.h"

int	ft_tablen(char **tab)
{
	size_t	l;

	l = 0;
	if (tab == NULL)
		return (-1);
	while (tab[l] != 0)
		l++;
	return (l);
}
