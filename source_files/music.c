/*
** music.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Apr 13 00:15:54 2017 Corentin LEROY
** Last update Sun May 28 22:12:13 2017 Corentin LEROY
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "headers.h"

int	change_alloc_music(t_main *core, char *newmusic)
{
  int	volume;

  if (core->cur_background != NULL)
    {
      sfMusic_stop(core->cur_background);
      sfMusic_destroy(core->cur_background);
    }
  if (!(core->cur_background = sfMusic_createFromFile(newmusic)))
    return (84);
  volume = core->options->general_volume * core->options->music_volume / 100;
  sfMusic_setVolume(core->cur_background, volume);
  sfMusic_play(core->cur_background);
  sfMusic_setLoop(core->cur_background, sfTrue);
  return (0);
}

int	change_music(t_main *core, sfMusic *newmusic)
{
  int	volume;

  if (core->cur_background != NULL)
    sfMusic_stop(core->cur_background);
  volume = core->options->general_volume * core->options->music_volume / 100;
  sfMusic_setVolume(newmusic, volume);
  sfMusic_play(newmusic);
  sfMusic_setLoop(newmusic, sfTrue);
  return (0);
}

void	play_sound(t_main *core, t_sound *sound)
{
  int	vol;

  vol = core->options->general_volume * core->options->effects_volume / 100;
  if (sfMusic_getStatus(sound->music) == sfStopped)
    {
      sfMusic_setVolume(sound->music, vol);
      sfMusic_play(sound->music);
    }
}
