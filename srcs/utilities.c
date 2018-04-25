/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:23:14 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/17 13:23:14 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			set_screen_size(t_app *m)
{
	if (m->frac != JULIA)
	{
		m->x_size.x = -2.0f;
		m->x_size.y = 1.0f;
		m->y_size.x = -1.5f;
		m->y_size.y = 1.5f;
	}
	else
	{
		m->x_size.x = -2.0f;
		m->x_size.y = 2.0f;
		m->y_size.x = -2.0f;
		m->y_size.y = 2.0f;
	}
}

void			forward_to_mouse(t_app *m, t_vector2f *mouse_pos)
{
	t_vector2f mouse_real_pos;

	mouse_real_pos.x = map(mouse_pos->x, vector2f(0, WIN_W),
							vector2f(m->x_size.x / (float)m->zoom,
							m->x_size.y / (float)m->zoom)) + m->center_pt->x;
	mouse_real_pos.y = map(mouse_pos->y, vector2f(0, WIN_H),
							vector2f(m->y_size.x / (float)m->zoom,
							m->y_size.y / (float)m->zoom)) + m->center_pt->y;
	m->center_pt->x = mouse_real_pos.x;
	m->center_pt->y = mouse_real_pos.y;
	ft_memdel((void**)&mouse_pos);
}

t_drawer_arg	*cpyarg(const t_drawer_arg *to_copy)
{
	t_drawer_arg	*arg;

	arg = (t_drawer_arg*)malloc(sizeof(t_drawer_arg));
	arg->func_ptr = to_copy->func_ptr;
	arg->app = to_copy->app;
	arg->x_range = to_copy->x_range;
	arg->y_range = to_copy->y_range;
	return (arg);
}
