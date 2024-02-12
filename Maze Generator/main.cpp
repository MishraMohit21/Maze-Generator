#include "Generator.h"



int main()
{

	std::srand(static_cast<unsigned>(time(NULL)));

	Generator Maze;


	while (Maze.isRunning())
	{


		Maze.update();


		Maze.render();
	}

	return 0;

}


