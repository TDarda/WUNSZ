#include <iomanip>
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<deque>

#define KEY_UP 72       //strzałka w górę
#define KEY_DOWN 80     //strzałka w dół
#define KEY_LEFT 75     //strzałka w lewo
#define KEY_RIGHT 77    //strzałka w prawo
#define HEIGHT 15    //wysokość poziomu
#define WIDTH 30        //szerokość poziomu

using namespace std;

char Level[HEIGHT][WIDTH];

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
    snake.push_front(pair<int, int>(up_down, left_right));
    snake.pop_back();

}


void game()  //właściwa gra
{
    bool game_on = true;
    char choose, last_choose = KEY_RIGHT;
    int snakeY = snake.front().first;
    int snakeX = snake.front().second;

    while (game_on)
    {
        choose = _getch();
        switch (choose)
        {
        case KEY_UP:
            while (!_kbhit())
            {
                Sleep(330);  delete_a_level(); snake_manipulation(--snakeY, snakeX); build_a_level(); create_a_snake(); show_a_level();
            }
            break;
        case KEY_DOWN:
            while (!_kbhit())
            {
                Sleep(330);  delete_a_level(); snake_manipulation(++snakeY, snakeX); build_a_level(); create_a_snake(); show_a_level();
            }
            break;
        case KEY_RIGHT:
            while (!_kbhit())
            {
                Sleep(330);  delete_a_level(); snake_manipulation(snakeY, ++snakeX); build_a_level(); create_a_snake();  show_a_level();
            }
            break;
        case KEY_LEFT:
            while (!_kbhit())
            {
                Sleep(330);  delete_a_level(); snake_manipulation(snakeY, --snakeX); build_a_level(); create_a_snake(); show_a_level();
            }
            break;
        }

    }
}

int main()
{
    game();
}