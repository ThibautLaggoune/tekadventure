/*
** unparse.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sun May 28 23:22:12 2017 Corentin LEROY
** Last update Sun May 28 23:22:13 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "headers.h"
#include "main.h"

void	unparse_files_editor(t_main *core, t_editor *resources)
{
  free_pictures(resources->backgrounds);
  free_pictures(resources->icones);
  free_pictures(resources->parallax);
  free_pictures(resources->characters);
  free_pictures(resources->creatures);
  free_musics(resources->musics);
  free_musics(resources->sounds);
  unparse_map(core, resources->save);
  free(resources);
}
