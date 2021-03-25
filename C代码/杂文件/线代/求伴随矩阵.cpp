#include<stdio.h>
#include<math.h>
int main()
{
	int a[3][3], b[2][2], key = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf_s("%d", &a[i][j]);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int x = 0, y = 0;
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (k != i && l != j)
					{
						b[x][y++] = a[k][l];
					}
				}
				if (y == 2) { x++; y = 0; }
			}
			printf("A%d%d=%d  ", i, j, key * (b[0][0] * b[1][1] - b[0][1] * b[1][0]));
			key = -key;
		}
		printf("\n");
	}
}