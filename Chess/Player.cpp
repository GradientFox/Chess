#include "Player.h"
using namespace std;

Player::Player(int type)
{
	if (type == 1)
	{
		this->data.push_back(make_unique<King>(1, 5));
	}
}