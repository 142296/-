#include<stdio.h>
#include<Windows.h>
#include<conio.h>
int main()
{
	int hX = 7, hY = 7, len = 4, i = 0, map[900] = { 0 }; //ͷ���꣬�߳���ѭ����������ͼ��-1:ʳ�� 0:�հ� >0����)
	char c = 'a', cl = 'a', deaw[1801] = { 0 };   //��ʼ����
	system("mode con:cols=60 lines=30");	//���ڴ�С
	srand((unsigned)malloc(1));
	for (map[rand() % 900] = -1; 1; Sleep(100))  //����ʳ�� ��ʱ
	{
		if (_kbhit() && (cl = _getch()))   //�ж��Ƿ����� �һ������
			switch (cl)
			{
			case 'a':case 'A':if (c != 'd')c = 'a'; break;  //�ж���ԭ�����Ƿ��ͻ
			case 'd':case 'D':if (c != 'a')c = 'd'; break;
			case 's':case 'S':if (c != 'w')c = 's'; break;
			case 'w':case 'W':if (c != 's')c = 'w'; break;
			}
		switch (c)
		{
		case 'a':hX -= hX > 0 ? 1 : -29; break;   //����ͷ����
		case 'd':hX += hX < 29 ? 1 : -29; break;
		case 's':hY += hY < 29 ? 1 : -29; break;
		case 'w':hY -= hY > 0 ? 1 : -29; break;
		}
		if (map[hY * 30 + hX] > 1)     //�ж��Ƿ�Ե��Լ�
		{
			system("cls");
			exit(!_getch());
		}
		if (map[hY * 30 + hX] == -1) //�ж��Ƿ�Ե�ʳ��
		{
			len++;
			do
				i = rand() % 900;     //��֤ʳ������λ��Ϊƽ��
			while (map[i]);
			map[i] = -1;             //ʳ��
		}
		else for (i = 0; i < 900; i++)      //ȫ������ֵΪ-1
			if (map[i] > 0) map[i] -= 1;
		map[hY * 30 + hX] = len;		//��ͷ��ֵ
		for (i = 0; i < 1800; i++)       //���»���
		{
			if (map[i / 2] == 0)deaw[i] = ' ';
			else if (map[i / 2] > 0)deaw[i] = (i % 2) ? ')' : '(';
			else deaw[i] = '0';
		}
		system("cls");
		printf(deaw);
	}
}