/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:20:32 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/08 14:20:33 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dest;
	const unsigned char		*source;
	int						i;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	i = 0;
	while (i < (int)n)
	{
		dest[i] = source[i];
		if (source[i++] == (unsigned char)c)
			return (&dst[i]);
	}
	return (NULL);
}
