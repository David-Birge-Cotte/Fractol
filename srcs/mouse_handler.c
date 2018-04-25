/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:12:19 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/18 16:12:20 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mouse_roll(int x, int y, int val, t_app *app)
{
	if (val == 0)
		return (0);
	if (val > 0)
	{
		app->zoom *= 2;
		forward_to_mouse(app, new_vector2f(x, y));
	}
	else
	{
		if (app->zoom > 1)
			app->zoom /= 2;
	}
	render(app, app->frac);
	return (0);
}

int			mouse_move(int x, int y, t_app *app)
{
	if (app->julia_mouse == 0)
		return (0);
	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return (0);
	app->para.x = map(y, vector2f(0, WIN_H), vector2f(-1.0f, 1.0f));
	app->para.y = map(x, vector2f(0, WIN_W), vector2f(-1.0f, 1.0f));
	if (app->frac == JULIA)
		render(app, app->frac);
	return (0);
}
