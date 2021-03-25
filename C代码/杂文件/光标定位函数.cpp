#include<stdio.h>
#include<Windows.h>

void HideCursor()//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)                //光标移动到（x，y）位置
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
int main()
{
	HideCursor();
	printf("123456");
	gotoxy(0, 2);
	printf("1");
}