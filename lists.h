/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 21:35:46 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/07 21:35:48 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <fcntl.h>
# include <mlx.h>
# include <X11/xlib.h>
# include <X11/cursorfont.h>

# define MLX_MAX_EVENT LASTEvent
# define LAR 1500
# define LON 1400
# define ABS(x) ((x >= 0) ? x : -(x))
# define LON_M LON - (LON / 6)
# define LAR_M LAR - (LAR / 6)
# define RIGHT_X LAR_M + (a * (e->posx + e->dirx - e->planex))
# define RIGHT_Y LON_M + (b * (e->posy + e->diry - e->planey))
# define LEFT_X LAR_M + (a * (e->posx + e->dirx + e->planex))
# define LEFT_Y LON_M + (b * (e->posy + e->diry + e->planey))

# define LEAVE_0 (e->leave_x == (int)e->posx && e->leave_y == (int)e->posy)
# define LEAVE_1 (e->leave_x + 1 == (int)e->posx && e->leave_y == (int)e->posy)
# define LEAVE_2 (e->leave_x == (int)e->posx && e->leave_y + 1 == (int)e->posy)
# define LEAVE_3 (e->leave_x + 1 == (int)e->posx && e->leave_y + 1 ==\
					(int)e->posy)
# define LEAVE_4 (e->leave_x - 1 == (int)e->posx && e->leave_y - 1 ==\
					(int)e->posy)
# define LEAVE_5 (e->leave_x == (int)e->posx && e->leave_y - 1 == (int)e->posy)
# define LEAVE_6 (e->leave_x - 1 == (int)e->posx && e->leave_y == (int)e->posy)

# define OUT (((e->bpp >> 3) * ((e->size_line - 10) >> 2) * LON))

# define SPRT (e->text[e->tid]->bpp >> 3) * \
				(e->texty * e->text[e->tid]->width) + \
				(e->textx * e->text[e->tid]->bpp)

# define HIT (env->map[env->mapy][env->mapx] != '0'\
				&& (ft_isdigit(env->map[env->mapy][env->mapx])))

# define PERP_NULL ((env->mapx - env->rayposx + (1 - env->stepx)\
									/ 2) / env->raydirx)

# define PERP ((env->mapy - env->rayposy + (1 - env->stepy) / 2) / env->raydiry)

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define OK 65293

# define BLUE 0x0000cc
# define GREEN 0x00cc00
# define BROWN 0xcc6600
# define GRAY 0x999999
# define FUSHIA 0xcc00cc
# define YELLOW 0xcccc00
# define CYAN 0xccffff
# define WHITE 0xffffff
# define RED 0xff0000

#define SIZE_MAP 20
#define MOVE_SPEED 0.3

typedef struct		s_level
{
	char			*str;
	char			*lvl;
	struct s_level	*next;
}					t_level;

typedef struct			s_img
{
	XImage				*image;
	Pixmap				pix;
	GC					gc;
	int					size_line;
	int					bpp;
	int					width;
	int					height;
	int					type;
	int					format;
	char				*data;
}						t_img;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture;
	int			i;
	int			mul;
}				t_sprite;

typedef struct			s_env
{
	t_img				*text[16];
	t_img				*obj[5];
	t_sprite			sprite[100];
	char				**map_obj;
	int					x;
	int					nb_l;
	int					nb_c;
	char				**map;
	void				*mlx;
	void				*win;
	t_img				*img;
	void				*img2;
	int					bpp;
	int					bpp2;
	int					size_line;
	int					size_line2;
	int					endian;
	int					endian2;
	char				*str;
	char				*str2;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				camerax;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				ddistx;
	double				ddisty;
	double				perpwalldist;
	int					draw;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					color;
	float				rotspeed;
	int					bol;
	double				enter_x;
	double				enter_y;
	double				leave_x;
	double				leave_y;
	double				check_x;
	double				check_y;
	t_level				*stage;
	float				angle;
	int					choix;
	int					tid;
	int					tis;
	double				wallx;
	int					in;
	double				y;
	double				floorXWall;
	double				floorYWall;
	int					floorTexX;
	int					floorTexY;
	int					textx;
	int	 				texty;
	double			Zbuffer[LAR];
	double			*sprite_Distance;
	int				sprites_nb;
	double			invDet;
	double			spriteX;
	double			spriteY;
	double			transformX;
	double			transformY;
	int				spriteScreenX;
	int				spriteHeight;
	int				drawStartY;
	int				drawEndY;
	int				spriteWidth;
	int				drawStartX;
	int				drawEndX;
	double			starX;
	double			starY;
	double			endX;
	double			endY;
}						t_env;


typedef struct			s_xpm_col
{
	int					name;
	int					col;
}						t_xpm_col;


struct					s_col_name
{
	char				*name;
	int					color;
};

typedef struct		s_event_list
{
	int				mask;
	int				(*hook)();
	void			*param;
}					t_event_list;


typedef struct			s_win_list
{
	Window				window;
	GC					gc;
	struct s_win_list	*next;
	int					(*mouse_hook)();
	int					(*key_hook)();
	int					(*expose_hook)();
	void				*mouse_param;
	void				*key_param;
	void				*expose_param;
	t_event_list		hooks[MLX_MAX_EVENT];
}						t_win_list;


typedef struct			s_xvar
{
	Display				*display;
	Window				root;
	int					screen;
	int					depth;
	Visual				*visual;
	Colormap			cmap;
	int					private_cmap;
	t_win_list			*win_list;
	int					(*loop_hook)();
	void				*loop_param;
	int					use_xshm;
	int					pshm_format;
	int					do_flush;
	int					decrgb[6];
}						t_xvar;

typedef struct	s_resume
{
	double		weight;
	double		distWall;
	double		distPlayer;
	double		currentDist;
	double		currentFloorX;
	double		currentFloorY;
}				t_resume;

typedef struct	s_maps
{
	double		a;
	double		b;
	int			i;
	int			j;
	double		x;
	double		y;
}				t_maps;

typedef struct	s_seg
{
	float		a;
	double		temp;
	double		cste;
	double		x;
	double		y;
	double		dy;
	double		dx;
}				t_seg;

typedef struct	s_cord
{
	double		x;
	double		y;
}				t_cord;

#endif /* LISTS_H */
