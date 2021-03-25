#include<stdio.h>
#include<Windows.h>
#include<conio.h>
int main()
{
	int hX = 7, hY = 7, len = 4, i = 0, map[900] = { 0 }; //头坐标，蛇长，循环变量，地图（-1:食物 0:空白 >0蛇身)
	char c = 'a', cl = 'a', deaw[1801] = { 0 };   //初始方向
	system("mode con:cols=60 lines=30");	//窗口大小
	srand((unsigned)malloc(1));
	for (map[rand() % 900] = -1; 1; Sleep(100))  //生成食物 延时
	{
		if (_kbhit() && (cl = _getch()))   //判断是否输入 且获得输入
			switch (cl)
			{
			case 'a':case 'A':if (c != 'd')c = 'a'; break;  //判断与原方向是否冲突
			case 'd':case 'D':if (c != 'a')c = 'd'; break;
			case 's':case 'S':if (c != 'w')c = 's'; break;
			case 'w':case 'W':if (c != 's')c = 'w'; break;
			}
		switch (c)
		{
		case 'a':hX -= hX > 0 ? 1 : -29; break;   //更新头坐标
		case 'd':hX += hX < 29 ? 1 : -29; break;
		case 's':hY += hY < 29 ? 1 : -29; break;
		case 'w':hY -= hY > 0 ? 1 : -29; break;
		}
		if (map[hY * 30 + hX] > 1)     //判断是否吃到自己
		{
			system("cls");
			exit(!_getch());
		}
		if (map[hY * 30 + hX] == -1) //判断是否吃到食物
		{
			len++;
			do
				i = rand() % 900;     //保证食物生成位置为平地
			while (map[i]);
			map[i] = -1;             //食物
		}
		else for (i = 0; i < 900; i++)      //全部蛇身值为-1
			if (map[i] > 0) map[i] -= 1;
		map[hY * 30 + hX] = len;		//蛇头赋值
		for (i = 0; i < 1800; i++)       //更新绘制
		{
			if (map[i / 2] == 0)deaw[i] = ' ';
			else if (map[i / 2] > 0)deaw[i] = (i % 2) ? ')' : '(';
			else deaw[i] = '0';
		}
		system("cls");
		printf(deaw);
	}
}