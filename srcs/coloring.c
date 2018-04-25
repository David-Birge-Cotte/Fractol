/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:18:03 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/25 14:15:57 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_color	*get_color_from_scheme_linear(float val, t_color_scheme *scheme)
{
	t_color	*color;
	size_t	i;
	float	icp;
	float	increment;

	i = 1;
	increment = (float)(1.0f / (scheme->nb_colors - 1));
	icp = increment;
	while (val > icp)
	{
		icp += increment;
		i++;
	}
	color = lerp_color(scheme->scheme[i - 1], scheme->scheme[i], val);
	return (color);
}

static t_color	*get_ultracolor_linear(float val, t_color_scheme *scheme)
{
	t_color	*color;

	if (val < 0.16f)
	{
		val = map(val, vector2f(0.0f, 0.16f), vector2f(0.0f, 1.0f));
		color = lerp_color(scheme->scheme[0], scheme->scheme[1], val);
	}
	else if (val < 0.42f)
	{
		val = map(val, vector2f(0.16f, 0.42f), vector2f(0.0f, 1.0f));
		color = lerp_color(scheme->scheme[1], scheme->scheme[2], val);
	}
	else if (val < 0.6425f)
	{
		val = map(val, vector2f(0.42f, 0.6425f), vector2f(0.0f, 1.0f));
		color = lerp_color(scheme->scheme[2], scheme->scheme[3], val);
	}
	else if (val < 0.8575f)
	{
		val = map(val, vector2f(0.6425f, 0.8575f), vector2f(0.0f, 1.0f));
		color = lerp_color(scheme->scheme[3], scheme->scheme[4], val);
	}
	else
		color = copy_color(scheme->scheme[4]);
	return (color);
}

static t_color	*greyscale(int val, int nb_iteration)
{
	t_color *color;

	val = map(val, vector2f(0, nb_iteration), vector2f(0, 255));
	color = new_color(val, val, val, 255);
	return (color);
}

t_color			*color_from_val(int val, int nb_iteration,
									t_color_scheme *scheme, t_color_mode mode)
{
	t_color *color;

	if (mode == ULTRACOLOR)
		color = get_ultracolor_linear(map(val, vector2f(0, nb_iteration),
										vector2f(0.0f, 1.0f)), scheme);
	else if (mode == LINEAR)
		color = get_color_from_scheme_linear(map(val, vector2f(0, nb_iteration),
										vector2f(0.0f, 1.0f)), scheme);
	else
		color = greyscale(val, nb_iteration);
	return (color);
}
