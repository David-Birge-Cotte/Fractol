/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:31:45 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/10 16:32:27 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** This is the main loop
*/

static void			loop(t_app *app)
{
	handle_event(app);
	display(app->sdl, app->pixels);
}

/*
** The entry point of the program
*/

int					main(int argc, char **argv)
{
	t_app		*app;
	t_fractal	fractal;

	if ((fractal = arg_handle(argc, argv)) == ERROR)
		return (-1);
	if ((app = new_app()) == NULL)
		return (-1);
	app->frac = fractal;
	set_screen_size(app);
	calculate_frame(app);
	while (app->loop)
		loop(app);
	app_del(app);
	return (0);
}
