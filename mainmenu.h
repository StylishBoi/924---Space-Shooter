/*#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>

class MainMenu
{
private:
	int MainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[2];

public:
	MainMenu(float width, float height);

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed() { return MainMenuSelected; }
};

#endif*/
