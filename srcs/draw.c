/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:01:29 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/18 10:01:30 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*draw_fractal(t_drawer_arg *args)
{
	t_vector2i	incr;
	t_vector2ld	pt;
	t_vector2i	pix;
	t_color		*color;

	incr = vector2i(0, 0);
	while (incr.x < WIN_W)
	{
		incr.y = args->screen_y_from;
		while (incr.y < (int)args->screen_y_to)
		{
			pt.x = map(incr.x, vector2f(0, WIN_W), args->x_range);
			pt.y = map(incr.y, vector2f(0, WIN_H), args->y_range);
			pix = vector2i(incr.x, incr.y);
			color = color_from_val(args->func_ptr(&pt, args->app->nb_itera,
					args->app->para), args->app->nb_itera,
					args->app->color_scheme, args->app->color_mode);
			put_pixel(args->app->pixels, pix.x, pix.y, color);
			ft_memdel((void**)&color);
			incr.y++;
		}
		incr.x++;
	}
	ft_memdel((void**)&args);
	return (NULL);
}
