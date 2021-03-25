#include<stdio.h>
#include<stdlib.h>
#define one 11
void swap(int* p, int* q)    //交换
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}
void right(int num[9])          //输出九宫格
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			printf("\n");
		printf("%d ", num[i]);

	}
}
int sum(int a, int b, int c)                //判断重复以及和
{
	if (a + b + c == ((one + 4) * 3) && a != b && a != c && b != c)
		return 1;
	else
		return 0;
}
int main()
{
	int num[9] = { 0 };
	num[4] = one + 4;
	int i, j, k, l;
	bool key = 1;
	for (num[0] = one; num[0] < one + 9; num[0]++)
	{
		for (num[1] = one; num[1] < one + 9; num[1]++)
		{
			for (num[2] = one; num[2] < one + 9; num[2]++)
			{
				for (num[3] = one; num[3] < one + 9; num[3]++)
				{
					for (num[5] = one; num[5] < one + 9; num[5]++)
					{
						for (num[6] = one; num[6] < one + 9; num[6]++)
						{
							for (num[7] = one; num[7] < one + 9; num[7]++)
							{
								for (num[8] = one; num[8] < one + 9; num[8]++)
								{
									if (sum(num[1], num[2], num[0]))
										if (sum(num[3], num[4], num[5]))
											if (sum(num[6], num[7], num[8]))
												if (sum(num[0], num[3], num[6]))
													if (sum(num[1], num[4], num[7]))
														if (sum(num[2], num[5], num[8]))
															if (sum(num[0], num[4], num[8]))
																if (sum(num[2], num[4], num[6]))
																{
																	printf("right:");
																	right(num);
																}
								}
							}
						}
					}
				}

			}
		}
	}
}
