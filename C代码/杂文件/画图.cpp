#include<stdio.h>
int main()
{

	int a = 0, x = 0, y = 0;
	char s;
	char c[10][10] = { 0 };
	c[x][y] = '#';
	do
	{
		s = getchar();
		if (s == 'L')
			x = x - 1;
		if (s == 'R')
			x = x + 1;
		if (s == 'U')
			y = y - 1;
		if (s == 'D')
			y = y + 1;
		c[x][y] = '*';
	} while (s != 'p');
	for (y = 0; y < 10; y++)
	{
		for (x = 0; x < 10;x++)
			printf("%c", c[x][y]);
		printf("\n");
	}
	return 0;
}