/*
** macro.h for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Fri Apr 28 13:40:22 2017 Corentin LEROY
** Last update Thu May 25 13:34:26 2017 thibaut
*/

#ifndef MACRO_H_
# define MACRO_H_

# define SWIDTH	1280
# define SHEIGHT	720
# ifndef UNUSED
#  define UNUSED(x)	(void(x))
# endif /* !UNUSED */
# define MYABS(x)	x > 0 ? x : -x

# define MAPFIELD	10
# define WORLDMAPFIELD	4
# define FILLID	"id"
# define FILLMU	"music"
# define FILLBG	"background"
# define FILLPA	"parallax"
# define FILLMO	"move areas"
# define FILLIO	"inside/out areas"
# define FILLNP	"npc"
# define FILLPO	"npc pos"
# define FILLTE	"npc text"
# define FILLSO	"npc sound"
# define FILLNO	"nodes"
# define IOFIELD	6

# define NBICONE	5
# define PTREDIT	7
# define PTRMAIN	4
# define PTROPTION	4
# define PTRSPRITE	5
# define NBSPRITE	10
# define SPRITE_PER_LINE 27

#endif /* !MACRO_H_ */
