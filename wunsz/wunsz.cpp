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
int x = 0, y = 1;
char chooz;

void direction(int x, int y) 
{
    system("cls");
    
    int szer = 40;
    int i = 0;
    for (; i < y; i++) { cout <<setw(szer)<<"<" << endl; }
    if (x == 39)cout << setw(39)<<head << '<';
    else if (x == 0)cout << setw(39) << head << '<';
    else
    cout << setw(x) << head<<setw(szer-x)<<'<';
    i +=1;
    cout << endl;
    for (; i < 20; i++) { cout << setw(szer) << "<" << endl; }
    cout.fill('^');
    cout << setw(39) << '^';
    cout.fill(' ');
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
                        if (y == -1)y = 19;
                        Sleep(330);
                        direction(x, y--);
                    };
                break;
                case KEY_DOWN:
                    while (!_kbhit())
                    {
                        if (y == 20)y = 0;
                        Sleep(330);
                        direction(x, y++);
                    };
                break;
                case KEY_LEFT:
                    while (!_kbhit())
                    {
                        if (x == 0)x = 39;
                        Sleep(330);
                        direction(x--, y);
                    };
                break;
                case KEY_RIGHT:
                    while (!_kbhit())
                    {
                        if (x == 39)x = 0;
                        Sleep(330);
                        direction(x++, y);
                    };
                break;
        
            }
        
        }



 
}

