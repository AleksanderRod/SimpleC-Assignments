// Author: Aleksander Rodriguez
// Course: COSC 2436
// Program Set 3
// References: none

#include <iostream>

using namespace std;

void printSquares(int , int, int);

int main()
{

	char yes = 'n';
	do
	{
		int size;
		int rows = 1;
		int cols = 1;

		cout << "Enter size [5-20]: ";
		cin >> size;
		while (size < 5 || size > 20)
		{
			cout << endl << "Reenter size [5-20]: ";
			cin >> size;
		}

		printSquares(size, rows, cols);

		//Check case
		cout << endl << "Run Again (Y/N): ";
		cin >> yes;
		cout << endl;

	} while (yes == 'Y' || yes == 'y');
}


void printSquares(int siz, int x, int y)
{
	// this if checks where X's need
	// to be for rows
	if (x == 1 || x == siz|| y == 1 || y == siz        
		||( x == 3 && y > siz -siz +2 && y < siz -1)   
		|| x == siz -2 && y > siz - siz + 2 && y < siz - 1
		|| x == siz - 4 && y > siz - siz + 4 && y < siz - 3
		||(x == siz - siz + 5 && y > siz - siz + 4 && y < siz - 3)
		||(x == siz - siz + 7 && y > siz - siz + 6 && y < siz - 5)
		|| x == siz - 6 && y > siz - siz + 6 && y < siz - 5
		|| (x == siz - siz + 9 && y > siz - siz + 8 && y < siz - 7)
		|| x == siz - 8 && y > siz - siz + 8 && y < siz - 7)
	{
		cout << "X";
	}
	// if check for X's on columns
	else if ((y == 3 && x > siz - siz + 2 && x < siz - 1)
			|| y == siz - 2 && x > siz - siz + 2 && x < siz - 1
			|| y == siz - 4 && x > siz - siz + 4 && x < siz - 3
			|| (y == siz - siz + 5 && x > siz - siz + 4 && x < siz - 3)
			|| (y == siz - siz + 7 && x > siz - siz + 6 && x < siz - 5)
			|| y == siz - 6 && x > siz - siz + 6 && x < siz - 5
			|| (y == siz - siz + 9 && x > siz - siz + 8 && x < siz - 7)
			|| y == siz - 8 && x > siz - siz + 8 && x < siz - 7)
	{
		cout << "X";
	}
	else {
		cout << " ";
	}
	
	
	y++; // iterate my make shift loop
	
	// this will allow me to run recursion as a 2D for loop 
	if (y == siz + 1)
	{
		x++;
		y = 1;
		cout << endl;
	}

	// recursion will stop when x = siz +1
	if (x != siz +1)
	{

		return printSquares(siz, x, y);
	}
}


