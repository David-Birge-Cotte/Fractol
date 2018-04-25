/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_allocator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:48 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:50 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Creates a new sdl instance
*/

t_sdl	*new_sdl(void)
{
	t_sdl	*sdl;

	if ((sdl = ft_memalloc(sizeof(t_sdl))) == NULL)
		return (NULL);
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		return (NULL);
	if ((sdl->event = ft_memalloc(sizeof(SDL_Event))) == NULL)
		return (NULL);
	if ((sdl->win = SDL_CreateWindow(WIN_TITLE, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H,
			SDL_WINDOW_BORDERLESS)) == NULL)
		return (NULL);
	if ((sdl->renderer = SDL_CreateRenderer(sdl->win, -1, 0)) == NULL)
		return (NULL);
	if (SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0) == -1)
		return (NULL);
	if ((sdl->frame = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, WIN_W, WIN_H)) == NULL)
		return (NULL);
	if (SDL_SetTextureBlendMode(sdl->frame, SDL_BLENDMODE_BLEND) == -1)
		return (NULL);
	return (sdl);
}

/*
** Destroys the sdl instance
*/

void	sdl_del(t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->frame);
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->win);
	ft_memdel((void**)&sdl->event);
	ft_memdel((void**)&sdl);
	SDL_Quit();
}
