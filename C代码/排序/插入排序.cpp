#include<stdio.h>			//��������  ��С����
#include<stdlib.h>			//������ʦ�����
#include<time.h>
int main()
{
	srand(time(0));
	int a[10], t, j;
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 90 + 10;
	for (int i = 1; i < 10; i++)
	{
		t = a[i];                //��������
		for (j = i; j > 0; j--)
		{						
			if (t > a[j - 1])	//�ж���ǰһ�����Ĵ�С��ϵ
			{					//����ǰһ��
				break;
			}
			else               //С��ǰһ��
				a[j] = a[j - 1];		//����ǰ��
		}
		a[j] = t;				//��1����������ѭ��  С�ڵ�һ��
	}							//��2��break����ѭ�� ����ǰһ��
	for (j = 0; j < 10; j++)
		printf("%d ", a[j]);
}