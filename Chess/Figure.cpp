#include "Figure.h"

///////////////////////////////////////////////////
// defining Figure methods
///////////////////////////////////////////////////
void Figure::move(int _row, int _col)
{
	this->coord = { _row, _col };
	this->set_moved();
	this->update_possible();
}
pair<int, int> Figure::get_coord() { return this->coord; }
char Figure::get_name() { return this->name; }
int Figure::get_team() { return this->team; }
void Figure::update_possible() {}
vector<pair<int, int>> Figure::get_possible() { return this->possible; }
void Figure::set_moved() { this->moved = true; }
bool Figure::get_moved() { return this->moved; }
///////////////////////////////////////////////////
// defining King methods
///////////////////////////////////////////////////
King::King(int _row, int _col, int _team)
{
	this->coord = { _row, _col };
	this->team = _team;
	this->name = 'K';
	this->update_possible();
}
void King::update_possible()
{
	if (this->coord.first - 1 >= 0)
	{
		this->possible.push_back({ this->coord.first - 1, this->coord.second });
		if (this->coord.second - 1 >= 0)
		{
			this->possible.push_back({ this->coord.first - 1, this->coord.second - 1 });
			this->possible.push_back({ this->coord.first, this->coord.second - 1 });
		}
		if (this->coord.second + 1 < 8)
		{
			this->possible.push_back({ this->coord.first - 1, this->coord.second + 1 });
			this->possible.push_back({ this->coord.first, this->coord.second + 1 });
		}
	}
	if (this->coord.first + 1 < 8)
	{
		this->possible.push_back({ this->coord.first + 1, this->coord.second });
		if (this->coord.second - 1 >= 0)
			this->possible.push_back({ this->coord.first + 1, this->coord.second - 1 });
		if (this->coord.second + 1 < 8)
			this->possible.push_back({ this->coord.first + 1, this->coord.second + 1 });
	}
}
///////////////////////////////////////////////////
// defining Queen methods
///////////////////////////////////////////////////
Queen::Queen(int _row, int _col, int _team)
{ 
	this->coord = { _row, _col };
	this->team = _team;
	this->name = 'Q';
	this->update_possible();
}
void Queen::update_possible()
{
	this->possible.clear();
	for (int ind = 1; ind < 8; ind++)
	{
		if (this->coord.first - ind >= 0)
		{
			this->possible.push_back({ this->coord.first - ind, this->coord.second });
			if (this->coord.second - ind >= 0)
				this->possible.push_back({ this->coord.first - ind, this->coord.second - ind });
		}
		if (this->coord.first + ind < 8)
		{
			this->possible.push_back({ this->coord.first + ind, this->coord.second });
			if (this->coord.second + ind < 8)
				this->possible.push_back({ this->coord.first + ind, this->coord.second + ind });
		}
		if (this->coord.second - ind >= 0)
		{
			this->possible.push_back({ this->coord.first, this->coord.second - ind });
			if (this->coord.first + ind < 8)
				this->possible.push_back({ this->coord.first + ind, this->coord.second - ind });
		}
		if (this->coord.second + ind < 8)
		{
			this->possible.push_back({ this->coord.first, this->coord.second + ind });
			if (this->coord.first - ind >= 0)
				this->possible.push_back({ this->coord.first - ind, this->coord.second + ind });
		}
	}
}
///////////////////////////////////////////////////
// defining Bishop methods
///////////////////////////////////////////////////
Bishop::Bishop(int _row, int _col, int _team)
{
	this->coord = { _row, _col };
	this->team = _team;
	this->name = 'B';
	this->update_possible();
}
void Bishop::update_possible()
{
	this->possible.clear();
	for (int ind = 1; ind < 8; ind++)
	{
		if (this->coord.first - ind >= 0 && this->coord.second - ind >= 0)
			this->possible.push_back({ this->coord.first - ind, this->coord.second - ind });
		if (this->coord.first + ind < 8 && this->coord.second + ind < 8)
			this->possible.push_back({ this->coord.first + ind, this->coord.second + ind });
		if (this->coord.second - ind >= 0 && this->coord.first + ind < 8)
			this->possible.push_back({ this->coord.first + ind, this->coord.second - ind });
		if (this->coord.second + ind < 8 && this->coord.first - ind >= 0)
			this->possible.push_back({ this->coord.first - ind, this->coord.second + ind });
	}
}
///////////////////////////////////////////////////
// defining Rook methods
///////////////////////////////////////////////////
Rook::Rook(int _row, int _col, int _team)
{
	this->coord = { _row, _col };
	this->team = _team;
	this->name = 'R';
	this->update_possible();
}
void Rook::update_possible()
{
	this->possible.clear();
	for (int ind = 1; ind < 8; ind++)
	{
		if (this->coord.first - ind >= 0)
			this->possible.push_back({ this->coord.first - ind, this->coord.second });
		if (this->coord.first + ind < 8)
			this->possible.push_back({ this->coord.first + ind, this->coord.second });
		if (this->coord.second - ind >= 0)
			this->possible.push_back({ this->coord.first, this->coord.second - ind });
		if (this->coord.second + ind < 8)
			this->possible.push_back({ this->coord.first, this->coord.second + ind });
	}
}
///////////////////////////////////////////////////
// defining Hourse methods
///////////////////////////////////////////////////
Hourse::Hourse(int _row, int _col, int _team)
{
	this->coord = { _row, _col };
	this->team = _team;
	this->name = 'H';
	this->update_possible();
}
void Hourse::update_possible()
{
	this->possible.clear();
	if (this->coord.first - 2 >= 0)
	{
		if (this->coord.second + 1 < 8)
			this->possible.push_back({ this->coord.first - 2, this->coord.second + 1 });
		if (this->coord.second - 1 >= 0)
			this->possible.push_back({ this->coord.first - 2, this->coord.second - 1 });
	}
	if (this->coord.first + 2 < 8)
	{
		if (this->coord.second + 1 < 8)
			this->possible.push_back({ this->coord.first + 2, this->coord.second + 1 });
		if (this->coord.second - 1 >= 0)
			this->possible.push_back({ this->coord.first + 2, this->coord.second - 1 });
	}
	if (this->coord.second - 2 >= 0)
	{
		if (this->coord.first + 1 < 8)
			this->possible.push_back({ this->coord.first + 1, this->coord.second - 2 });
		if (this->coord.first - 1 >= 0)
			this->possible.push_back({ this->coord.first - 1, this->coord.second - 2 });
	}
	if (this->coord.second + 2 < 8)
	{
		if (this->coord.first + 1 < 8)
			this->possible.push_back({ this->coord.first + 1, this->coord.second + 2 });
		if (this->coord.first - 1 >= 0)
			this->possible.push_back({ this->coord.first - 1, this->coord.second + 2 });
	}
}
///////////////////////////////////////////////////
// defining Pawn methods
///////////////////////////////////////////////////
Pawn::Pawn(int _row, int _col, int _team)
{ 
	this->coord = { _row, _col };
	this->team = _team;
	this->name = 'P';
	this->update_possible();
}
void Pawn::update_possible()
{
	this->possible.clear();
	if ((this->coord.first + 2 * pow(-1, this->team) < 8) && (this->coord.first + 2 * pow(-1, this->team) >= 0) && 
		!this->moved)
		this->possible.push_back({ this->coord.first + 2 * pow(-1, this->team) , this->coord.second });
	if ((this->coord.first + pow(-1, this->team) < 8) && (this->coord.first + pow(-1, this->team) >= 0))
	{
		this->possible.push_back({ this->coord.first + pow(-1, this->team), this->coord.second });
		if (this->coord.second + 1 < 8)
			this->possible.push_back({ this->coord.first + pow(-1, this->team), this->coord.second + 1 });
		if (this->coord.second - 1 >= 0)
			this->possible.push_back({ this->coord.first + pow(-1, this->team), this->coord.second - 1 });
	}
}

///////////////////////////////////////////////////
// defining Empty methods
///////////////////////////////////////////////////
Empty::Empty(int _row, int _col) { this->coord = { _row, _col }; this->name = 'n'; }
void Empty::update_possible() {}
