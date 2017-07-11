/*
** function_pointers.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Apr 13 00:47:03 2017 Corentin LEROY
** Last update Fri May 26 01:34:59 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include "headers.h"
#include "main.h"
#include "macro.h"

void	initmenuptr(int (**ptr)())
{
  ptr[0] = &play_menu;
  ptr[1] = &edit_menu;
  ptr[2] = &menu_options;
  ptr[3] = &quitgame;
}

void	initoptptr(int (**ptr)())
{
  ptr[0] = &change_general_volume;
  ptr[1] = &change_music_volume;
  ptr[2] = &change_effects_volume;
  ptr[3] = &quitoptions;
}

void	initeditptr(int	(**ptr)())
{
  ptr[0] = &move_next_bck;
  ptr[1] = &move_previous_bck;
  ptr[2] = &move_next_bck;
  ptr[3] = &move_previous_bck;
  ptr[4] = &quit_edit;
  ptr[5] = &move_upper_bck;
  ptr[6] = &move_lower_bck;
}
