#ifndef WIN_H
#define WIN_H

#include	"Button.h"
#include	"AWin.h"
#include	<list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	Win : public AWin
{
public:
  Win(sf::RenderWindow&);
  virtual ~Win();
  virtual void	mainDraw();
};

#endif // WIN_H
