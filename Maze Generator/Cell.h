#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <ctime>
#include <stack>


constexpr int dimension = 20;


class Cell //: public sf::RectangleShape
{
public:

	int i, j;

	bool walls[4] = { true, true, true , true };


	bool visited;
	void initVariables(int i, int j);

	void renderCell(sf::RenderWindow* window);
	//void renderRect(sf::RenderWindow* window);

};

