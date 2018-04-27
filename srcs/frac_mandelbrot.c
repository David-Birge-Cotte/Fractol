/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:55:50 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/11 09:55:51 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	draw_mandelbrot(const t_vector2ld *p, const size_t nb_iteration,
						t_vector2f param)
{
	size_t		i;
	t_vector2ld	pt;
	t_vector2ld	sqr;

	param = vector2f(0, 0);
	i = 0;
	pt.x = p->x;
	pt.y = p->y;
	sqr.x = pt.x * pt.x;
	sqr.y = pt.y * pt.y;
	while (i < nb_iteration && sqr.x + sqr.y < 4)
	{
		pt.y = pt.y * pt.x;
		pt.y += pt.y;
		pt.y += p->y;
		pt.x = sqr.x - sqr.y + p->x;
		sqr.x = (pt.x * pt.x);
		sqr.y = (pt.y * pt.y);
		i++;
	}
	if (i == nb_iteration)
		i = 0;
	return (i);
}
