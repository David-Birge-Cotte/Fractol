/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:31:41 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/10 16:32:11 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_TITLE		"Fractal Drawer"
# define WIN_W		768
# define WIN_H		768
# define THREAD_NUM		8
# define MOVE_SPEED		0.05f
# define NB_ITERATION	48

# include <SDL2/SDL.h>
# include "../libft/libft.h"
# include <pthread.h>
# include <stdarg.h>

/*
** Typedef for common unsigned types
*/
typedef unsigned int	t_uint32;
typedef unsigned char	t_uint8;

/*
** Boolean type 0 = FALSE, 1 = TRUE
*/
typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef enum		e_fractal
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
	ERROR
}					t_fractal;

typedef enum		e_color_mode
{
	ULTRACOLOR,
	LINEAR,
	GREYSCALE
}					t_color_mode;

typedef struct		s_s_coords
{
	float			x_min;
	float			x_max;
	float			y_min;
	float			y_max;
}					t_s_coords;

/*
** Vectors2
*/
typedef struct		s_vector2i
{
	int				x;
	int				y;
}					t_vector2i;

typedef struct		s_vector2f
{
	float			x;
	float			y;
}					t_vector2f;

typedef struct		s_vector2ld
{
	long double		x;
	long double		y;
}					t_vector2ld;

/*
** 32 bit color structure RGBA8888
*/
typedef struct		s_color
{
	t_uint8			r;
	t_uint8			g;
	t_uint8			b;
	t_uint8			a;
}					t_color;

typedef struct		s_color_scheme
{
	t_color			**scheme;
	size_t			nb_colors;
}					t_color_scheme;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Texture		*frame;
	SDL_Event		*event;
}					t_sdl;

typedef struct		s_app
{
	t_bool			loop;
	t_uint32		*pixels;
	size_t			nb_pixels;
	t_sdl			*sdl;
	size_t			zoom;
	t_vector2f		*center_pt;
	size_t			nb_itera;
	t_fractal		frac;
	t_color_scheme	*color_scheme;
	t_vector2f		para;
	t_vector2f		x_size;
	t_vector2f		y_size;
	t_color_mode	color_mode;
	char			julia_mouse;
}					t_app;

typedef struct		s_drawer_arg
{
	t_app			*app;
	size_t			screen_y_from;
	size_t			screen_y_to;
	t_vector2f		x_range;
	t_vector2f		y_range;
	int				(*func_ptr)(const t_vector2ld *p,
						const size_t nb_iteration, t_vector2f param);
}					t_drawer_arg;

/*
** App & SDL
*/
t_app				*new_app(void);
void				app_del(t_app *app);
t_sdl				*new_sdl(void);
void				sdl_del(t_sdl *sdl);
void				quit_app(void);

/*
** Colors
*/
t_uint32			color_to_pixeldata(const t_color *color);
t_color				*new_color(t_uint8 r, t_uint8 g, t_uint8 b, t_uint8 a);
t_color				*copy_color(const t_color *color_cpy);
t_color				*lerp_color(const t_color *start, const t_color *end, float t);
t_color				*color_from_val(int val, int nb_iteration,
						t_color_scheme *scheme, t_color_mode mode);
t_color_scheme		*new_scheme(size_t size, t_color *color, ...);

/*
** Draw
*/
void				calculate_frame(t_app *app);
void				clear_frame(t_uint32 *pixels, size_t nb_pixels);
void				fill_frame (t_uint32 *pixels, size_t nb_pixels, t_color *color);
int					display(t_sdl *sdl, t_uint32 *pixels);
void				put_pixel(t_uint32 *pixels, t_uint32 x, t_uint32 y, const t_color *color);

/*
** Events
*/
void				handle_event(t_app *app);
int					mouse_move(int x, int y, t_app *app);
int					mouse_roll(int x, int y, int val, t_app *app);
int					key_press(int keycode, t_app *app);

/*
** Math
*/
t_vector2i			*new_vector2i(int x, int y);
t_vector2i			vector2i(int x, int y);
t_vector2f			*new_vector2f(float x, float y);
t_vector2f			vector2f(float x, float y);
float				lerp(const float start, const float end, const float t);
float				map(float input, t_vector2f input_range, t_vector2f output_range);
t_vector2ld			*new_vector2ld(long double x, long double y);

/*
** Other
*/

t_fractal			arg_handle(int argc, char **argv);
void				render(t_app *m, t_fractal fractal);
void				forward_to_mouse(t_app *m, t_vector2f *mouse_pos);
void				backward_from_mouse(t_app *m, t_vector2f *mouse_pos);
t_s_coords			new_coords(float x_min, float x_max,
						float y_min, float y_max);
void				set_screen_size(t_app *m);
int					draw_mandelbrot(const t_vector2ld *p,
						const size_t nb_iteration, t_vector2f param);
int					draw_julia(const t_vector2ld *p, const size_t nb_iteration,
						t_vector2f param);
int					draw_burning_ship(const t_vector2ld *p,
						const size_t nb_iteration, t_vector2f param);
void				*draw_fractal(t_drawer_arg *args);
t_drawer_arg		*cpyarg(const t_drawer_arg *to_copy);
void				threader(t_drawer_arg *args);

#endif
