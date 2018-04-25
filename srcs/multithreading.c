/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:00:53 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/25 13:00:53 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		threader(t_drawer_arg *args)
{
	size_t			i;
	SDL_Thread		**threads;
	t_drawer_arg	*specific_arg;

	i = 0;
	threads = ft_memalloc(sizeof(SDL_Thread*) * THREAD_NUM);
	while (i < THREAD_NUM)
	{
		specific_arg = cpyarg(args);
		specific_arg->screen_y_from = i * WIN_H / THREAD_NUM;
		specific_arg->screen_y_to = (i + 1) * WIN_H / THREAD_NUM;
		threads[i] = SDL_CreateThread((void*)draw_fractal,
						"thread", (void *)(specific_arg));
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
		SDL_WaitThread(threads[i++], NULL);
	ft_memdel((void**)&args);
}
