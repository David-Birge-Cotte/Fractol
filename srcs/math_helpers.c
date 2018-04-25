/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:11:23 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/12 14:22:55 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_vector2ld	*new_vector2ld(long double x, long double y)
{
	t_vector2ld	*vector2ld;

	vector2ld = (t_vector2ld*)malloc(sizeof(t_vector2ld));
	vector2ld->x = x;
	vector2ld->y = y;
	return (vector2ld);
}

float		lerp(const float start, const float end, const float val)
{
	return ((1 - val) * start + val * end);
}

float		map(float input, t_vector2f input_range, t_vector2f output_range)
{
	float	output;
	float	slope;

	slope = (output_range.y - output_range.x) / (input_range.y - input_range.x);
	output = output_range.x + slope * (input - input_range.x);
	return (output);
}
