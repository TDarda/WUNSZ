#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75 
#define KEY_RIGHT 77

using namespace std;

char head = '@';
int x = 1, y = 1;
char chooz;

void direction(int x, int y) 
{
    system("cls");
    
    
    for (int i = 0; i < y; i++) { cout << endl; }
    cout << setw(x) << head<<y;
}

int main()
{     
     char wybor;
         
   
        while (true)
        {
            wybor = _getch();
            switch(wybor)
            {
                case KEY_UP:
                    while (!_kbhit())
                    {
                        Sleep(330);
                        direction(x, y--);
                    };
                break;
                case KEY_DOWN:
                    while (!_kbhit())
                    {
                        Sleep(330);
                        direction(x, y++);
                    };
                break;
                case KEY_LEFT:
                    while (!_kbhit())
                    {
                        Sleep(330);
                        direction(x--, y);
                    };
                break;
                case KEY_RIGHT:
                    while (!_kbhit())
                    {
                        Sleep(330);
                        direction(x++, y);
                    };
                break;
        
            }
        
        }



 
}

