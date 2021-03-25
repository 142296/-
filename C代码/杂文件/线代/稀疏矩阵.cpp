#include<iostream>
#include<map>
using namespace std;
int Size;
struct mem{
	int x, y, data;
	mem* next;
};
mem matrix[2];
void swap(int* x, int* y);
void mean();
void creat();
void transpose();
void add(int x);
void mul();
void show(mem *move);
void swap(int* x, int* y)
{
	int t = *x; *x = *y; *y = t;
}
void mean()
{
	cout << "-------请选择要执行的操作--------\n\n";
	cout << "		0---创建矩阵"<<endl;
	cout << "		1---A+B"<<endl;
	cout << "		2---A-B"<<endl;
	cout << "		3---A*B"<<endl;
	cout << "		4---转置"<<endl;
	cout << "		5---退出" << endl;
	cout << "------------------------------------"<<endl;
}
void creat()
{
	int x;
	cout << "请输入两个矩阵的规格(n*n)输入n:";
	cin >> Size;
	getchar();
	for(int i=0;i<2;i++)
	{
		mem* head,*temp;
		head = new mem();
		matrix[i].next = head;
		cout << "请输入第" << i << "个矩阵"<<endl;
		for (int j = 0; j < Size; j++)
		{
			for (int k = 0; k < Size; k++)
			{
				cin >> x;
				getchar();
				if (x)
				{
					mem* new_mem = new mem();
					new_mem->x = j;
					new_mem->y = k;
					new_mem->data = x;
					temp = head->next;
					head->next = new_mem;
					new_mem->next = temp;
				}
			}
		}
	}
}
void transpose()
{
	int se;
	cout << "请选择要转置的矩阵" << endl;
	cout << "0---A"<<endl;
	cout << "1---B" << endl;
	cin >> se;
	getchar();
	mem* move = matrix[se].next->next;
	while (move)
	{
		if (move->x != move->y)
			swap(&move->x, &move->y);
		move = move->next;
	}
	printf("结果为:\n");
	show(matrix[se].next->next);
}
void add(int x)
{
	mem* result = new mem();
	mem* temp;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			int a = 0, b = 0;
			mem* move1 = matrix[0].next->next;
			mem* move2 = matrix[1].next->next;
			while (move1)
			{
				if (move1->x == i && move1->y == j)
				{
					a = move1->data;
					break;
				}
				move1 = move1->next;
			}
			while (move2)
			{
				if (move2->x == i && move2->y == j)
				{
					b = move2->data;
					break;
				}
				move2 = move2->next;
			}
			if (a + x * b)
			{
				mem* new_mem = new mem();
				new_mem->x = i;
				new_mem->y = j;
				new_mem->data = a+x*b;

				temp = result->next;
				result->next = new_mem;
				new_mem->next = temp;
			}
		}
	}

	printf("结果为:\n");
	show(result->next);
}
void show(mem* move)
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			int key = 1;
			mem* move1 = move;
			while (move1)
			{
				if (move1->x == i && move1->y == j)
				{
					printf("%d ", move1->data);
					key = 0;
					break;
				}
				move1 = move1->next;
			}
			if (key)
				printf("0 ");
		}
		printf("\n");
	}
	getchar();
}
void mul()
{
	mem* result = new mem();
	mem* temp;
	for (int i = 0; i < Size; i++)
	{
		int sum1 = 0;
		mem* move = matrix[0].next->next;
		map<int, int>m1;
		while (move)
		{
			if (move->x == i)
				m1[move->y] = move->data;
			move = move->next;
		}
		for (int j = 0; j < Size; j++)
		{

			mem* move = matrix[1].next->next;
			while (move)
			{
				if (move->y == j)
					sum1 += move->data * m1[move->x];
				move = move->next;
			}
			if (sum1)
			{
				mem* new_mem = new mem();
				new_mem->x = i;
				new_mem->y = j;
				new_mem->data = sum1;

				temp = result->next;
				result->next = new_mem;
				new_mem->next = temp;
			}
		}
	}
	printf("结果为:\n");
	show(result->next);
}
int main()
{
	int se;
	while (1)
	{
		system("cls");
		mean();
		cin >> se;
		getchar();
		switch (se)
		{
		case 0:creat(); break;
		case 1:add(1);	break;
		case 2:add(-1); break;
		case 3:mul(); break;
		case 4:transpose(); break;
		case 5:return 0;
		}
	}
} 