#include "Generator.h"

void Generator::initVariables()
{
	this->windowSize = { 800, 800 };
	this->setting.antialiasingLevel = 8;
	this->WindowTitle = "Maze Generator";


	// World setup var;	
	this->col = this->windowSize.width / dimension;
	this->row = this->windowSize.height / dimension;

}

void Generator::initwindow()
{
	this->window = new sf::RenderWindow(this->windowSize, this->WindowTitle,/* sf::Style::None*/sf::Style::Close | sf::Style::Titlebar , this->setting);
	this->window->setFramerateLimit(60);
}

void Generator::initCells()
{
	for (int j = 0; j < this->row; j++)
	{
		for (int i = 0; i < this->col; i++)
		{
			Cell cell;
			cell.initVariables(i, j);
			this->grid.push_back(cell);
		}
	}

	this->current = &grid[0];
}

int Generator::index(int i, int j)
{
	if (i < 0 || j < 0 || j > row - 1 || i > col - 1)
	{
		return -1;
	}

	return i + j * this->col;
}

Cell* Generator::checkNeighbour(Cell* cur)
{
	int i = cur->i;
	int j = cur->j;
	std::vector<Cell*> neighbour;

	if (index(i, j - 1) != -1)
	{
		Cell* top = &grid[index(i, j - 1)];
		if (!top->visited)
		{
			neighbour.push_back(top);
		}
	}
	if (index(i + 1, j) != -1)
	{
		Cell* right = &grid[index(i + 1, j )];
		if (!right->visited)
		{
			neighbour.push_back(right);
		}
	}
	if (index(i, j + 1) != -1)
	{
		Cell* down = &grid[index(i, j + 1)];
		if (!down->visited)
		{
			neighbour.push_back(down);
		}
	}
	if (index(i - 1, j) != -1)
	{
		Cell* left = &grid[index(i - 1, j)];
		if (!left->visited)
		{
			neighbour.push_back(left);
		}
	}
	
	if (neighbour.size() > 0)
	{
		int r = rand() % neighbour.size();
		//Cell* next = &neighbour[r];
		//std::cout << neighbour[r].i << " " << neighbour[r].j << "\n" << neighbour.size() << "\n";
		return neighbour[r];
	}
	else
	{
		return nullptr;
	}
}

void Generator::removeWall(Cell* cur, Cell* nex)
{
	int x = cur->i - nex->i;

	if (x == 1)
	{
		cur->walls[3] = false;
		nex->walls[1] = false;
	}
	else if (x == -1)
	{
		cur->walls[1] = false;
		nex->walls[3] = false;
	}

	int y = cur->j - nex->j;

	if (y == 1)
	{
		cur->walls[0] = false;
		nex->walls[2] = false;
	}
	else if (y == -1)
	{
		cur->walls[2] = false;
		nex->walls[0] = false;
	}
}

void Generator::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.KeyPressed == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}

		}
	}
}

Generator::Generator()
{
	this->initVariables();
	this->initwindow();
	this->initCells();
}

Generator::~Generator()
{
	delete this->window;
}

const bool Generator::isRunning() const
{
	return this->window->isOpen();
}

void Generator::update()
{
	this->pollEvents();	
	this->updateCell();
}


void Generator::updateCell()
{
	this->current->visited = true;
	//std::cout << current->visited << "\n";

	Cell* next = this->checkNeighbour(this->current);
	if (next != nullptr)
	{
		next->visited = true;
		// Step 1 Complete

		this->backtrak.push(this->current);
		//Step Complete

		this->removeWall(current, next);
		//Step 3 Complete
		
		this->current  = next;
		//Step 4 Complete
	}
	else if (!this->backtrak.empty())
	{
		this->current = this->backtrak.top();
		this->backtrak.pop();
	}
}

void Generator::render()
{

	this->window->clear(sf::Color(25, 25, 25));

	this->RenderCell();
	//std::cout << "Kya ho raha hai\n";
	this->highlight();

	this->window->display();

}

void Generator::RenderCell()
{
	
	for (int j = 0; j < this->grid.size(); j++)
	{
		//std::cout << "Loop chal raha hai RenderCell\n";
		this->grid[j].renderCell(this->window);
		//std::cout << j << " ka visited hai: " << grid[j].visited << "\n";

			int x = grid[j].i;
			int y = grid[j].j;

			sf::RectangleShape rect;
			rect.setSize(sf::Vector2f(dimension, dimension));
			rect.setPosition(x * dimension, y * dimension);
			rect.setFillColor(sf::Color(0, 0, 0, 100));


		if (grid[j].visited)
		{
			rect.setFillColor(sf::Color(255, 0, 255, 100));

		}
			window->draw(rect);

	}

	
}

void Generator::highlight()
{
	int x = this->current->i * dimension;
	int y = this->current->j * dimension;

	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(dimension, dimension));
	rect.setPosition(x , y );
	rect.setFillColor(sf::Color(147, 250, 165, 255));
	window->draw(rect);

}


