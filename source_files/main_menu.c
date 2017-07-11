/*
** main_menu.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 15:35:59 2017 Corentin LEROY
** Last update Fri May  5 00:42:20 2017 Corentin LEROY
*/

#include <SFML/Window.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include "headers.h"
#include "macro.h"
#include "main.h"
#include "my.h"

static int	display_menu(sfRenderWindow *window, sfFont *menu_font)
{
  sfVector2f	pos;
  sfText	*play;
  sfText	*editor;
  sfText	*option;
  sfText	*quit;

  if (!(play = create_new_text("JOUER", sfBlack, menu_font, 75)) ||
      !(editor = create_new_text("EDITER", sfBlack, menu_font, 75))||
      !(option = create_new_text("OPTIONS", sfBlack, menu_font, 75)) ||
      !(quit = create_new_text("QUITTER", sfBlack, menu_font, 75)))
    return (84);
  pos = getv2f(50, SHEIGHT / 2 - 160);
  sfText_setPosition(play, pos);
  pos = getv2f(50, SHEIGHT / 2 - 60);
  sfText_setPosition(editor, pos);
  pos = getv2f(50, SHEIGHT / 2 + 40);
  sfText_setPosition(option, pos);
  pos = getv2f(50, SHEIGHT / 2 + 140);
  sfText_setPosition(quit, pos);
  sfRenderWindow_drawText(window, play, NULL);
  sfRenderWindow_drawText(window, editor, NULL);
  sfRenderWindow_drawText(window, option, NULL);
  sfRenderWindow_drawText(window, quit, NULL);
  text_destroy(play, editor, option, quit);
  return (0);
}

int		main_menu_sprites(sfRenderWindow *window, sfFont *menuf,
				  int mode)
{
  sfVector2f	scale;
  t_picture	*back;
  sfText	*title;
  int		ret;

  sfRenderWindow_clear(window, sfWhite);
  scale = getv2f(0.5, 0.5);
  if (!(title = create_new_text("BANAL ADVENTURE", sfBlack, menuf, 160)) ||
      !(back = set_texture(scale, "resources", "background.png")))
    return (84);
  if (mode)
    if (display_menu(window, menuf) == 84)
      return (84);
  sfText_setPosition(title, getv2f(SWIDTH / 3, SHEIGHT / 4 * 3));
  sfRenderWindow_drawSprite(window, back->sprite, NULL);
  sfRenderWindow_drawText(window, title, NULL);
  ret = print_rectangle(getv2f(SWIDTH / 3, SHEIGHT - 15), getv2i(830, 10),
			sfBlack, window);
  sfText_destroy(title);
  return (ret);
}

int		main_menu(t_main *core)
{
  sfEvent	event;
  int		ret;

  ret = 1;
  if (change_alloc_music(core, "resources/sound/musics/menu-music.ogg") == 84)
    return (84);
  while (ret == 1 && sfRenderWindow_isOpen(core->window))
    {
      my_memset(&event, 0, sizeof(sfEvent));
      if (main_menu_sprites(core->window, core->fonts[0], 1) == 84)
	return (84);
      sfRenderWindow_display(core->window);
      ret = 0;
      while (ret == 0 && sfRenderWindow_isOpen(core->window))
	{
	  ret = event_main_menu(core, &event);
	  if (ret == 84)
	    return (84);
	}
    }
  return (0);
}
