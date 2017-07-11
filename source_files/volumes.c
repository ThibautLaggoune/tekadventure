/*
** volumes.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Apr 13 09:19:54 2017 Corentin LEROY
** Last update Thu Apr 13 09:19:54 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include "headers.h"

int	change_music_volume(t_main *core, int x, int y)
{
  core->options->music_volume = (x - 300) / 3;
  y = (core->options->music_volume * core->options->general_volume) / 100;
  sfMusic_setVolume(core->cur_background, y);
  return (1);
}

int	change_effects_volume(t_main *core, int x, int y)
{
  (void)y;
  core->options->effects_volume = (x - 300) / 3;
  return (3);
}

int	change_general_volume(t_main *core, int x, int y)
{
  core->options->general_volume = (x - 300) / 3;
  y = (core->options->music_volume * core->options->general_volume) / 100 ;
  sfMusic_setVolume(core->cur_background, y);
  return (1);
}
