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
				return true;
		}
		return false;
		break;
	default:
		break;
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