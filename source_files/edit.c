/*
** edit.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Apr 13 00:59:20 2017 Corentin LEROY
** Last update Sat May 27 18:03:58 2017 thibaut
*/

#include <SFML/Graphics.h>
#include "headers.h"
#include "macro.h"
#include "main.h"
#include "my.h"

void		edit_recup_chara_sprites(t_main *core, t_editor *resources)
{
  int		i;
  int		size;
  sfSprite	*sprite;
  sfVector2f	pos;
  sfVector2f	scale;

  size = 0;
  while (resources->icones[size])
    size += 1;
  i = 0;
  pos.y = SHEIGHT - 140;
  while (resources->icones[i])
    {
      sprite = resources->icones[i]->sprite;
      pos.x = (SWIDTH - (size * 100)) / (size + 1) * (i + 1) + i * 100;
      scale.x = 100 / resources->icones[i]->size.x;
      scale.y = 100 / resources->icones[i]->size.y;
      sfSprite_setScale(sprite, scale);
      sfSprite_setPosition(sprite, pos);
      sfRenderWindow_drawSprite(core->window, sprite, NULL);
      scale.x = 1 / scale.x;
      scale.y = 1 / scale.y;
      i += 1;
    }
}

void		edit_write_inLayout(t_main *core, t_editor *resources,
				    int tester[2])
{
  sfText	*swap;
  char		*text;
  sfVector2f	pos;

  if (tester[0] == 0 || tester[0] == 1)
    {
      text = "Changer de fond avec les fleches gauche et droite";
      if (!(swap = create_new_text(text, sfWhite, core->fonts[1], 25)))
	return ;
      pos.x = 30;
      pos.y = SHEIGHT - 90 - 50;
      sfText_setPosition(swap, pos);
      sfRenderWindow_drawText(core->window, swap, NULL);
      sfText_destroy(swap);
      text = "Valider avec la fleche du bas et annuler avec celle du haut";
      if (!(swap = create_new_text(text, sfWhite, core->fonts[1], 25)))
	return ;
      pos.y += 50;
      sfText_setPosition(swap, pos);
      sfRenderWindow_drawText(core->window, swap, NULL);
      sfText_destroy(swap);
    }
  else
    edit_recup_chara_sprites(core, resources);
}

void		edit_display_bg(t_main *core, t_editor *resources,
				int *tester)
{
  sfVector2f	pos;
  sfSprite	*tmp;

  tmp = resources->backgrounds[resources->cur_state.bg_state]->sprite;
  sfRenderWindow_drawSprite(core->window, tmp, NULL);
  if (tester[0] > 0)
    {
      pos.x = 0;
      pos.y = SHEIGHT - 180;
      pos.y -= resources->parallax[resources->cur_state.para_state]->size.y;
      tmp = resources->parallax[resources->cur_state.para_state]->sprite;
      sfSprite_setPosition(tmp, pos);
      sfRenderWindow_drawSprite(core->window, tmp, NULL);
    }
  pos.x = 0;
  pos.y = SHEIGHT - core->layout[0]->size.y;
  sfSprite_setPosition(core->layout[0]->sprite, pos);
  sfRenderWindow_drawSprite(core->window, core->layout[0]->sprite, NULL);
  display_save(core);
  edit_write_inLayout(core, resources, tester);
}

int		edit_menu(t_main *core)
{
  int		ret;
  int		tester[2];
  t_editor	*resources;
  sfEvent	event;

  ret = 1;
  my_memset(tester, 0, sizeof(int) * 2);
  if (loading_screen(core) || (resources = parse_files_editor()) == NULL)
    return (84);
  core->resource = resources;
  while (sfRenderWindow_isOpen(core->window) && ret == 1)
    {
      my_memset(&event, 0, sizeof(event));
      sfRenderWindow_clear(core->window, sfWhite);
      edit_display_bg(core, resources, tester);
      sfRenderWindow_display(core->window);
      ret = 0;
      while (ret == 0 && sfRenderWindow_isOpen(core->window))
	{
	  if ((ret = event_edit_menu(core, &event, resources, tester)) == 84)
	    return (84);
	}
    }
  unparse_files_editor(core, resources);
  return (1);
}
