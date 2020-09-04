#include<stdio.h>
#include<windows.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void daw_ship()
{
  printf("<.0.>");
}
int main() 
{
	daw_ship();
	return 0;

}