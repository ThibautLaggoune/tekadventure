/*
** main.h for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 14:42:34 2017 Corentin LEROY
** Last update Mon May 29 01:30:10 2017 thibaut
*/

#ifndef MAIN_H_
# define MAIN_H_

# include <SFML/Graphics/Text.h>
# include "headers.h"

/*
**	Display
*/

void	position_parallax(t_play *resources, float shift);
void	display_parallax(t_main *core, t_map *map);
int		display_save(t_main *core);
int	display_rect_from_intrect(t_main *core, sfIntRect **tab, sfColor color);
int	display_rect_from_int(t_main *core, int **tab, sfColor color);

/*
**	Edit
*/

int	edit_menu(t_main *core);
void	initeditptr(int	(**ptr)());
int	edit_sub_sprite(t_main *core, t_editor *resource, sfEvent *event);
int		drop_sprite(t_main *core, sfEvent *event, t_picture *tmp);
t_picture	*pick_sprite(t_main *core, sfEvent *event, t_picture **image,
			     int *s_chara);

/*
**	Event
*/

int	event_play_map(t_main *core, sfEvent *event, t_play *resource);
int	event_main_menu(t_main *core, sfEvent *event);
void	initoptptr(int (**ptr)());
int	event_option_menu(t_main *core, sfEvent *event);
int	event_edit_menu(t_main *core, sfEvent *event, t_editor *resource,
int	param[2]);
int	event_icone_chara(t_main *core, t_picture **sprite, sfEvent *event,
				  int *s_chara);
int	event_world_map(t_main *core, sfEvent *event, t_play *resource, t_world *map);

/*
**	Fill map
*/

int	fill_id(t_map *map, char **buff, int *i);
int	fill_music(t_map *map, char **buff, int *i);
int	fill_moveareas(t_map *map, char **buff, int *i);
int	fill_ioareas(t_map *map, char **buff, int *i);
int	fill_parallax(t_map *map, char **buff, int *i);
int	fill_background(t_map *map, char **buff, int *i);
int	fill_chara(t_map *map, char **buff, int *i);
int	fill_charapos(t_map *map, char **buff, int *i);
int	fill_charatext(t_map *map, char **buff, int *i);
int	fill_charasound(t_map *map, char **buff, int *i);

/*
**	Free
*/

void	free_inttab(int **tab);
void	free_intrecttab(sfIntRect **tab);
void	free_pictures(t_picture **pics);
void	free_musics(t_sound **sounds);
void	free_nodes(t_node **nodes);

/*
**	Loading
*/

int		loading_screen(t_main *core);

/*
**	Map
*/

t_map	*init_map(int id);
void	unparse_map(t_main *core, t_map *map);
int		play_map(t_main *core, t_play *resource, int id, char *folder_name);
t_map	*get_map(int id, char **files, char *folder_name);
t_map	*fill_map_struct(int id, char **buff);

/*
**	Menu
*/

int	main_menu(t_main *core);
void	initmenuptr(int (*ptr[4])(t_main *));
int	main_menu_sprites(sfRenderWindow *window, sfFont *menuf, int mode);

/*
**	Move
*/

int	move_next_bck(t_main *core, int param[2], t_editor *resource);
int	move_previous_bck(t_main *core, int param[2], t_editor *resource);
int	move_upper_bck(t_main *core, int param[2], t_editor *resource);
int	move_lower_bck(t_main *core, int param[2], t_editor *resource);
int	move_characters(t_main *core, t_play *resource);
void	init_compare_input(int (**ptr)());
int	draw_icone_move_area(t_main *core, t_editor *resource);
void	move_height(t_play *resource);
int	get_pos(int mode);
int	compar_int(float a, float b);
int	move_icone_io(t_main *core, t_editor *resource);
int	save_rekt(t_editor *resource, sfIntRect *rect, t_main *core);
int	check_norm(t_main *core, sfEvent event, t_editor *resource, sfIntRect rect);
int	move_icone_move_area(t_main *core, t_editor *resource);

/*
**	Music
*/

int	change_alloc_music(t_main *core, char *newmusic);
int	change_music(t_main *core, sfMusic *newmusic);
int	change_general_volume(t_main *core, int x, int y);
int	change_music_volume(t_main *core, int x, int y);
int	change_effects_volume(t_main *core, int x, int y);
void	play_sound(t_main *core, t_sound *sound);

/*
**	NPC
*/

int	display_npc(t_main *core, t_map *map);

/*
**	Options
*/

int		menu_options(t_main *core);
t_options	*init_options(int general, int effects, int music);

/*
**	Parsing Files
*/

int	check_id(int fd, int id);
t_editor	*parse_files_editor();
char		**get_files(char *path);
void	unparse_files_editor(t_main *core, t_editor *resources);
t_picture	**get_pictures(char *path);
t_picture	**get_multi(char *path, int width, int height, sfVector2f size);

/*
**	Play
*/

int	play_menu(t_main *core);
int	play_worldmap(t_main *core, t_play *resource, char *path, int origin);

/*
**	Quit
*/

int	quit_edit(t_main *core, int param[2], t_editor *resource);
int	quitoptions(t_main *core, int x, int y);
int	quitgame(t_main *core);
int	return_backward(t_main *core, t_picture **sprite, int **s_chara);
int	save_in_file(t_editor *resource);
int	get_out(t_play *resource);

/*
**	Rectangles
*/

sfIntRect	*allocintrect(char *top, char *left, char *width, char *height);
void	getrectmenu(sfIntRect *menu);
void	getrectoptions(sfIntRect *menu);
int	print_rectangle(sfVector2f tl, sfVector2i wh, sfColor color,
				sfRenderWindow *window);
sfIntRect	getintrect(int top, int left, int width, int height);
int	print_draw_rect_ma(t_main *core);

/*
**	Sprite
*/

t_picture	*set_texture(sfVector2f scale, char *path, char *name);
sfVector2f	get_size_from_bounds(sfSprite *sprite);

/*
**	Text
*/

void		display_text(t_main *core, sfText *to_disp);
sfText	*create_new_text(char *text, sfColor color, sfFont *font, int size);
void	text_destroy(sfText *t1, sfText *t2, sfText *t3, sfText *t4);
sfFont	**init_fonts();

/*
**	Vector
*/

sfVector2f	getv2f(float x, float y);
sfVector2i	getv2i(int x, int y);

/*
**	Window
*/

sfRenderWindow	*open_window(char *name, int width, int height);

/*
**	Worldmap
*/

int	fillw_id(t_world *map, char **buff, int *i);
int	fillw_music(t_world *map, char **buff, int *i);
int	fillw_background(t_world *map, char **buff, int *i);
int	fillw_nodes(t_world *map, char **buff, int *i);
t_world	*fill_worldmap_struct(char **buff);
void	unparse_worldmap(t_main *core, t_world *map);
t_world	*get_worldmap(char **files, char *folder_name);
int		world_characters(t_main *core, t_play *resource, t_world *map);

#endif /* !MAIN_H_ */
