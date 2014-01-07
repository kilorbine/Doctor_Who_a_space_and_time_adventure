#ifndef LEAVE_H
#define LEAVE_H


#include	"Button.h"
#include	"AWin.h"
#include	<list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	Leave : public AWin
{
public:
  Leave(sf::RenderWindow&);
  virtual ~Leave();
  virtual void	mainDraw();
};

#endif // LEAVE_H
