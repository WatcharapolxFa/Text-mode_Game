#include<stdio.h>
#include<conio.h>
#include<windows.h>

void draw_ship(int, int);
void gotoxy(int, int);

int main()

{
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { draw_ship(--x, y); }
			if (ch == 'd') { draw_ship(++x, y); }
			if (ch == 'w') { draw_ship(x, ++y); }
			if (ch == 's') { draw_ship(x, --y); }
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}

void draw_ship(int x,int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}