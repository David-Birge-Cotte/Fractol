/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:28 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:30 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Listens to event and responds to them
*/

void		handle_event(t_app *app)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	ft_memdel((void**)&app->sdl->event);
	app->sdl->event = ft_memalloc(sizeof(SDL_Event));
	SDL_PollEvent(app->sdl->event);
	if (app->sdl->event->type == SDL_QUIT)
		app->loop = FALSE;
	else if (app->sdl->event->type == SDL_KEYDOWN)
		key_press(app->sdl->event->key.keysym.sym, app);
	else if (app->sdl->event->type == SDL_MOUSEMOTION)
		mouse_move(x, y, app);
	else if (app->sdl->event->type == SDL_MOUSEWHEEL)
		mouse_roll(x, y, app->sdl->event->wheel.y, app);
}
