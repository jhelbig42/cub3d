#include "cube.h"

int	on_keypress(int key, t_game *game)
{
  //destroy on ESC
  if (key == ESC)
	  on_destroy(game);
  return (0);
}