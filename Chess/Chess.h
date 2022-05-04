#pragma once
#include "Desk.h"
#include "Figure.h"

using namespace std;

class Game
{
	friend class Figure;
	friend class Desk;
private:
	Desk* desk;
public:
	Game();
	bool possible_move(Figure* _piece, int _x, int _y);
	bool check_between(Figure*, int, int);
	void move(Figure* _piece, int _x, int _y);
	void run();
};