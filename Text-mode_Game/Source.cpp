#include<stdio.h>
#include<conio.h>
#include<windows.h>

void draw_ship(int, int);
void gotoxy(int, int);
void erase_ship(int, int);

int main()

{
	char ch = ' ';
	int x = 0, y = 0;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x > 0) { erase_ship(x, y); draw_ship(--x, y); }
			if (ch == 'd' && x < 80) { erase_ship(x, y); draw_ship(++x, y); }
			if (ch == 'w' && y > 0) { erase_ship(x, y); draw_ship(x, --y); }
			if (ch == 's' && y < 25) { erase_ship(x, y); draw_ship(x, ++y); }
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

void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("       ");
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}