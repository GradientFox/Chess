#pragma once
#include "Figure.h"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Player
{
public:
	Player(int type);
	~Player();

private:
	vector<unique_ptr<Figure>> data;
};
