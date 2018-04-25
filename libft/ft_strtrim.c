/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:12:23 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/09 14:12:24 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une copie de la chaine
** passée en paramètre sans les espaces blancs au debut et à la
** fin de cette chaine. On considère comme espaces blancs les
** caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces
** blancs au début ou à la fin, la fonction renvoie une copie de
** s. Si l’allocation echoue, la fonction renvoie NULL.
*/

static int	get_space_num_start(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	get_space_num_end(char const *s)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s) - 1;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		j++;
	}
	return (j);
}

static int	is_all_blanc(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;

	if (!s)
		return (NULL);
	if (is_all_blanc(s))
		return (ft_strnew(0));
	str = ft_strsub(s, get_space_num_start(s),
	(ft_strlen(s) - get_space_num_start(s) - get_space_num_end(s)));
	return (str);
}
