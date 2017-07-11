/*
** options.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed Apr 12 21:49:27 2017 Corentin LEROY
** Last update Fri May  5 00:44:15 2017 Corentin LEROY
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Window/Event.h>
#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "main.h"

t_options	*init_options(int general, int effects, int music)
{
  t_options	*ret;

  if (!(ret = malloc(sizeof(*ret))))
    return (NULL);
  ret->general_volume = general;
  ret->effects_volume = effects;
  ret->music_volume = music;
  return (ret);
}

int	display_options_sprites(sfRenderWindow *window, sfFont *menu_font)
{
  sfText	*vol;
  sfText	*general;
  sfText	*music;
  sfText	*effects;
  sfText	*ret;

  if (!(vol = create_new_text("OPTIONS DE VOLUME", sfBlack, menu_font, 75)) ||
      !(general = create_new_text("GENERAL", sfBlack, menu_font, 75))||
      !(music = create_new_text("MUSIQUE", sfBlack, menu_font, 75)) ||
      !(effects = create_new_text("EFFETS", sfBlack, menu_font, 75)) ||
      !(ret = create_new_text("RETOUR", sfBlack, menu_font, 75)))
    return (84);
  sfText_setPosition(vol, getv2f(50, SHEIGHT / 2 - 260));
  sfText_setPosition(general, getv2f(50, SHEIGHT / 2 - 160));
  sfText_setPosition(music, getv2f(50, SHEIGHT / 2 - 60));
  sfText_setPosition(effects, getv2f(50, SHEIGHT / 2 + 40));
  sfText_setPosition(ret, getv2f(50, SHEIGHT / 2 + 140));
  sfRenderWindow_drawText(window, vol, NULL);
  sfRenderWindow_drawText(window, general, NULL);
  sfRenderWindow_drawText(window, music, NULL);
  sfRenderWindow_drawText(window, effects, NULL);
  sfRenderWindow_drawText(window, ret, NULL);
  text_destroy(vol, general, music, effects);
  sfText_destroy(ret);
  return (0);
}

int	options_display(t_main *core)
{
  sfVector2f	pos;

  if (display_options_sprites(core->window, core->fonts[0]))
    return (84);
  pos = getv2f(300, 240);
  if (print_rectangle(pos, getv2i(300, 10), sfBlack, core->window) > 1)
    return (84);
  pos = getv2f(300 + core->options->general_volume * 3 - 5, 230);
  if (print_rectangle(pos, getv2i(10, 30), sfBlack, core->window) > 1)
    return (84);
  pos = getv2f(300, 340);
  if (print_rectangle(pos, getv2i(300, 10), sfBlack, core->window) > 1)
    return (84);
  pos = getv2f(300 + core->options->music_volume * 3 - 5, 330);
  if (print_rectangle(pos, getv2i(10, 30), sfBlack, core->window) > 1)
    return (84);
  pos = getv2f(300, 440);
  if (print_rectangle(pos, getv2i(300, 10), sfBlack, core->window) > 1)
    return (84);
  pos = getv2f(300 + core->options->effects_volume * 3 - 5, 430);
  if (print_rectangle(pos, getv2i(10, 30), sfBlack, core->window) > 1)
    return (84);
  return (0);
}

int	handle_ret(t_main *core, sfMusic *sound, int ret)
{
  int	vol;

  vol = core->options->effects_volume * core->options->general_volume / 100;
  if (ret == 3)
    {
      sfMusic_setVolume(sound, vol);
      sfMusic_play(sound);
      return (1);
    }
  return (ret);
}

int		menu_options(t_main *core)
{
  int		ret;
  sfEvent	event;
  sfMusic	*sound;

  ret = 1;
  if (!(sound = sfMusic_createFromFile("resources/sound/sounds/hauvent.ogg")))
    return (84);
  while (sfRenderWindow_isOpen(core->window) && ret == 1)
    {
      sfRenderWindow_clear(core->window, sfWhite);
      if (main_menu_sprites(core->window, core->fonts[0], 0) == 84)
	return (84);
      if (options_display(core) == 84)
	return (84);
      sfRenderWindow_display(core->window);
      ret = 0;
      while (ret == 0 && sfRenderWindow_isOpen(core->window))
	{
	  if ((ret = event_option_menu(core, &event)) > 1 ||
	      !sfRenderWindow_isOpen(core->window))
	    ret = handle_ret(core, sound, ret);
	}
    }
  sfMusic_destroy(sound);
  return (1);
}
