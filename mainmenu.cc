/*#include "mainmenu.h"
#include <vector>

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("")) {}

	for (int i = 0; i < 2; ++i) {
		mainMenu[i].setFont(font);
		mainMenu[i].setFillColor(sf::Color::White);
		mainMenu[i].setString("assets\\OpenSans.ttf");
		mainMenu[i].setPosition(400, (200 * i));
	}
}

void MainMenu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 2; ++i) {
		window.draw(mainMenu[i]);
	}
 }

void MainMenu::MoveUp() {
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[1].setFillColor(sf::Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 >= 2) {
		mainMenu[2].setFillColor(sf::Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == 2) {
			MainMenuSelected = 0;
		}
	}
	mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
}*/