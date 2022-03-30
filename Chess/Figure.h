#pragma once
#include <utility>
#include <iostream>

using namespace std;

class Figure
{
public:
	virtual void move(int _x, int _y);
	virtual pair<int, int> get_coord();
	virtual bool possible_move(int _x, int _y) = 0;
protected:
	pair <int, int> coord = {0, 0};
};

class King : Figure
{
public:
	King(int _x, int _y);
	bool possible_move(int _x, int _y);
};