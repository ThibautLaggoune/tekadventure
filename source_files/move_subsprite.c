/*
** move_subsprite.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue May 23 11:04:42 2017 Corentin LEROY
** Last update Thu May 25 13:39:10 2017 thibaut
*/

#include "headers.h"
#include "macro.h"
#include "main.h"

int	move_down_subsprite(t_main *core, t_picture **sprite, int *s_chara)
{
  (void)core;
  (void)sprite;
  if (s_chara[s_chara[0] + 1] > -1 && s_chara[s_chara[0] + 2] > -1)
    s_chara[0] += 1;
  return (1);
}

int	move_left_subsprite(t_main *core, t_picture **sprite, int *s_chara)
{
  (void)core;
  (void)sprite;
  if (s_chara[s_chara[0] + 1] > 0)
    s_chara[s_chara[0] + 1] -= 1;
  return (1);
}

int	move_right_subsprite(t_main *core, t_picture **sprite, int *s_chara)
{
  (void)core;
  if (sprite[s_chara[0] * SPRITE_PER_LINE + s_chara[s_chara[0] + 1] + 1])
    {
      s_chara[s_chara[0] + 1] += 1;
      if (s_chara[s_chara[0] + 1] > SPRITE_PER_LINE - NBSPRITE)
	s_chara[s_chara[0] + 1] = SPRITE_PER_LINE - NBSPRITE;
    }
  return (1);
}

int	move_up_subsprite(t_main *core, t_picture **sprite, int *s_chara)
{
  (void)core;
  (void)sprite;
  if (s_chara[0] > 0)
    s_chara[0] -= 1;
  return (1);
}

void	init_compare_input(int (**ptr)())
{
  ptr[0] = move_left_subsprite;
  ptr[1] = move_right_subsprite;
  ptr[2] = move_up_subsprite;
  ptr[3] = move_down_subsprite;
  ptr[4] = return_backward;
}
