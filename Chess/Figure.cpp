#include "Figure.h"

///////////////////////////////////////////////////
// defining Figure methods
///////////////////////////////////////////////////
void Figure::move(int _x, int _y)
{
	if (this->possible_move(_x, _y))
		this->coord = { _x, _y };
	else
		throw 1;
}
bool Figure::possible_move(int _x, int _y) { return true; }
pair<int, int> Figure::get_coord() { return this->coord; }
///////////////////////////////////////////////////
// defining King methods
///////////////////////////////////////////////////
King::King(int _x, int _y) { this->coord = { _x, _y }; }
bool King::possible_move(int _x, int _y)
{
	if ((abs(_x - this->coord.first) > 1) ||
		(abs(_y - this->coord.second) > 1) ||
		(_x == this->coord.first && _y == this->coord.second) ||
		(_x > 8) ||
		(_y > 8))
	{
		return false;
	}
	return true;
}