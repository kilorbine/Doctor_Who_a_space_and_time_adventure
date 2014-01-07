#include <time.h>
#include <unistd.h>
#include "main.h"
#include "Game.h"

Game::Game(sf::RenderWindow& window) : AWin(window)
{
    //ctor
}

Game::~Game()
{
    //dtor
}

bool	Game::gestEvent(sf::Event &event)
{
  std::list<Button*>::iterator	it;
  std::list<Button*>::iterator	itEnd;
  std::list<Button*>	but;
  int	mX;
  int	mY;

std::cout << "event type : " << event.type << std::endl;
  if(event.type == sf::Event::Closed)
  {
    _window.close();
    return (false);
  }
  if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
    return (false);
  if (event.type == sf::Event::MouseButtonReleased)
    {

      but = this->getButton();
      it = but.begin();
      itEnd = but.end();
      mX = event.mouseButton.x;
      mY = event.mouseButton.y;
      while (it != itEnd)
        {
            if ((*it)->isIn(mX, mY) == true)
                (*it)->getWin()->mainDraw();
            it++;
        }
    }
  if (event.type == sf::Event::Resized)
    this->updateButton();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
    this->upDown();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
    this->upUp();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
    this->launchWindow();
  _window.clear();
  this->drawContent();
  _window.display();
    return (true);
}

void	Game::mainDraw()
{
    sf::Event	event;
    bool    isIn;

    _window.clear();
    _window.display();
    isIn = true;
    while (isIn == true)
     {
        _window.pollEvent(event);
        isIn = gestEvent(event);
        usleep(40000);
     }

}
