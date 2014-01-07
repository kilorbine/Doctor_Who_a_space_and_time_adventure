#include <iostream>
#include <SFML/Graphics.hpp>
#include	<list>
#include	<unistd.h>
#include	<iostream>
#include	<string>
#include	"Game.h"
#include	"Leave.h"
#include	"Win.h"

bool	gestEvent(sf::Event event, sf::RenderWindow& window, AWin &currentWin)
{
  std::list<Button*>::iterator	it;
  std::list<Button*>::iterator	itEnd;
  std::list<Button*>	but;
  int	mX;
  int	mY;

    std::cout << "gest event" << std::endl;
  if(event.type == sf::Event::Closed)
    window.close();
  if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    window.close();
  if (event.type == sf::Event::MouseButtonReleased)
    {

      but = currentWin.getButton();
      it = but.begin();
      itEnd = but.end();
      mX = event.mouseButton.x;
      mY = event.mouseButton.y;
      std::cout << mX <<"," << mY << std::endl;
      while (it != itEnd)
        {
            if ((*it)->isIn(mX, mY) == true)
                (*it)->getWin()->mainDraw();
            it++;
        }
    }
  if (event.type == sf::Event::Resized)
    currentWin.updateButton();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
    currentWin.upDown();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
    currentWin.upUp();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
    currentWin.launchWindow();
  window.clear();
  currentWin.drawContent();
  window.display();
}

void	initMenu(sf::RenderWindow& win, AWin &current)
{
  Button	*game;
  Button	*leaveGame;

  int	x2 = win.getSize().x / 2;
  int	y2 = win.getSize().y / 2;
  game = new Button(x2 - 150, y2 - 50, x2 + 150, y2 + 50, "Launch Game");
  game->DrawContent(win);
  game->setWin(new Game(win));
  game->setTarget(true);
  current.addButton(game);
  leaveGame = new Button(x2 - 150, y2 + 100, x2 + 150, y2 + 200, "Leave");
  leaveGame->DrawContent(win);
  leaveGame->setWin(new Leave(win));
  current.addButton(leaveGame);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Doctor Who : A Space & Time Adventure!");
    sf::Event	event;
    Win		currentWin(window);

    currentWin.setType(MENU);
    initMenu(window, currentWin);
    window.display();
    while (window.isOpen())
    {
      window.pollEvent(event);
      gestEvent(event, window, currentWin);
      usleep(40000);
      window.clear();
      if(currentWin.getButton().size() == 0)
        initMenu(window, currentWin);
      currentWin.drawContent();
      window.display();
    }
}
