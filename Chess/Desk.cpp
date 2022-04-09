#include "Desk.h"

template<int txt = 7, int bg = 0>
ostream& color(ostream& text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}

Desk::Desk()
{
	for (int row = 0; row < 8; row++)
	{
		this->board[row] = new Figure *[8];
	}
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			this->board[row][col] = new Empty(row, col);
		}
	}
	this->board[0][0] = new Rook(0, 0, 0);
	this->board[0][1] = new Hourse(0, 1, 0);
	this->board[0][2] = new Bishop(0, 2, 0);
	this->board[0][3] = new Queen(0, 3, 0);
	this->board[0][4] = new King(0, 4, 0);
	this->board[0][5] = new Bishop(0, 5, 0);
	this->board[0][6] = new Hourse(0, 6, 0);
	this->board[0][7] = new Rook(0, 7, 0);
	for (int i = 0; i < 8; i++)
	{
		this->board[1][i] = new Pawn(1, i, 0);
		this->board[6][i] = new Pawn(6, i, 1);
	}
	this->board[7][0] = new Rook(7, 0, 1);
	this->board[7][1] = new Hourse(7, 1, 1);
	this->board[7][2] = new Bishop(7, 2, 1);
	this->board[7][3] = new Queen(7, 3, 1);
	this->board[7][4] = new King(7, 4, 1);
	this->board[7][5] = new Bishop(7, 5, 1);
	this->board[7][6] = new Hourse(7, 6, 1);
	this->board[7][7] = new Rook(7, 7, 1);
}
Figure*** Desk::get_board()
{
	return this->board;
}
void Desk::print()
{
	cout << "\t  01234567\n";
	for (int row = 0; row < 8; row++)
	{
		cout << "\t" << row << " ";
		for (int col = 0; col < 8; col++)
		{
			if (this->board[row][col]->get_name() == 'n')
			{
				if ((col + 1 + row % 2) % 2)
					cout << color<0, 7> << ".";
				else
					cout << color<7, 0> << ".";
			}
			else
				if ((col + 1 + row % 2) % 2)
				{
					if (this->board[row][col]->get_team() == 0)
						cout << color<1, 7> << this->board[row][col]->get_name();
					else
						cout << color<4, 7> << this->board[row][col]->get_name();
				}
				else
				{
					if (this->board[row][col]->get_team() == 0)
						cout << color<1, 0> << this->board[row][col]->get_name();
					else
						cout << color<4, 0> << this->board[row][col]->get_name();
				}
		}
		cout << color<7, 0> << endl;
	}
	cout << endl;
}

