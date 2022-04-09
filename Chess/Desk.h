#pragma once
#include <iostream>
#include <utility>
#include <memory>
#include <string>
#include "Figure.h"
#include <Windows.h>
#include <map>
#include "Chess.h"
using namespace std;

class Desk
{
	friend class Figure;
private:
	Figure *** board = new Figure **[8];
public:
	Desk();
	void print();
	Figure*** get_board();
};