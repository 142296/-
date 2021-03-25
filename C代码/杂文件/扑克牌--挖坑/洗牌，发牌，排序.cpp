#include<stdio.h>
#include<stdlib.h>

void swap(char*, char*);             //ϴ�Ʒֺ���
void show(char poke[][2]);			//����
void wash(char poke[][2]);			//ϴ��
void sort(char poke[][2]);			//ð������

void swap(char* p, char* q)
{
	char t = *p;
	*p = *q;
	*q = t;
}
void show(char poke[52][2])
{
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0 && i % 16 == 0)
			{
				switch (i / 16)
				{
				case 0:printf("����:"); break;
				case 1:printf("\n����:"); break;
				case 2:printf("\n������:"); break;
				default:printf("\n����:");
				}
			}
			switch (poke[i][j])
			{
			case 'r':printf("����"); break;
			case'p':printf("Ƭ��"); break;
			case'b':printf("����"); break;
			case'm':printf("÷��"); break;
			case 'a':printf("A"); break;
			case 'c':printf("2"); break;
			case 'd':printf("3"); break;
			case 'D':										//4
			case 'E':										//5
			case 'F':										//6
			case 'G':										//7
			case 'H':										//8
			case 'I':printf("%c", (poke[i][j]) - 16); break;		//9
			case 'J':printf("10"); break;
			case 'S':printf("K"); break;
			default:printf("%c", (poke[i][j]) - 1);         //J  Q
			}
		}
		printf(" ");

	}
}
void wash(char poke[52][2])
{
	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int k = (rand() % (52 - i)) + i;
			if (k > i)
			{
				swap(&poke[i][j], &poke[k][j]);
			}

		}
	}
}
void sort(char poke[][2])									//ð������
{
	bool key;
	do
	{
		key = 0;
		for (int i = 0; i < 15; i++)
		{
			if (poke[i][1] > poke[i + 1][1])
			{
				key = 1;
				for (int j = 0; j < 2; j++)
					swap(&poke[i][j], &poke[i + 1][j]);
			}
		}
	} while (key);
}
int main()
{
	char r;
	char poke[52][2] = { 'r','a','r','c','r','d','r','D','r','E','r','F','r','G','r','H','r','I','r','J','r','K','r','R','r','S',
						 'p','a','p','c','p','d','p','D','p','E','p','F','p','G','p','H','p','I','p','J','p','K','p','R','p','S',
						 'b','a','b','c','b','d','b','D','b','E','b','F','b','G','b','H','b','I','b','J','b','K','b','R','b','S',
						 'm','a','m','c','m','d','m','D','m','E','m','F','m','G','m','H','m','I','m','J','m','K','m','R','m','S' };
	wash(poke);
	sort(poke);
	sort(&poke[16]);
	sort(&poke[32]);
	show(poke);
	while (1)
	{
		printf("\n����'r'���·���");
		scanf_s("%c", &r);
		getchar();
		if (r == 'r')
		{
			system("cls");
			wash(poke);
			show(poke);
		}
		else
			break;
	}
}