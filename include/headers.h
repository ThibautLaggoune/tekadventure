/*
** headers.h for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 20 16:58:27 2017 Corentin LEROY
** Last update Mon May 29 01:03:14 2017 thibaut
*/

#ifndef HEADERS_H_
# define HEADERS_H_

# include <SFML/Audio.h>
# include <SFML/Graphics/Font.h>
# include <SFML/Graphics/Texture.h>
# include <SFML/Graphics/RenderWindow.h>

typedef struct	s_options
{
  int		general_volume;
  int		effects_volume;
  int		music_volume;
}		t_options;

typedef struct	s_sound
{
  sfMusic	*music;
  char		*name;
}		t_sound;

/*
**  Size : largeur et hauteur en pixel
**  Resize : hauteur en pixel
**	Name : nom du fichier
**	Path : chemin depuis la racine du dossier tekadventure
**  Texture : texture à laquelle on applique le tableau
**  Sprite : l'objet image auquel on applique la texture
*/

typedef struct	s_picture
{
  sfVector2f	size;
  sfVector2f	resize;
  char		*name;
  char		*path;
  sfTexture	*texture;
  sfSprite	*sprite;
}		t_picture;

typedef struct	s_chara
{
  t_picture	*body;
  sfVector2f	pos;
  int		dir;
  sfVector2f	size;
  sfText	*text;
}		t_chara;

/*
**  ID map : identifiant unique de la map d'origine
**  ID scene : identifiant unique à la map
**  Action order : ordre et type des actions en cours, ainsi que leur id
**	type d'action:
**		0 : son
**		1 : texte
**		2 : mouvement de personnage
**		3 : rotations d'objet
**		4 : mouvement d'objet
**		5 : changement de sprite
**	id de l'action
**  Act Sound : son
*/

typedef struct	s_scene
{
  int		id_scene;
  int		**actions_order;
  sfMusic	**act_sound;
  char		**act_char_text;
  sfVector2i	**act_chara_move;
  sfVector2i	**act_objects_rotations;
  t_picture	**act_sprite_changing;
}		t_scene;

typedef struct	s_state
{
  int		bg_state;
  int		para_state;
}		t_state;

typedef struct	s_node
{
  int		level;
  char		*name;
  sfVector2f	pos;
  int		*nexts;
}		t_node;

typedef struct	s_world
{
  t_picture	*background;
  t_sound	*music;
  t_node	**list;
  int		location;
}		t_world;

typedef struct	s_map
{
  int		id_map;
  t_sound	*musical_theme;
  sfIntRect	**move_areas;
  int		**io_areas;
  int		**obj_locations;
  t_picture	**objects;
  int		**chara_locations;
  t_chara	**characters;
  int		**chara_scripts;
  t_sound	**script_sound;
  sfText	**script_text;
  t_scene	**script_scene;
  t_picture	**backgrounds;
}		t_map;

/*
**  ID de map : identifiant unique
**  Musical Theme : Musique de fond
**  Move zone : zone de déplacement
**	tableau de plusieurs zones, fini en NULL
**	première colonne : id de la zone
**	x coin haut gauche
**	y coin haut gauche
**	x largeur
**	y hauteur
**  IO zone : zone de sortie / entrée
**	tableau de plusieurs zones, fini en NULL
**	première colonne : id de la zone
**	x coin haut gauche
**	y coin haut gauche
**	x coin haut droit
**	y coin haut droit
**	id de map
**	id de zone d'arrivée
**  Obj_locations : emplacement de l'objet
**	id de l'objet
**	x de la source d'affichage : coin haut gauche
**	y de la source d'affichage : coin haut gauche
**  Objects : liste d'objets
**	première colonne : id de l'objet (le reste est dans l'objet lui-même)
**  Chara_locations : emplacement du personnages
**	id du personnage
**	x de la source d'affichage : coin haut gauche
**	y de la source d'affichage : coin haut gauche
**  Characters : liste de personnages
**	première colonne : id du personnage (le reste est dans le perso lui-même)
**  Chara scripts : contient les id de scripts en fonction des id de perso
** 	id du personnage
**	type du script
**		0 : Sound
**		1 : Bulle de texte
**		2 : cinématique ?
**	id du script
**  Script Sound : son à lancer en fonction du script
**	première colonne : id du script
**	son à lancer
**  Script Text : texte à afficher en fonction du script
**	première colonne : id du script
**	text en un char *
**  Script scene : cinématique à faire jouer en fonction du script
**	première colonne : id de la cinématique
**	appel de script
**  Backgrounds : 0 - Fond imobile, 1 - fond peu mobile, 2 Fond mobile;
*/

typedef struct	s_editor
{
  t_picture	**backgrounds;
  t_picture	**icones;
  t_picture	**parallax;
  t_picture	**objects;
  t_picture	**creatures;
  t_picture	**characters;
  t_sound	**musics;
  t_sound	**sounds;
  t_state	cur_state;
  t_map		*save;
}		t_editor;

typedef struct	s_play
{
  t_map		*cur_map;
  t_picture	**characters;
  sfVector2f	size;
  sfVector2f	chara_pos;
  sfVector2f	to_be;
  int		cur_chara;
  int		cur_way;
  int		level;
}		t_play;

typedef struct	s_files
{
  sfFont	*fonts;
  t_picture	*characters;
  t_picture	*objects;
  t_picture	*backgrounds;
  t_picture	*layouts;
  t_sound	*sounds;
}		t_files;

typedef struct		s_main
{
  sfRenderWindow	*window;
  sfFont		**fonts;
  t_options		*options;
  t_picture		**layout;
  sfMusic		*cur_background;
  t_editor		*resource;
}			t_main;

#endif /* !HEADERS_H_ */
