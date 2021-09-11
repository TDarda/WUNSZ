#include <iomanip>
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<deque>
#include<ctime>
#include<cstdlib>

#define KEY_UP 72       //strzałka w górę
#define KEY_DOWN 80     //strzałka w dół
#define KEY_LEFT 75     //strzałka w lewo
#define KEY_RIGHT 77    //strzałka w prawo
#define HEIGHT 15    //wysokość poziomu
#define WIDTH 30        //szerokość poziomu

using namespace std;

char Level[HEIGHT][WIDTH];

int appleX, appleY;

deque<pair<int, int>>snake = {
		{7,4}, {7,5}, {7,6},{7,7}
};


void build_a_level() //budowa poziomu
{
	for (int i = 0; i < HEIGHT; i++)
	{

		for (int j = 0; j < WIDTH; j++)
		{
			Level[0][j] = '#';
			Level[i][0] = '#';
			Level[HEIGHT - 1][j] = '#';
			Level[i][WIDTH - 1] = '#';
		}
	}
}

void delete_a_level() //czyszczecnie poziomu
{
	for (int i = 0; i < HEIGHT; i++)
	{

		for (int j = 0; j < WIDTH; j++)
		{
			Level[i][j] = ' ';

		}
	}
}

void create_a_snake()  //stworzenie węża na planszy
{
	for (deque<pair<int, int>>::iterator iter = snake.begin(); iter != snake.end(); iter++)
	{
		Level[iter->first][iter->second] = 'o';

	}


}

void show_a_level()   //wyświetlenie poziomu
{
	system("cls");
	for (int i = 0; i < HEIGHT; i++)
	{
		cout << endl;

		for (int j = 0; j < WIDTH; j++)
		{
			cout << Level[i][j];

		}
	}
}

void snake_manipulation(int& up_down, int& left_right)  //dodanie nowej głowy i usunięcię ogona
{
	if (left_right == WIDTH - 1)left_right = 1;
	if (left_right == 0)left_right = WIDTH - 2;
	if (up_down == 0)up_down = HEIGHT - 2;
	if (up_down == HEIGHT - 1)up_down = 1;
	snake.push_front(pair<int, int>(up_down, left_right));
	snake.pop_back();

}

void apple_generator(int& appleX, int& appleY)  //generuje jabłko
{
	appleX = rand() % (WIDTH - 2) + 1;
	appleY = rand() % (HEIGHT - 2) + 1;


}

void apple_position(const int& appleX, const int& appleY)  //ustawia na planszy jabłko
{
	Level[appleY][appleX] = '@';
}

void game_sequence(char direct) // sekwencja gry, funkcja, która ma na celu zapobiec redundancji
{
	int snakeY = snake.front().first;
	int snakeX = snake.front().second;

	delete_a_level();

	if (direct == 'u')snake_manipulation(--snakeY, snakeX);
	if (direct == 'd')snake_manipulation(++snakeY, snakeX);
	if (direct == 'r')snake_manipulation(snakeY, ++snakeX);
	if (direct == 'l')snake_manipulation(snakeY, --snakeX);

	build_a_level();
	apple_position(appleX, appleY);
	create_a_snake();
	show_a_level();

}

char choosing(char& choose, char& last_choose)  // ta funkcja zapobiega zawracaniu na sobie węża
{
	choose = _getch();
	switch (choose)
	{
	case KEY_UP:
		if (last_choose == KEY_DOWN) { choose = KEY_DOWN;  }
		else 
		{
			last_choose = KEY_UP;  return choose;
		}
		break;
	case KEY_DOWN:
		if (last_choose == KEY_UP) { choose = KEY_UP; }
		else 
		{
			last_choose = KEY_DOWN; return choose;
		}
		break;
	case KEY_RIGHT:
		if (last_choose == KEY_LEFT) { choose = KEY_LEFT; }
		else 
		{
			last_choose = KEY_RIGHT; return choose;
		}
		break;
	case KEY_LEFT:
		if (last_choose == KEY_RIGHT) { choose = KEY_RIGHT;  }
		else 
		{
			last_choose = KEY_LEFT; return choose;
		}
		break;
	}
	
	return choose;

}

void test(char a, char b)
{
	cout << endl << a << "====" << b;
}

void game()  //właściwa gra
{
	bool game_on = true;
	char choose, last_choose;
	apple_generator(appleX, appleY);

	while (game_on)
	{



		switch (choosing(choose, last_choose))
		{
		case KEY_UP:

			while (!_kbhit())
			{
				Sleep(330);   game_sequence('u'); test(choose, last_choose);
			}
			break;

		case KEY_DOWN:

			while (!_kbhit())
			{
				Sleep(330);    game_sequence('d'); test(choose, last_choose);
			}
			break;




		case KEY_RIGHT:

			while (!_kbhit())
			{
				Sleep(330);     game_sequence('r'); test(choose, last_choose);
			}
			break;

		case KEY_LEFT:

			while (!_kbhit())
			{
				Sleep(330); game_sequence('l'); test(choose, last_choose);
			}

			break;

		}

		
	}
}

int main()
{
	srand(time(NULL));
	game();
}