/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:52 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/23 15:23:53 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Use this function to calculate the next frame
** Compute data and then draw to the pixels* frame
*/

void	calculate_frame(t_app *app)
{
	clear_frame(app->pixels, app->nb_pixels);
	render(app, app->frac);
}
