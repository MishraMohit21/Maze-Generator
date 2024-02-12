#include "Cell.h"



void Cell::initVariables(int i, int j)
{

	this->i = i;
	this->j = j;

	visited = false;

}

void Cell::renderCell(sf::RenderWindow* window)
{
	//std::cout << "Cell ke function chal raha hai\n";

	
	
	int x = this->i * dimension;
	int y = this->j * dimension;


	//std::cout << "x: " << x << " \ny: " << y << "\nVisited: " << this->visited << "\n";

	sf::VertexArray top_wall(sf::Lines, 2);
	sf::VertexArray right_wall(sf::Lines, 2);
	sf::VertexArray left_wall(sf::Lines, 2);
	sf::VertexArray down_wall(sf::Lines, 2);

	top_wall[0].position = sf::Vector2f(x, y);
	top_wall[1].position = sf::Vector2f(x + dimension, y);

	right_wall[0].position = sf::Vector2f(x + dimension, y);
	right_wall[1].position = sf::Vector2f(x + dimension, y + dimension);

	left_wall[0].position = sf::Vector2f(x, y);
	left_wall[1].position = sf::Vector2f(x, y + dimension);

	down_wall[0].position = sf::Vector2f(x, y + dimension);
	down_wall[1].position = sf::Vector2f(x + dimension, y + dimension);

	right_wall[0].color = sf::Color::White;
	right_wall[1].color = sf::Color::White;

	top_wall[0].color = sf::Color::White;
	top_wall[1].color = sf::Color::White;

	left_wall[0].color = sf::Color::White;
	left_wall[1].color = sf::Color::White;

	down_wall[0].color = sf::Color::White;
	down_wall[1].color = sf::Color::White;


	if (walls[0])
	{
		window->draw(top_wall);
	}
	if (walls[1])
	{
		window->draw(right_wall);
	}
	if (walls[2])
	{
		window->draw(down_wall);
	}
	if (walls[3])
	{
		window->draw(left_wall);
	}

}


