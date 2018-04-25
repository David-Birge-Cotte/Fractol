/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:55:57 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/17 11:48:12 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	draw_julia(const t_vector2ld *p, const size_t nb_iteration,
							t_vector2f param)
{
	size_t		i;
	t_vector2ld	pt;
	t_vector2ld	sqr;
	long double	xtmp;

	i = 0;
	pt.x = p->x;
	pt.y = p->y;
	sqr.x = pt.x * pt.x;
	sqr.y = pt.y * pt.y;
	while (i < nb_iteration && sqr.x + sqr.y < 4)
	{
		xtmp = sqr.x - sqr.y;
		pt.y = 2 * pt.x * pt.y + param.x;
		pt.x = xtmp + param.y;
		sqr.x = (pt.x * pt.x);
		sqr.y = (pt.y * pt.y);
		i++;
	}
	if (i == nb_iteration)
		i = 0;
	return (i);
}
