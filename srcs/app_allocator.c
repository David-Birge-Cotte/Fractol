/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_allocator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:22:12 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:22:38 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Starts a new app with an new sdl instance
*/

t_app		*new_app(void)
{
	t_app	*app;

	if ((app = ft_memalloc(sizeof(t_app))) == NULL)
		return (NULL);
	app->nb_pixels = WIN_H * WIN_W;
	if ((app->pixels = ft_memalloc(sizeof(t_uint32) * app->nb_pixels)) == NULL)
		return (NULL);
	if ((app->sdl = new_sdl()) == NULL)
		return (NULL);
	app->loop = TRUE;
	app->nb_itera = NB_ITERATION;
	app->zoom = 1;
	app->center_pt = new_vector2f(0, 0);
	app->color_mode = ULTRACOLOR;
	app->julia_mouse = 1;
	app->color_scheme = new_scheme(5, new_color(0, 7, 100, 255),
					new_color(32, 107, 203, 255), new_color(237, 255, 255, 255),
					new_color(255, 107, 0, 255), new_color(0, 2, 0, 255));
	return (app);
}

/*
** Stops the app and the sdl instance then properly exit the program
*/

void		app_del(t_app *app)
{
	sdl_del(app->sdl);
	ft_memdel((void**)&app->pixels);
	ft_memdel((void**)&app);
}
