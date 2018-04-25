/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:15:51 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/17 16:15:51 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	draw_burning_ship(const t_vector2ld *p, const size_t nb_iteration,
						t_vector2f param)
{
	size_t		i;
	t_vector2ld	pt;
	t_vector2ld	sqr;
	long double	xtmp;

	param = vector2f(0, 0);
	i = 0;
	pt.x = p->x;
	pt.y = p->y;
	sqr.x = pt.x * pt.x;
	sqr.y = pt.y * pt.y;
	while (i < nb_iteration && sqr.x + sqr.y < 4)
	{
		xtmp = sqr.x - sqr.y + p->x;
		pt.y = ft_absl(2 * pt.x * pt.y + p->y);
		pt.x = ft_absl(xtmp);
		sqr.x = (pt.x * pt.x);
		sqr.y = (pt.y * pt.y);
		i++;
	}
	if (i == nb_iteration)
		i = 0;
	return (i);
}
