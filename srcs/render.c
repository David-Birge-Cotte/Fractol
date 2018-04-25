/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:43:05 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/11 09:43:05 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** changes the color of a pixel in a frame (*pixels)
*/

void			put_pixel(t_uint32 *pixels, t_uint32 x, t_uint32 y,
					const t_color *color)
{
	if (x >= WIN_W || y >= WIN_H)
		return ;
	pixels[y * WIN_W + x] = color_to_pixeldata(color);
}

void			render(t_app *app, t_fractal fractal)
{
	t_drawer_arg	*args;

	args = (t_drawer_arg*)malloc(sizeof(t_drawer_arg));
	args->app = app;
	if (fractal == MANDELBROT)
		args->func_ptr = &draw_mandelbrot;
	if (fractal == JULIA)
		args->func_ptr = &draw_julia;
	if (fractal == BURNING_SHIP)
		args->func_ptr = &draw_burning_ship;
	args->x_range = vector2f((args->app->x_size.x + args->app->center_pt->x
						* (float)args->app->zoom) / (float)args->app->zoom,
					(args->app->x_size.y + args->app->center_pt->x
						* (float)args->app->zoom) / (float)args->app->zoom);
	args->y_range = vector2f((args->app->y_size.x + args->app->center_pt->y
						* (float)args->app->zoom) / (float)args->app->zoom,
					(args->app->y_size.y + args->app->center_pt->y
						* (float)args->app->zoom) / (float)args->app->zoom);
	threader(args);
}

/*
** Sets all the pixels of the frame to a color
*/

void			fill_frame(t_uint32 *pixels, size_t nb_pixels, t_color *color)
{
	t_uint32	pixel_color;

	pixel_color = color_to_pixeldata(color);
	ft_memset((void*)pixels, pixel_color,
		(size_t)(nb_pixels * sizeof(t_uint32)));
}

/*
** Sets all the pixels of the frame to a 0 (transparent)
*/

void			clear_frame(t_uint32 *pixels, size_t nb_pixels)
{
	t_color	*transparent;

	transparent = new_color(0, 0, 0, 0);
	fill_frame(pixels, nb_pixels, transparent);
	ft_memdel((void**)&transparent);
}

/*
** Draws the frame (*pixels) to the SDL
*/

int				display(t_sdl *sdl, t_uint32 *pixels)
{
	size_t	win_size;

	win_size = WIN_W * sizeof(t_uint32);
	if (SDL_UpdateTexture(sdl->frame, NULL, pixels, win_size) == -1)
		return (-1);
	if (SDL_RenderClear(sdl->renderer) == -1)
		return (-1);
	if (SDL_RenderCopy(sdl->renderer, sdl->frame, NULL, NULL) == -1)
		return (-1);
	SDL_RenderPresent(sdl->renderer);
	return (0);
}
