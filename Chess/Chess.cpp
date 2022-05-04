#include "Chess.h"

Game::Game()
{
	this->desk = new Desk();
}
bool Game::possible_move(Figure* _piece, int _x, int _y)
{
	vector <pair<int, int>> temp_possible = _piece->get_possible();
	Figure*** board = this->desk->get_board();
	switch (_piece->get_name())
	{
	case 'P':
		if (_piece->get_coord().second == _y)
		{
			for (int ind = 0; ind < temp_possible.size(); ind++)
			{
				if (temp_possible[ind] == make_pair(_x, _y) &&
					board[_x][_y]->get_name() == 'n')
					return true;
			}
			return false;
		}
		for (int ind = 0; ind < temp_possible.size(); ind++)
		{
			if (temp_possible[ind] == make_pair(_x, _y) &&
				board[_x][_y]->get_name() != 'n' &&
				board[_x][_y]->get_name() != 'K' &&
				board[_x][_y]->get_team() != _piece->get_team())
				return true;
		}
		return false;
		break;
	case 'Q':
		for (int ind = 0; ind < temp_possible.size(); ind++)
		{
			if (temp_possible[ind] == make_pair(_x, _y) &&
				board[_x][_y]->get_name() != 'K' &&
				board[_x][_y]->get_team() != _piece->get_team())
				if (this->check_between(_piece, _x, _y))
					return true;
		}
		return false;
		break;
	case 'K':
		for (int ind = 0; ind < temp_possible.size(); ind++)
		{
			if (temp_possible[ind] == make_pair(_x, _y) &&
				board[_x][_y]->get_name() != 'K' &&
				board[_x][_y]->get_team() != _piece->get_team())
				return true;
		}
		if (!_piece->get_moved())
		{
			/*if (_x == _piece->get_coord().second && abs(_piece->get_coord().first - _y) == 2)
			{
				if (_piece->get_coord().first - _y < 0 && board[pow(7, _piece->get_team()) - 1][7])
				{

				}
			}*/
		}
		return false;
		break;
	case 'H':
		for (int ind = 0; ind < temp_possible.size(); ind++)
		{
			if (temp_possible[ind] == make_pair(_x, _y) &&
				board[_x][_y]->get_name() != 'K' &&
				board[_x][_y]->get_team() != _piece->get_team())
				return true;
		}
		return false;
		break;
	case 'B':
		for (int ind = 0; ind < temp_possible.size(); ind++)
		{
			if (temp_possible[ind] == make_pair(_x, _y) &&
				board[_x][_y]->get_name() != 'K' &&
				board[_x][_y]->get_team() != _piece->get_team())
				if (this->check_between(_piece, _x, _y))
					return true;
		}
		return false;
		break;
	case 'R':
		for (int ind = 0; ind < temp_possible.size(); ind++)
		{
			if (temp_possible[ind] == make_pair(_x, _y) &&
				board[_x][_y]->get_name() != 'K' &&
				board[_x][_y]->get_team() != _piece->get_team())
				if (this->check_between(_piece, _x, _y))
					return true;
		}
		return false;
		break;
	default:
		break;
	}
}
bool Game::check_between(Figure* _piece, int _x, int _y)
{
	int vectorX, vectorY;
	pair<int, int> coord = _piece->get_coord();
	Figure*** board = this->desk->get_board();
	switch (_piece->get_name())
	{
	case 'B':
		vectorX = abs(coord.first - _x) / (coord.first - _x);
		vectorY = abs(coord.second - _y) / (coord.second - _y);
		for (int ind = 1; ind < abs(coord.first - _x); ind++)
		{
			if (board[_x + vectorX * ind][_y + vectorY * ind]->get_name() != 'n')
				return false;
		}
		return true;
	case 'Q':
		vectorX = (coord.first - _x != 0) ? abs(coord.first - _x) / (coord.first - _x) : 0;
		vectorY = (coord.second - _y != 0) ? abs(coord.second - _y) / (coord.second - _y) : 0;
		for (int ind = 1; ind < abs(coord.first - _x); ind++)
		{
			if (board[_x + vectorX * ind][_y + vectorY * ind]->get_name() != 'n')
				return false;
		}
		for (int ind = 1; ind < abs(coord.second - _y); ind++)
		{
			if (board[_x + vectorX * ind][_y + vectorY * ind]->get_name() != 'n')
				return false;
		}
		return true;
	case 'R':
		vectorX = (coord.first - _x != 0) ? abs(coord.first - _x) / (coord.first - _x) : 0;
		vectorY = (coord.second - _y != 0) ? abs(coord.second - _y) / (coord.second - _y) : 0;
		for (int ind = 1; ind < abs(coord.first - _x) + abs(coord.second - _y); ind++)
		{
			if (board[_x + vectorX * ind][_y + vectorY * ind]->get_name() != 'n')
				return false;
		}
		return true;
	}
}
void Game::run()
{
	Figure*** board = this->desk->get_board();
	this->desk->print();
	bool team = 1;
	while (true)
	{
		int row_take, col_take;
		if (team)
			cout << "Red: Enter the position of figure to take(row, col):\n";
		else 
			cout << "Blue: Enter the position of figure to take(row, col):\n";
		cin >> row_take >> col_take;
		if (board[row_take][col_take]->get_name() == 'n')
		{
			system("cls");
			this->desk->print();
			cout << "You entered empty cell.\n";
			continue;
		}
		if (board[row_take][col_take]->get_team() != team)
		{
			system("cls");
			this->desk->print();
			cout << "You entered piece that isn't belong to your team.\n";
			continue;
		}
		int row_place, col_place;
		cout << "Enter the position of figure to place(row, col):\n";
		cin >> row_place >> col_place;
		if (!this->possible_move(board[row_take][col_take], row_place, col_place))
		{
			system("cls");
			this->desk->print();
			cout << "You entered unavailable position to place figure.\n";
			continue;
		}
		this->move(board[row_take][col_take], row_place, col_place);
		team = !team;
		system("cls");
		this->desk->print();
		cout << "Your move was (" << row_take << "," << col_take << ") -> (" << row_place << "," << col_place << ")\n\n";
	}
}
void Game::move(Figure* _piece, int _x, int _y)
{
	Figure*** board = this->desk->get_board();
	if (_piece->get_name() == 'P' && (_x == 0 || _x == 7))
		board[_x][_y] = new Queen(_x, _y, _piece->get_team());
	else
		board[_x][_y] = board[_piece->get_coord().first][_piece->get_coord().second];
	board[_piece->get_coord().first][_piece->get_coord().second] = new Empty(_piece->get_coord().first, _piece->get_coord().second);
	_piece->move(_x, _y);
}