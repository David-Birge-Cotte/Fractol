/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:42:14 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/10 16:42:15 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_usage(void)
{
	ft_putendl("------------------------ USAGE ----------------------------");
	ft_putendl("usage: ./fractol [fractal]");
	ft_putendl("fractals: \n -> Mandelbrot \n -> Julia \n -> Burning_Ship");
	ft_putendl("----------------------- CONTROLS --------------------------");
	ft_putendl("+ Mouse scroll to zoom to cursor");
	ft_putendl("+ Arrow keys to move camera");
	ft_putendl("+ Keypad 1, 2, 3 to change fractal type");
	ft_putendl("+ Keypad + and - to change the number of iterations");
	ft_putendl("+ Spacebar to reset view");
	ft_putendl("+ Return key to switch color type");
	ft_putendl("--------------------- JULIA PARAMETERS --------------------");
	ft_putendl("+ Move mouse to change parameters");
	ft_putendl("+ Left Ctrl key to freeze / un-freeze parameters");
	ft_putendl("-----------------------------------------------------------");
}

t_fractal	arg_handle(int argc, char **argv)
{
	t_fractal frac_type;

	frac_type = ERROR;
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			frac_type = MANDELBROT;
		else if (ft_strcmp(argv[1], "Julia") == 0)
			frac_type = JULIA;
		else if (ft_strcmp(argv[1], "Burning_Ship") == 0)
			frac_type = BURNING_SHIP;
	}
	if (frac_type == ERROR)
		print_usage();
	return (frac_type);
}
