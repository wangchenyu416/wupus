#include <iostream>
#include <time.h>
#include <string>
using namespace std;
int wumpx()
{
	//randomx for wumpus
	srand(time(NULL));
	int x = rand() % 10;
	//prevents from wumpus at starting point  
	while (x == 5)
	{
		x = rand() % 10;
	}
	return x;
}
int wumpy()
{
	//randomy for wumpus
	srand(time(NULL));
	int y = rand() % 10;
	//prevents from wumpus at starting point	
	while (y == 5)
	{
		y = rand() % 10;
	}
	return y;
}

int main()
{
	int opt = 0;
	bool wumpuslive = 1, youlive = 1, wumpsmell = 0, arrow = 1;
	int x = 5, y = 5, wx = wumpx(), wy = wumpy();
	int wumparray[10][10];
	wumparray[wy][wx] = 1;
	//main game loop
	while (wumpuslive == 1 || youlive == 1)
	{
		opt = 0;
		cout << "You are standing at " << x << "," << y << ".\n";
		if (wumparray[y - 1][x] == 1 || wumparray[y + 1][x] == 1 || wumparray[y][x - 1] == 1 || wumparray[y][x + 1] == 1)
		{
			cout << "I smell a wumpus.\n";
			wumpsmell = 1;
		}
		else
		{
			wumpsmell = 0;
		}
		if (wumparray[y][x] == 1)
		{
			cout << "Hey, look a wumpus!\n*CHOMP*\nYou have been eaten by the wumpus.\nGAME OVER.\n";
			break;
		}
		cout << "You can:\n1. Move North.\n2. Move South\n3. Move East\n4. Move West\n5. Shoot Arrow[1]\n6. Exit\n";


		while (opt<1 || opt>4)
		{
			cin >> opt;
			switch (opt)
			{
			case 1:
				if (y<10)
				{
					y += 1;
				}
				break;
			case 2:
				if (y>0)
				{
					y -= 1;
				}
				break;
			case 3:
				if (x<10)
				{
					x += 1;
				}
				break;
			case 4:
				if (x>0)
				{
					x -= 1;
				}
				break;
			case 5:
				if (arrow == 1 && wumpsmell == 1)
				{
					cout << "*BANG*\nCongratulations, you shot the wumpus!\n*THE END*\n";
					arrow = 0;
				}
				else
				{
					cout << "*BANG*\nThere's not wumpus in sight and the arrow bounces off the wall and you get shot!\nNice one.\n*GAME OVER*\n";
					arrow = 0;
				}
				break;
			case 6:
				cout << "Come again!\n";
				break;
			default:
				cin >> opt;
				break;

			}
			if (arrow == 0)
			{
				break;
			}
		}

		if (arrow == 0)
		{
			break;
		}
	}
	system("pause");
	return 0;
}