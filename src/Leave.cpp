#include "Leave.h"

Leave::Leave(sf::RenderWindow& window) : AWin(window)
{
  setType(MENU);
}

Leave::~Leave()
{
}

void	Leave::mainDraw()
{
  getWindow().clear();
  getWindow().close();
}
