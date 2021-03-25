#include<stdio.h>
struct date
{
	char dat;
	date* next;
	date* bro;
};
int main()
{
	date array[11];
	for (int i = 0; i < 11; i++)
	{
		array[i].dat = 'A' + i;
		array[i].bro = NULL;
		array[i].next = NULL;
	}
	array[0].next = &array[1];
	array[1].bro = &array[2];
	array[2].bro = &array[3];
	array[1].next = &array[4];
	array[4].next = &array[7];
	array[7].bro = &array[8];
	array[8].bro = &array[9];
	array[3].next = &array[5];
	array[5].bro = &array[6];
	array[6].next = &array[10];
}