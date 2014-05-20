/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 23:56:54 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/07 21:23:05 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "get_next_line.h"
# include <mlx.h>
# include "lists.h"
# include <X11/xlib.h>
# include <X11/cursorfont.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e);
void	ft_draw(t_env *e);
int		mouse_hook(int x, int y, t_env *e);
void	ft_dda(t_env *env);
void	ft_init(t_env *env);
int		mouse_click_hook(int button, int x, int y, t_env *env);
void	init(t_env *e);
void	raycasting(t_env *e);
int		ft_intdraw(t_env *e);

void	ft_create_minimap(t_env *e);
void	draw_map(t_env *e, t_maps map);
void	ft_bezero(t_env *e);
void	draw_player(t_env *e, double x, double y);
void	ft_create_bigmap(t_env *e);
void	draw_view(t_env *e, double a, double b);
void	draw_seg(t_env *e, t_cord p1, t_cord p2);
char	**ft_lecture(char *file, t_env *e);
t_level	*fill();
void	menu(t_env *e);
int		mouse_menu_hook(int button, int x, int y, t_env *e);
void	sauvegarde(t_env *e);
t_level	*loading(t_env *e);
int		main(int ac, char **av);
void	check_point(t_env *e);
void	delete_check(t_env *e);
void	choice(t_env *e);
void	i9tira7(t_env *e, int x, int y, int button);
t_level	*charge(t_env *e);

void	ft_drawtext(t_env *data);
void	ft_settext(t_env *data, double y);
void	ft_gettextx(t_env *data);
void	fill_texture(t_env *e);
int		map_text(t_env *e);

void	flooring(t_env *e);
void	ft_draw_floor(t_env *e);
void	ft_draw_ceil(t_env *e);

int		ft_expose_hook(t_env *e);
int		ft_main_hook(t_env *e);
t_env	*get_instance();
void	chargement(t_env *e);
void	draw_point(t_env *e, double x, double y);
void	fill_sprites(t_env *e);
void	sprite_casting(t_env *e, int nb);
void	fill_obj(t_env *e);

void	checks(t_env *e, char **tab, int i, int j);
void	check_obj(t_env *e, char **tab, int i, int j);
void	combSort(int *order, double *dist, int amount);
void	ft_draw_weapon(t_env *data, int x, int y, t_img *xpm);
void	ft_draw_thing(t_env *e, int x);

#endif /* WOLF_H */
