#pragma once
#include "Cell.h"


class Generator
{

	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode windowSize;
	sf::ContextSettings setting;
	std::string WindowTitle;


	// World Constant
	int col, row;
	std::vector<Cell> grid;
	Cell* current;
	 
	// Initializers
	void initVariables();
	void initwindow();
	void initCells();

	// ALgortihtm
	int index(int i,int j);
	// Check for the neighbours;

	Cell* checkNeighbour(Cell* Cur);

	// Remove Walls
	void removeWall(Cell* cur, Cell* nex);

	// Bactracking ke liye stack;
	
	std::stack<Cell*> backtrak;
	
	//  Event Polling
	void pollEvents();

public:

	// Constructor Destructor
	Generator();
	~Generator();

	// Is Running
	const bool isRunning() const;

	// Updater
	void update();
	void updateCell();


	// Renderer
	void render();
	void RenderCell();
	void highlight();
};

