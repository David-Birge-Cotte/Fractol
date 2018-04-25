/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:24:25 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/09 16:24:26 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères
** “fraiche” terminée par un ’\0’ représentant l’entier n passé
** en paramètre. Les nombres négatifs doivent être gérés. Si l’allocation
** échoue, la fonction renvoie NULL.
*/

static char	*handle_neg(char *str)
{
	char	*str_tmp;

	str_tmp = ft_strdup(str);
	ft_strdel(&str);
	if (!(str = ft_strjoin((char*)"-", str_tmp)))
		return (NULL);
	ft_strdel(&str_tmp);
	return (str);
}

static char	*update_str(char *str, char c)
{
	char	*str_tmp;
	char	*tmp;

	tmp = ft_strnew(1);
	tmp[0] = c;
	str_tmp = ft_strdup(str);
	ft_strdel(&str);
	if (!(str = ft_strjoin(tmp, str_tmp)))
		return (NULL);
	ft_strdel(&str_tmp);
	ft_strdel(&tmp);
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	char	*tmp;
	char	*str_tmp;
	long	l;

	if (!(str = ft_strnew(0)))
		return (NULL);
	l = (long)n;
	l = l < 0 ? -l : l;
	if (l == 0)
		str[0] = '0';
	while (l)
	{
		if (update_str(str, (char)(l % 10) + 48) == NULL)
			return (NULL);
		l = l / 10;
	}
	if (n < 0)
		if (handle_neg(str) == NULL)
			return (NULL);
	return (str);
}
