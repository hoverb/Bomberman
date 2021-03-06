/*
** element_collision.c for Bomberman in /Users/becketthover/Desktop/Bomberman/server
**
** Made by HOVER Beckett
** Login   <hover_b@etna-alternance.net>
**
** Started on  Fri Apr 22 07:09:40 2016 HOVER Beckett
** Last update Fri Apr 22 07:09:45 2016 HOVER Beckett
*/
#include "server.h"

int element_element_collision(t_element* current, t_element* element)
{
  t_collider c1;
  t_collider c2;

  c1.x = current->x;
  c1.y = current->y;
  c1.s = ELEMENT_SIZE;
  c2.x = element->x;
  c2.y = element->y;
  c2.s = ELEMENT_SIZE;

  return collision_handler(&c1, &c2);
}

t_player* get_element_collisions_with_players(t_element* element)
{
  int i;
  t_player* player;

  for (i = 0; i < 4; i++)
  {
    player = game->players[i];
    if (player && player_element_collision(player, element) > 0)
    {
      return game->players[i];
    }
  }

  return NULL;
}

t_element* get_element_collisions_with_list(t_element* elm, t_element* list)
{
  t_element* element;

  for (element = list; element != NULL; element = element->next)
  {
    if (element_element_collision(elm, element) > 0)
    {
      return element;
    }
  }

  return NULL;
}
