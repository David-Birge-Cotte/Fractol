/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:58:06 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/13 11:58:06 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	reset_view(t_app *app)
{
	app->zoom = 1;
	app->center_pt->x = 0;
	app->center_pt->y = 0;
	app->nb_itera = NB_ITERATION;
	set_screen_size(app);
}

static void	change_fractal(t_app *app, int keycode)
{
	if (keycode == SDLK_1 && app->frac != MANDELBROT)
	{
		app->frac = MANDELBROT;
		reset_view(app);
	}
	else if (keycode == SDLK_2 && app->frac != JULIA)
	{
		app->frac = JULIA;
		reset_view(app);
	}
	else if (keycode == SDLK_3 && app->frac != BURNING_SHIP)
	{
		app->frac = BURNING_SHIP;
		reset_view(app);
	}
}

static void	move_handle(t_app *app, int keycode)
{
	if (keycode == SDLK_LEFT)
		app->center_pt->x -= (float)(MOVE_SPEED / app->zoom);
	if (keycode == SDLK_RIGHT)
		app->center_pt->x += (float)(MOVE_SPEED / app->zoom);
	if (keycode == SDLK_DOWN)
		app->center_pt->y += (float)(MOVE_SPEED / app->zoom);
	if (keycode == SDLK_UP)
		app->center_pt->y -= (float)(MOVE_SPEED / app->zoom);
}

static void	change_color(t_app *app)
{
	if (app->color_mode < 2)
		app->color_mode++;
	else
		app->color_mode = 0;
}

int			key_press(int keycode, t_app *app)
{
	move_handle(app, keycode);
	change_fractal(app, keycode);
	if (keycode == SDLK_PLUS || keycode == SDLK_KP_PLUS)
		app->nb_itera += 4;
	if (keycode == SDLK_MINUS || keycode == SDLK_KP_MINUS)
	{
		if (app->nb_itera > 4)
			app->nb_itera -= 4;
	}
	if (keycode == SDLK_SPACE)
		reset_view(app);
	if (keycode == SDLK_RETURN)
		change_color(app);
	if (keycode == SDLK_ESCAPE)
		app->loop = FALSE;
	if (keycode == SDLK_LCTRL)
		app->julia_mouse ^= 1;
	render(app, app->frac);
	return (0);
}
