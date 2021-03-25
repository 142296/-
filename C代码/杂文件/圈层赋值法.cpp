#include<iostream>          //圈层赋值法 
#include<Windows.h>
#include<time.h>
using namespace std;
const int N = 7;
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void HideCursor()//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void show(int a[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << a[i][j];
		cout << endl;
	}
}
int main()
{
	HideCursor();
	int k, i, j, a[N][N] = { 0 }, begin;
	getchar();
	gotoxy(0, 0);
	for (k = 1; k <= N; k++)
	{
		for (j = k - 1; j <= N - k; j++)
		{
			begin = time(0);
			a[N - j - 1][N - k] = a[j][k - 1] = a[k - 1][N - j - 1] = a[N - k][j] = k;         //圈层赋值法   以数字的圈层分别赋值
			while (begin == time(0));
			gotoxy(0, 0);
			show(a);
		}

	}

}