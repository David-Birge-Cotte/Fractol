/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:11:59 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/18 11:11:59 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_vector2f	*new_vector2f(float x, float y)
{
	t_vector2f	*vector2f;

	vector2f = (t_vector2f*)malloc(sizeof(t_vector2f));
	vector2f->x = x;
	vector2f->y = y;
	return (vector2f);
}

t_vector2f	vector2f(float x, float y)
{
	t_vector2f	vector2f;

	vector2f.x = x;
	vector2f.y = y;
	return (vector2f);
}
