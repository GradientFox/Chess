#pragma once
#include <utility>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Desk.h"

using namespace std;

class Figure
{
public:
	Figure() {};
	virtual void move(int _row, int _col);
	virtual pair<int, int> get_coord();
	virtual char get_name();
	virtual int get_team();
	virtual void update_possible() = 0;
	virtual vector<pair<int, int>> get_possible();
protected:
	pair <int, int> coord = {0, 0}; // {row, col}
	int team = -1; // 0/1  First team = 0 ; Second team = 1; None = -1
	char name = 'n'; // Name : {'K' - "King", 'Q' - "Queen", 'B' - "Bishop", 'H' - "Hourse", 'R' - "Rook", 'P' - "Pawn", 'n' - "none"}
	vector<pair<int, int>> possible = {}; // Possible coord to next move
};
class King : public Figure
{
public:
	King(int _row, int _col, int _team);
	void update_possible();
};
class Queen : public Figure
{
public:
	Queen(int _row, int _col, int _team);
	void update_possible();
};
class Bishop : public Figure
{
public:
	Bishop(int _row, int _col, int _team);
	void update_possible();
};
class Rook : public Figure
{
public:
	Rook(int _row, int _col, int _team);
	void update_possible();
};
class Hourse : public Figure
{
public:
	Hourse(int _row, int _col, int _team);
	void update_possible();
};
class Pawn : public Figure
{
public:
	Pawn(int _row, int _col, int _team);
	void update_possible();
};
class Empty : public Figure
{
public:
	Empty(int _row, int _col);
	void update_possible();
};

