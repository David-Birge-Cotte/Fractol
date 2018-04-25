/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:19:27 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/09 15:19:28 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Alloue (avec malloc(3)) et retourne un tableau de chaines de
** caractères “fraiches” (toutes terminées par un ’\0’, le tableau
** également donc) résultant de la découpe de s selon le caractère
** c. Si l’allocation echoue, la fonction retourne NULL. Exemple :
** ft_strsplit("*salut*les***etudiants*", ’*’) renvoie
** le tableau ["salut", "les", "etudiants"].
*/

static char		*get_next_chunk(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_strsub(s, 0, i));
}

static int		get_num_chunks(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s) - 1)
	{
		if ((s[i] == c && s[i + 1] != c) || (i == 0 && s[0] != c))
			j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!ft_strlen(s))
	{
		tab = ft_memalloc(1);
		tab[0] = 0;
		return (tab);
	}
	if (!(tab = (char**)malloc((get_num_chunks(s, c) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	if (s[0] != c)
		tab[j++] = get_next_chunk(s, c);
	while (i++ < ft_strlen(s) - 1)
	{
		if ((s[i - 1] == c && s[i] != c))
			tab[j++] = get_next_chunk(&s[i], c);
	}
	tab[j] = 0;
	return (tab);
}
