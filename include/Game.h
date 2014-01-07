#ifndef GAME_H
#define GAME_H

#include "AWin.h"

class	Game : public AWin
{
public:
Game(sf::RenderWindow&);
virtual ~Game();
 virtual void	mainDraw();
bool    gestEvent(sf::Event&);
};

#endif // GAME_H
